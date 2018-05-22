
    #version 450

    #define MAX_LIGHTS 10
    #define MAX_MATERIAL 32

    uniform int numLights;
    uniform struct Light {
       vec4 position;
       vec3 intensities;
       vec3 direction;
       float angle;
    } lights[MAX_LIGHTS];

    uniform struct Material {
        vec3 albedo;
        float metallic;
        float roughness;
    } materials[MAX_MATERIAL];

    in vec2 uv;

    uniform mat4 invModelview;
    uniform mat4 invProjection;
    uniform mat4 lightModelview;
    uniform mat4 rotation;

    uniform sampler2D texDepth;
    uniform sampler2D texDiffuseUV;
    uniform sampler2D texNormal;
    uniform samplerCube irradianceMap;
    uniform samplerCube prefilterMap;
    uniform sampler2D brdfLUT;
    uniform sampler2DArray texMaterial;

    uniform vec3 cameraV;

    const float PI = 3.14159265359;

    out vec4 out_Color;

    vec3 fresnelSchlickRoughness(float cosTheta, vec3 F0, float roughness) {
        return F0 + (max(vec3(1.0 - roughness), F0) - F0) * pow(1.0 - cosTheta, 5.0);
    }

    vec3 fresnelSchlick(float cosTheta, vec3 F0) {
        return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
    }

    float distributionGGX(vec3 N, vec3 H, float roughness) {
        float a = roughness * roughness;
        float a2 = a * a;
        float NdotH = max(dot(N, H), 0.0);
        float NdotH2 = NdotH * NdotH;

        float num = a2;
        float denom = (NdotH2 * (a2 - 1.0) + 1.0);
        denom = PI * denom * denom;

        return num / denom;
    }

    float geometrySchlickGGX(float NdotV, float roughness) {
        float r = roughness + 1.0;
        float k = (r * r) / 8.0;

        float num = NdotV;
        float denom = NdotV * (1.0 - k) + k;

        return num / denom;
    }

    float geometrySmith(vec3 N, vec3 V, vec3 L, float roughness) {
        float NdotV = max(dot(N, V), 0.0);
        float NdotL = max(dot(N, L), 0.0);
        float ggx2 = geometrySchlickGGX(NdotV, roughness);
        float ggx1 = geometrySchlickGGX(NdotL, roughness);

        return ggx1 * ggx2;
    }

    vec4 WorldPosFromDepth(vec2 tc) {
        float z = texture(texDepth, tc).x * 2.0 - 1.0;

        vec4 clipSpacePosition = vec4(tc * 2.0 - 1.0, z, 1.0);
        vec4 viewSpacePosition = invProjection * clipSpacePosition;

        return viewSpacePosition /= viewSpacePosition.w;
    }

    float computeBlur(vec2 uv) {
        vec2 texelSize = 1.0 / vec2(textureSize(texDiffuseUV, 0));
        float result = 0.0;
        for (int x = -2; x < 2; x = x + 1) {
            for (int y = -2; y < 2; y = y + 1) {
                vec2 offset = vec2(float(x), float(y)) * texelSize;
                result += texture(texDiffuseUV, uv + offset).a;
            }
        }

        return result / (4.0 * 4.0);
    }

    /*float computeShadow(vec3 vertex, vec3 lightDir, vec3 normal) {
        vec4 vertexLS = lightModelview * vec4(vertex, 1.0);
        vertexLS = inverse(invProjection) * vertexLS;
        vec3 projCoords = vertexLS.xyz / vertexLS.w;
        projCoords = projCoords * 0.5 + 0.5;

        float closestDepth = texture(texShadow, projCoords.xy).r;
        float currentDepth = projCoords.z;

        float bias = 0.00001;
        float shadow = 0.0;
        vec2 texelSize = 1.0 / textureSize(texShadow, 0);
        if (projCoords.z <= 1.0) {
            for(int x = -1; x < 1; x = x + 1) {
                for(int y = -1; y < 1; y = y + 1) {
                    vec2 offset = vec2(float(x), float(y)) * texelSize;
                    float pcfDepth = texture(texShadow, projCoords.xy + offset).r;
                    shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
                }
            }
            shadow = shadow / (2.0 * 2.0);
        }

        return 1.0 - shadow;
    }*/

    void main() {
        vec3 vertex = (invModelview * WorldPosFromDepth(uv)).xyz;
        vec3 normal = texture(texNormal, uv).xyz;
        if (normal != vec3(0.0, 0.0, 0.0)) {
            int id = int(texture(texNormal, uv).w);
            vec3 N = normalize(normal);
            vec3 V = normalize(cameraV - vertex);
            vec3 R = reflect(V, N);
            R = (rotation * vec4(R, 1.0)).xyz;
            vec2 textureUV = texture(texDiffuseUV, uv).xy;
            vec2 tileUV = mix(textureUV, fract(vec2(dot(normal.zxy, vertex), dot(normal.yzx, vertex))), textureUV == vec2(-1.0, -1.0));
            vec3 albedo = texture(texMaterial, vec3(tileUV, id)).rgb;

            vec3 F0 = vec3(0.04);
            F0 = mix(F0, albedo, materials[id].metallic);

            vec3 Lo = vec3(0.0);
            for (int i = 0; i < numLights; i = i + 1) {
                vec3 L = mix(normalize(lights[i].position.xyz), normalize(lights[i].position.xyz - vertex), lights[i].position.w);
                vec3 H = normalize(V + L);

                float distance = length(lights[i].position.xyz - vertex);
                float attenuation = mix(1.0, 1.0 / (distance * distance), lights[i].position.w);
                vec3 radiance = lights[i].intensities * attenuation;

                float NDF = distributionGGX(N, H, materials[id].roughness);
                float G = geometrySmith(N, V, L, materials[id].roughness);
                vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

                vec3 kS = F;
                vec3 kD = vec3(1.0) - kS;
                kD *= 1.0 - materials[id].metallic;

                vec3 numerator = NDF * G * F;
                float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0);
                vec3 specular = numerator / max(denominator, 0.001);


                float NdotL = max(dot(N, L), 0.0);
                Lo += (kD * albedo / PI + specular) * radiance * NdotL;
            }

            vec3 F = fresnelSchlickRoughness(max(dot(N, V), 0.0), F0, materials[id].roughness);

            vec3 kS = F;
            vec3 kD = 1.0 - kS;
            kD *= 1.0 - materials[id].metallic;

            vec3 irradiance = texture(irradianceMap, N).rgb;
            vec3 diffuse = irradiance * albedo;

            const float MAX_REFLECTION_LOD = 4.0;
            vec3 prefilteredColor = textureLod(prefilterMap, R, materials[id].roughness * MAX_REFLECTION_LOD).rgb;
            vec2 brdf = texture(brdfLUT, vec2(max(dot(N, V), 0.0), materials[id].roughness)).rg;
            vec3 specular = prefilteredColor * (F * brdf.x + brdf.y);

            vec3 ambient = (kD * computeBlur(uv) * diffuse + specular);

            vec3 color = (ambient + Lo);

            color = color / (color + vec3(1.0));
            color = pow(color, vec3(1.0/2.2));

            out_Color = vec4(color, 1.0);
        } else {
            out_Color = vec4(texture(texDiffuseUV, uv).rgb, 1.0);
        }

    }

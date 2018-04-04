
    #version 450

    #define MAX_LIGHTS 10
    #define MAX_LIGHTS 32

    uniform int numLights;
    uniform struct Light {
       vec4 position;
       vec3 intensities;
       vec3 coneDirection;
       float attenuation;
       float ambientCoefficient;
       float coneAngle;
    } lights[MAX_LIGHTS];

    uniform int numMaterial;
    uniform struct Material {
        vec3 albedo;
        float metallic;
        float roughness;
    } materials[MAX_MATERIAL];

    in vec2 uv;

    uniform mat4 invModelview;
    uniform mat4 invProjection;

    uniform sampler2D texDepth;
    uniform sampler2D texDiffuse;
    uniform sampler2D texNormal;

    uniform vec3 cameraV;

    const float PI = 3.14159265359;

    uniform vec3  albedo;
    uniform float metallic;
    uniform float roughness;
    uniform float ao;

    out vec4 out_Color;

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

    void main() {
        vec3 vertex = (invModelview * WorldPosFromDepth(uv)).xyz;
        vec3 normal = texture(texNormal, uv).xyz;
        vec3 N = normalize(normal);
        vec3 V = normalize(cameraV - vertex);

        vec3 F0 = vec3(0.04);
        F0 = mix(F0, albedo, metallic);

        vec3 Lo = vec3(0.0);
        for (int i = 0; i < 4; i = i + 1) {

            vec3 L = normalize(lights[i].position.xyz - vertex);
            vec3 H = normalize(V + L);

            float distance = lenght(lights[i].position.xyz - vertex);
            float attenuation = 1.0 / (distance * distance);
            vec3 radiance = lights[i].intensities * attenuation;

            float NDF = distributionGGX(N, H, roughness);
            float G = geometrySmith(N, V, L, roughness);
            vec3 F = fresnelSchlick(max(dot(H, V), 0.0), F0);

            vec3 kS = F;
            vec3 kD = vec3(1.0) - kS;
            kD *= 1.0 - metallic;

            vec3 numerator = NDF * G * F;
            float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0);
            vec3 specular = numerator / max(denominator, 0.001);


            float NdotL = max(dot(N, L), 0.0);
            Lo += (kD * albedo / PI + specular) * radiance * NdotL;
        }

        vec3 ambient = vec3(0.03) * albedo * ao;
        vec3 color = ambient + Lo;

        color = color / (color + vec3(1.0));
        color = pow(color, vec3(1.0/2.2));

        out_Color = vec4(color, 1.0);
    }

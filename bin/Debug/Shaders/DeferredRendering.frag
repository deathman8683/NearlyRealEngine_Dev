
    #version 450

    #define MAX_LIGHTS 10

    uniform int numLights;
    uniform struct Light {
       vec4 position;
       vec3 intensities;
       vec3 coneDirection;
       float attenuation;
       float ambientCoefficient;
       float coneAngle;
    } lights[MAX_LIGHTS];

    in vec2 uv;

    uniform vec3 cameraV;
    uniform mat4 invModelview;
    uniform mat4 invProjection;

    uniform sampler2D texDiffuse;
    uniform sampler2D texDepth;
    uniform sampler2D texNormal;
    uniform sampler2D texSSAO;
    uniform samplerCube texSkyBox;
    uniform float type;

    out vec4 out_Color;

    float computeBlur(vec2 uv) {
        vec2 texelSize = 1.0 / vec2(textureSize(texSSAO, 0));
        float result = 0.0;
        for (int x = -2; x < 2; x = x + 1) {
            for (int y = -2; y < 2; y = y + 1) {
                vec2 offset = vec2(float(x), float(y)) * texelSize;
                result += texture(texSSAO, uv + offset).r;
            }
        }

        return result / (4.0 * 4.0);
    }

    vec3 WorldPosFromDepth(float depth) {
        float z = depth * 2.0 - 1.0;

        vec4 clipSpacePosition = vec4(uv * 2.0 - 1.0, z, 1.0);
        vec4 viewSpacePosition = invProjection * clipSpacePosition;

        viewSpacePosition /= viewSpacePosition.w;

        return viewSpacePosition.xyz;
    }

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec4 surfaceNormal, vec3 surfaceCamera, float num) {
        vec3 lightVertex;
        float attenuation = 1.0;
        float specularCoefficient;
        if (surfaceNormal.w == 0.0) {
            if (num == 0) {
                return (texture(texSkyBox, -refract(surfaceCamera, surfaceNormal.xyz, 1.0 / 1.333))).rgb;
            } else {
                if (light.position.w == 0.0) {
                    lightVertex = normalize(light.position.xyz);
                    attenuation = 1.0;
                } else {
                    lightVertex = normalize(light.position.xyz - surfacePos);
                    float distanceToLight = length(light.position.xyz - surfacePos);
                    attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

                    float lightVertexAngle = degrees(acos(dot(-lightVertex, normalize(light.coneDirection))));
                    if (lightVertexAngle > light.coneAngle) {
                        attenuation = 0.0;
                    }
                }

                 specularCoefficient = pow(max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal.xyz))), 100);
            }
        } else {
            if (light.position.w == 0.0) {
                lightVertex = normalize(light.position.xyz);
                attenuation = 1.0;
            } else {
                lightVertex = normalize(light.position.xyz - surfacePos);
                float distanceToLight = length(light.position.xyz - surfacePos);
                attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

                float lightVertexAngle = degrees(acos(dot(-lightVertex, normalize(light.coneDirection))));
                if (lightVertexAngle > light.coneAngle) {
                    attenuation = 0.0;
                }
            }

             specularCoefficient = max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal.xyz)));
        }

        vec3 ambient = light.ambientCoefficient * surfaceColor * light.intensities * computeBlur(uv);

        float diffuseCoefficient = max(0.0, dot(surfaceNormal.xyz, lightVertex));
        vec3 diffuse = diffuseCoefficient * surfaceColor * light.intensities;

        vec3 specular = specularCoefficient * surfaceColor * light.intensities;

        return ambient + attenuation * (diffuse + specular);
    }

    void main() {
        vec3 linearColor = vec3(0);
        vec3 color = texture(texDiffuse, uv).rgb;
        vec4 normal = texture(texNormal, uv);
        vec3 vertex = (invModelview * vec4(WorldPosFromDepth(texture(texDepth, uv).x), 1.0)).xyz;

        if (normal == vec4(1.0, 1.0, 1.0, 1.0)) {
            out_Color = vec4(color, 1.0);
        } else {
            if (type == 1.0) {
                for (int i = 0; i < numLights; i = i + 1) {
                    linearColor += applyLight(lights[i], vertex, color, normal, normalize(cameraV - vertex), i);
                }
                out_Color = texture(texSSAO, uv);
                //float c = computeBlur(uv);
                //out_Color = vec4(c, c, c, 1.0);
                //out_Color = texture(texSSAO, uv);
            } else {
                for (int i = 0; i < numLights; i = i + 1) {
                    linearColor += applyLight(lights[i], vertex, color, normal, normalize(cameraV - vertex), i);
                }
                out_Color = vec4(linearColor, 1.0);
                //out_Color = texture(texDiffuse, uv);
                //float c = computeBlur(uv);
                //out_Color = vec4(c, c, c, 1.0);
            }
        }
    }


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

    in vec3 cameraVertex;
    in vec2 uv;

    uniform mat4 projection;
    uniform mat4 cameraModelView;
    uniform mat4 lightModelView;

    uniform sampler2D texDiffuse;
    uniform sampler2D texPosition;
    uniform sampler2D texNormal;
    uniform sampler2D texShadow;
    uniform samplerCube skyBox;

    out vec4 out_Color;

    float linearizeDepth(in vec2 uv) {
        float zNear = 0.1;
        float zFar  = 1000.0;
        float depth = texture(texShadow, uv).x;
        return (2.0 * zNear) / (zFar + zNear - depth * (zFar - zNear));
    }

    float readShadowMap(vec3 pos, Light light) {
        vec3 position = (inverse(cameraModelView) * lightModelView * vec4(pos, 1.0)).xyz;
        float d = length(light.position.xyz - position);
        float depth = texture(texShadow, position.xy * vec2(0.5, 0.5) + vec2(0.5, 0.5)).x;
        return float(d > depth);
    }

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec4 surfaceNormal, vec3 surfaceCamera, float num) {
        vec3 lightVertex;
        float attenuation = 1.0;
        float specularCoefficient;
        if (surfaceNormal.w == 0.0) {
            if (num == 0) {
                return surfaceColor;
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

        float shadow = readShadowMap(surfacePos, light);

        vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensities;

        float diffuseCoefficient = max(0.0, dot(surfaceNormal.xyz, lightVertex)) * shadow;
        vec3 diffuse = diffuseCoefficient * surfaceColor.rgb * light.intensities;

        vec3 specular = specularCoefficient * surfaceColor * light.intensities * shadow;

        return ambient + attenuation*(diffuse + specular);
    }

    void main() {
        vec3 linearColor = vec3(0);
        vec3 color = texture(texDiffuse, uv).rgb;
        vec4 normal = texture(texNormal, uv);
        vec3 vertex = texture(texPosition, uv).xyz;

        if (normal == vec4(1.0, 1.0, 1.0, 1.0)) {
            out_Color = vec4(color, 1.0);
        } else {
            for (int i = 0; i < numLights; i = i + 1) {
                linearColor += applyLight(lights[i], vertex, color, normal, normalize(cameraVertex - vertex), i);
            }
            if (normal.w == 0.0) {
                out_Color = vec4(linearColor, 1.0);
            } else {
                vec3 gamma = vec3(1.0/2.2);
                out_Color = vec4(pow(linearColor, gamma), 1.0);
            }
        }
    }


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
    in vec2 pos;

    uniform vec3 cameraV;

    uniform sampler2D texDiffuse;
    uniform sampler2D texPosition;
    uniform sampler2D texNormal;
    uniform sampler2D texDepth;
    uniform samplerCube skyBox;

    uniform mat4 projection;

    uniform float gSampleRad;
    const int MAX_KERNEL_SIZE = 32;
    uniform vec3 gKernel[MAX_KERNEL_SIZE];

    out vec4 out_Color;

    float linearizeDepth(in vec2 uv) {
        float zNear = 0.1;
        float zFar  = 1000.0;
        float depth = texture(texDepth, uv).x;
        return (2.0 * zNear) / (zFar + zNear - depth * (zFar - zNear));
    }

    float SSAO(in vec2 pos) {
        vec3 vertex = texture(texPosition, pos).xyz;

        float AO = 0.0;

        for (int i = 0; i < MAX_KERNEL_SIZE; i = i + 1) {
            vec3 samplePos = vertex + gKernel[i];
            vec4 offset = vec4(samplePos, 1.0);
            offset = projection * offset;
            offset.xy /= offset.w;
            offset.xy = offset.xy * 0.5 + vec2(0.5);

            float sampleDepth = texture(texPosition, offset.xy).b;

            if (abs(vertex.z - sampleDepth) < gSampleRad) {
                AO += step(sampleDepth, samplePos.z);
            }
        }

        AO = 1.0 - AO / 128.0;
        AO = pow(AO, 2.0);
        
        return AO;
    }

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec4 surfaceNormal, vec3 surfaceCamera, float num) {
        vec3 lightVertex;
        float attenuation = 1.0;
        float specularCoefficient;
        if (surfaceNormal.w == 0.0) {
            if (num == 0) {
                return (texture(skyBox, -refract(surfaceCamera, surfaceNormal.xyz, 1.0 / 1.333))).rgb;
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

        vec3 ambient = light.ambientCoefficient * surfaceColor * light.intensities;

        float diffuseCoefficient = max(0.0, dot(surfaceNormal.xyz, lightVertex));
        vec3 diffuse = diffuseCoefficient * surfaceColor * light.intensities;

        vec3 specular = specularCoefficient * surfaceColor * light.intensities;

        return ambient + attenuation * (diffuse + specular);
    }

    void main() {
        vec3 linearColor = vec3(0);
        vec3 color = texture(texDiffuse, uv).rgb;
        vec4 normal = texture(texNormal, uv);
        vec3 vertex = texture(texPosition, uv).xyz;

        if (normal == vec4(1.0, 1.0, 1.0, 1.0)) {
            out_Color = vec4(color, 1.0);
        } else {
            float c = SSAO(pos);
            out_Color = vec4(c, c, c, 1.0);
            /*for (int i = 0; i < numLights; i = i + 1) {
                linearColor += applyLight(lights[i], vertex, color, normal, normalize(cameraV - vertex), i);
            }
            out_Color = vec4(linearColor, 1.0) * c;*/
        }
    }

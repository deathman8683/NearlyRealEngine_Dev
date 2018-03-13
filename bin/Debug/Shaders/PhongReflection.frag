
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

    in vec3 vertex;
    in vec3 color;
    in vec3 normal;
    in vec3 cameraVertex;
    in vec3 incident;
    in vec3 cameraNormal;

    uniform samplerCube skyBox;

    out vec4 out_Color;

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec3 surfaceNormal, vec3 surfaceCamera, float num) {
        vec3 lightVertex;
        float attenuation = 1.0;
        float specularCoefficient;
        if (surfaceColor == vec3(1.0, 1.0, 1.0)) {
            if (num == 0) {
                return vec3(texture(skyBox, -refract(surfaceCamera, surfaceNormal, 1.0 / 1.333)).xyz);
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

                specularCoefficient = pow(max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal))), 100);
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

             specularCoefficient = max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal)));
        }
        vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensities;

        float diffuseCoefficient = max(0.0, dot(surfaceNormal, lightVertex));
        vec3 diffuse = diffuseCoefficient * surfaceColor.rgb * light.intensities;

        vec3 specular = specularCoefficient * surfaceColor * light.intensities;

        return ambient + attenuation*(diffuse + specular);
    }

    void main() {
        vec3 linearColor = vec3(0);

        for (int i = 0; i < numLights; i = i + 1) {
            linearColor += applyLight(lights[i], vertex, color, normal, normalize(cameraVertex - vertex), i);
        }

        if (color == vec3(1.0, 1.0, 1.0)) {
            out_Color =  vec4(linearColor, 1.0);
        } else {
            vec3 gamma = vec3(1.0/2.2);
            out_Color = vec4(pow(linearColor, gamma), 1.0);
        }

    }

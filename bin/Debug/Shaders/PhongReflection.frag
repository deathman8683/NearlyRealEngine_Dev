
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

    out vec4 out_Color;

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec3 surfaceNormal, vec3 surfaceCamera) {
        vec3 lightVertex;
        float attenuation = 1.0;
        if (light.position.w == 0.0) {
            lightVertex = normalize(light.position.xyz);
            attenuation = 1.0;
        } else {
            //attenuation
            lightVertex = normalize(light.position.xyz - surfacePos);
            float distanceToLight = length(light.position.xyz - surfacePos);
            attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

            float lightVertexAngle = degrees(acos(dot(-lightVertex, normalize(light.coneDirection))));
            if (lightVertexAngle > light.coneAngle) {
                attenuation = 0.0;
            }
        }
        //ambient
        vec3 ambient = light.ambientCoefficient * surfaceColor.rgb * light.intensities;

        //diffuse
        float diffuseCoefficient = max(0.0, dot(surfaceNormal, lightVertex));
        vec3 diffuse = diffuseCoefficient * surfaceColor.rgb * light.intensities;

        //specular
        float specularCoefficient = 0.0;
        if (color == vec3(5.0/255.0, 75.0/255.0, 1.0)) {
            specularCoefficient = pow(max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal))), 100);
        } else {
            specularCoefficient = max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal)));
        }
        vec3 specular = specularCoefficient * surfaceColor * vec3(0.5, 0.5, 0.5) *  light.intensities;


        //linear color (color before gamma correction)
        return ambient + attenuation*(diffuse + specular);
    }

    void main() {
        vec3 linearColor = vec3(0);

        for (int i = 0; i < numLights; i = i + 1) {
            linearColor += applyLight(lights[i], vertex, color, normal, cameraVertex);
        }

        //final color (after gamma correction)
        vec3 gamma = vec3(1.0/2.2);
        out_Color = vec4(pow(linearColor, gamma), 1.0);
    }

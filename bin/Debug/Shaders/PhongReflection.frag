
    #version 450

    #define MAX_LIGHTS 10

    uniform int numLights;
    uniform struct Light {
       vec3 position;
       vec3 intensities;
       float attenuation;
       float ambientCoefficient;
    } lights[MAX_LIGHTS];

    in vec3 vertex;
    in vec3 color;
    in vec3 normal;
    in vec3 cameraVertex;

    out vec4 out_Color;

    vec3 applyLight(Light light, vec3 surfacePos, vec3 surfaceColor, vec3 surfaceNormal, vec3 surfaceCamera) {
        vec3 lightVertex = normalize(light.position - surfacePos);
        //ambient
        vec3 ambient = light.ambientCoefficient * surfaceColor * light.intensities;

        //diffuse
        float diffuseCoefficient = max(0.0, dot(surfaceNormal, lightVertex));
        vec3 diffuse = diffuseCoefficient * surfaceColor * light.intensities;

        //specular
        float specularCoefficient = 0.0;
        if (color == vec3(50.0/255.0, 50.0/255.0, 1.0)) {
            specularCoefficient = pow(max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal))), 100);
        } else {
            specularCoefficient = max(0.0, dot(surfaceCamera, reflect(-lightVertex, surfaceNormal)));
        }
        vec3 specular = specularCoefficient * surfaceColor * light.intensities;

        //attenuation
        float distanceToLight = length(light.position - surfacePos);
        float attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

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


    #version 450

    uniform vec3 camera;

    uniform struct Light {
       vec3 position;
       vec3 intensities;
       float attenuation;
       float ambientCoefficient;
    } light;

    in vec3 vertex;
    in vec3 color;
    in vec3 normal;

    out vec4 out_Color;

    void main() {
        vec3 surfaceToLight = normalize(light.position - vertex);
        vec3 surfaceToCamera = normalize(camera - vertex);

        //ambient
        vec3 ambient = light.ambientCoefficient * color * light.intensities;

        //diffuse
        float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight));
        vec3 diffuse = diffuseCoefficient * color * light.intensities;

        //specular
        float specularCoefficient = 0.0;
        if(diffuseCoefficient > 0.0) {
            if (color == vec3(50.0/255.0, 50.0/255.0, 1.0)) {
                specularCoefficient = pow(max(0.0, dot(surfaceToCamera, reflect(-surfaceToLight, normal))), 10);
            } else {
                specularCoefficient = max(0.0, dot(surfaceToCamera, reflect(-surfaceToLight, normal)));
            }
        }
        vec3 specular = specularCoefficient * color;

        //attenuation
        float distanceToLight = length(light.position - vertex);
        float attenuation = 1.0 / (1.0 + light.attenuation * pow(distanceToLight, 2));

        //linear color (color before gamma correction)
        vec3 linearColor = ambient + attenuation*(diffuse + specular);

        //final color (after gamma correction)
        vec3 gamma = vec3(1.0/2.2);
        out_Color = vec4(pow(linearColor, gamma), 1.0);
    }

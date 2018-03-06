
    #version 450

    uniform struct Light {
       vec3 position;
       vec3 intensities;
    } light;

    in vec3 fragVert;
    in vec3 fragColor;
    in vec3 fragNormal;

    out vec4 finalColor;

    void main() {
        mat3 normalMatrix = transpose(inverse(mat3(model)));
        vec3 normal = normalize(normalMatrix * fragNormal);

        vec3 fragPosition = vec3(vec4(fragVert, 1));

        vec3 surfaceToLight = light.position - fragVert;

        float brightness = dot(normal, surfaceToLight) / (length(surfaceToLight) * length(normal));
        brightness = clamp(brightness, 0, 1);

        vec4 surfaceColor = vec4(fragColor, 1.0);
        finalColor = vec4(brightness * light.intensities * surfaceColor.rgb, surfaceColor.a);
    }

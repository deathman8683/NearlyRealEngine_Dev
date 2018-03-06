
    #version 450

    uniform struct Light {
       vec3 position;
       vec3 intensities;
    } light;

    in vec3 vertex;
    in vec3 color;
    in vec3 normal;

    out vec4 out_Color;

    void main() {
        vec3 surfaceToLight = light.position - vertex;

        float brightness = dot(normal, surfaceToLight) / (length(surfaceToLight) * length(normal));
        brightness = clamp(brightness, 0, 1);

        vec4 tmpColor = vec4(color, 1.0);
        out_Color = vec4(brightness * light.intensities * tmpColor.rgb, tmpColor.a);

    }

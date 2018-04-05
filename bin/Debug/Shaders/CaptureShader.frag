
    #version 450

    in vec3 vertex;

    uniform samplerCube skyBox;

    out vec4 out_Color;

    void main() {
        vec3 envColor = texture(skyBox, vertex).rgb;

        envColor = envColor / (envColor + vec3(1.0));
        envColor = pow(envColor, vec3(1.0 / 2.2));

        out_Color = vec4(envColor, 1.0);
    }

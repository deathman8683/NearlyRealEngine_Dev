
    #version 450

    in vec3 vertex;

    uniform samplerCube skyBox;

    out vec4 [2] fragData;

    void main() {
        vec3 envColor = texture(skyBox, vertex).rgb;

        envColor = envColor / (envColor + vec3(1.0));
        envColor = pow(envColor, vec3(1.0 / 2.2));

        fragData[0] = vec4(envColor, 1.0);
        fragData[1] = vec4(0.0, 0.0, 0.0, 1.0);
    }


    #version 450

    in vec2 uv;

    uniform sampler2D texSSAO;

    out vec4 fragData;

    float offset[4] = float[](-1.5, -0.5, 0.5, 1.5);

    void main() {
        vec3 color = vec3(0.0, 0.0, 0.0);

        for (int i = 0; i < 4; i = i + 1) {
            for (int j = 0; j < 4; j = j + 1) {
                vec2 tc = uv;
                tc.x = uv.x + offset[j] / textureSize(texSSAO, 0).x;
                tc.y = uv.y + offset[i] / textureSize(texSSAO, 0).y;
                color += texture(texSSAO, tc).xyz;
            }
        }

        color /= 16.0;

        fragData = vec4(color, 1.0);
    }

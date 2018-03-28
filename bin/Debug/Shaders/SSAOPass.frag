
    #version 450

    in vec2 uv;

    uniform mat4 MVP;
    uniform sampler2D texPosition;

    uniform float gSampleRad;
    const int MAX_KERNEL_SIZE = 32;
    uniform vec3 gKernel[MAX_KERNEL_SIZE];

    out vec4 fragData;

    void main() {
        vec3 vertex = texture(texPosition, uv).xyz;

        float AO = 0.0;

        for (int i = 0; i < MAX_KERNEL_SIZE; i = i + 1) {
            vec3 samplePos = vertex + gKernel[i];
            vec4 offset = vec4(samplePos, 1.0);
            offset = MVP * offset;
            offset.xy /= offset.w;
            offset.xy = offset.xy * 0.5 + vec2(0.5);

            float sampleDepth = texture(texPosition, offset.xy).z;

            if (abs(vertex.z - sampleDepth) < gSampleRad) {
                AO += step(sampleDepth, samplePos.z);
            }
        }

        AO = 1.0 - AO / 128.0;
        AO = pow(AO, 2.0);

        fragData = vec4(AO);
    }

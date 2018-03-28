
    #version 450

    in vec2 uv;

    uniform mat4 MVP;
    uniform sampler2D texPosition;

    uniform float gSampleRad;
    const int MAX_KERNEL_SIZE = 128;
    uniform vec3 gKernel[MAX_KERNEL_SIZE];

    out vec4 fragData;

    void main() {
        vec3 vertex = texture(texPosition, uv).xyz;

        float occlusion = 0.0;
        for (int i = 0; i < MAX_KERNEL_SIZE; i = i + 1) {
            vec3 sampleV = vertex + gKernel[i];

            vec4 offset = vec4(sampleV, 1.0);
            offset = MVP * offset;
            offset.xy /= offset.w;
            offset.xy = offset.xy * 0.5 + vec2(0.5);

            float sampleDepth = texture(texPosition, offset.xy).z;

            float rangeCheck = smoothstep(0.0, 1.0, gSampleRad / abs(vertex.z - sampleDepth));
            occlusion += (sampleDepth >= sampleV.z + 0.04 ? 1.0 : 0.0) * rangeCheck;
        }

        occlusion = 1.0 - (occlusion / MAX_KERNEL_SIZE);
        fragData = vec4(occlusion);
    }

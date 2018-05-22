
    #version 450

    in vec4 normal;
    in vec2 uv;

    out vec4 [3] fragData;

    void main() {
	    fragData[0] = vec4(1.0);
        fragData[1] = normal;
        fragData[2] = vec4(uv, 0.0, 0.0);
    }

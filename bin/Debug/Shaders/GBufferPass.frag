
    #version 450

    in vec3 color;
    in vec4 normal;

    out vec4 [2] fragData;

    void main() {
	    fragData[0] = vec4(color, 1.0);
        fragData[1] = normal;
    }

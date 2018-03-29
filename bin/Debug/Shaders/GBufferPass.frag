
    #version 450

    in vec3 color;
    in vec3 vertex;
    in vec4 normal;

    out vec4 [3] fragData;

    void main() {
	    fragData[0] = vec4(color, 1.0);
    	fragData[1] = vec4(vertex, 1.0);
        fragData[2] = normal;
    }

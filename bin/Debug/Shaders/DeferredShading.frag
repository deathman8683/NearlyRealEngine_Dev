
    #version 450

    in vec3 color;
    //in vec3 vertex;
    //in vec3 normal;

    //out vec4 [3] fragData;
    out vec4 out_Color;

    void main() {
    	//fragData[0] = vec4(color, 1.0);
    	//fragData[1] = vec4(vertex, 1.0);
    	//fragData[2] = vec4(normal, 1.0);
        out_Color = vec4(color, 1.0);
    }

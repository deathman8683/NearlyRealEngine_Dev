
    #version 450

    in vec3 in_Vertex;
    in vec2 in_UV;


    out vec2 uv;
    out vec3 cameraVertex;

    void main() {
    	gl_Position = vec4(in_Vertex, 1.0);

        uv = in_UV;
    }

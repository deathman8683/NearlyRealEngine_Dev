
    #version 450

    in vec3 in_Vertex;
    in vec2 in_UV;

    out vec2 uv;
    out vec2 pos;

    void main() {
    	gl_Position = vec4(in_Vertex, 1.0);

        pos = (in_Vertex.xy + vec2(1.0)) / 2.0;
        uv = in_UV;
    }

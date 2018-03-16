
    #version 450

    in vec3 in_Vertex;
    in vec2 in_UV;

    uniform mat4 projection;
    uniform mat4 modelview;

    out vec2 uv;

    void main() {
    	gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

        uv = in_UV;
    }

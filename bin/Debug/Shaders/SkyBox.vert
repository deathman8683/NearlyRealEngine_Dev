
    #version 450

    in vec3 in_Vertex;

    uniform mat4 MVP;

    out vec3 vertex;

    void main() {
        vec4 pos = MVP * vec4(in_Vertex, 1.0);
        gl_Position = pos.xyww;

        vertex = in_Vertex;
    }

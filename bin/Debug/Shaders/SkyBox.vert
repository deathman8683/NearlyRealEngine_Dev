
    #version 450

    in vec3 in_Vertex;

    uniform mat4 MVP;

    out vec3 vertex;

    void main() {
        gl_Position = MVP * vec4(in_Vertex, 1.0);

        vertex = in_Vertex;
    }

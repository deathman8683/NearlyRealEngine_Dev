
    #version 450

    in vec3 in_Vertex;

    uniform mat4 modelview;

    out vec3 vertex;

    void main() {
        vertex = in_Vertex;

        gl_Position = modelview * vec4(in_Vertex, 1.0);
    }

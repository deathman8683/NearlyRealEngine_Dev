
    #version 450

    in vec3 in_Vertex;

    uniform mat4 projection;
    uniform mat4 modelview;

    out vec3 vertex;

    void main() {
        gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

        vertex = in_Vertex;
    }

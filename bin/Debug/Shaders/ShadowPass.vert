
    #version 450

    in vec3 in_Vertex;

    uniform mat4 modelview;
    uniform mat4 projection;

    void main() {
        gl_Position = projection * modelview * vec4(in_Vertex, 1.0);
    }

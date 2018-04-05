
    #version 450

    in vec3 in_Vertex;

    uniform mat4 projection;
    uniform mat4 modelview;

    out vec3 vertex;

    void main() {
        vertex = in_Vertex;

        mat4 rotView = mat4(mat3(modelview));
        vec4 clipPos = projection * rotView * vec4(in_Vertex, 1.0);
        gl_Position = clipPos.xyzw;
    }

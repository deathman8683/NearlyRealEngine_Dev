
    #version 450

    in vec3 in_Vertex;
    in vec2 in_UV;

    out vec2 uv;

    void main() {
        uv = in_UV;

        gl_Position = vec4(in_Vertex, 1.0);
    }


    #version 450

    in vec3 in_Vertex;
    in vec3 in_Color;
    in vec3 in_Normal;

    uniform mat4 MVP;

    out vec3 color;
    out vec4 normal;
    out vec3 vertex;

    void main() {
        gl_Position = MVP * vec4(in_Vertex, 1.0);

        if (in_Color == vec3(68.0 / 255.0, 68.0 / 255.0, 122.0 / 255.0)) {
            normal = vec4(in_Normal, 0.0);
        } else {
            normal = vec4(in_Normal, 1.0);
        }

        color = in_Color;
        vertex = in_Vertex;
    }

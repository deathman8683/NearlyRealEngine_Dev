
    #version 450

    in vec3 in_Vertex;
    in vec3 in_Color;
    in vec3 in_Normal;

    uniform mat4 modelview;
    uniform mat4 projection;

    out vec3 color;
    out vec4 normal;

    void main() {
        vec4 vertexMV = modelview * vec4(in_Vertex, 1.0);
        gl_Position = projection * vertexMV;

        if (in_Color == vec3(68.0 / 255.0, 68.0 / 255.0, 122.0 / 255.0)) {
            normal = vec4(in_Normal, 0.0);
        } else {
            normal = vec4(in_Normal, 1.0);
        }

        color = in_Color;
    }

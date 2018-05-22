
    #version 450

    in vec3 in_Vertex;
    in vec3 in_Normal;
    in float in_Material;

    uniform mat4 modelview;
    uniform mat4 projection;

    out vec4 normal;

    void main() {
        vec4 vertexMV = modelview * vec4(in_Vertex, 1.0);
        gl_Position = projection * vertexMV;

        normal.xyz = in_Normal;
        normal.w = in_Material;
    }


    #version 450

    in vec3 in_Vertex;
    in vec3 in_Normal;
    in vec3 in_Tangent;
    in float in_Material;
    in vec2 in_UV;

    uniform mat4 modelview;
    uniform mat4 projection;

    out vec4 normal;
    out vec2 uv;

    void main() {
        vec4 vertexMV = modelview * vec4(in_Vertex, 1.0);
        gl_Position = projection * vertexMV;

        normal.xyz = in_Normal;
        normal.w = in_Material;
        uv = in_UV;
    }

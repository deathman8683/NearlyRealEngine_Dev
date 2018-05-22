
    #version 450

    in vec3 in_Vertex;
    in vec3 in_Normal;
    in vec3 in_Tangent;
    in float in_Material;
    in vec2 in_UV;

    uniform mat4 modelview;
    uniform mat4 projection;

    out float id;
    out vec2 uv;
    out mat3 TBN;
    out vec3 vertex;
    out vec3 normal;

    void main() {
        vec4 vertexMV = modelview * vec4(in_Vertex, 1.0);
        gl_Position = projection * vertexMV;

        id = in_Material;
        uv = in_UV;
        vec3 T = normalize(in_Tangent);
        vec3 N = normalize(in_Normal);
        vec3 B = cross(N, T);
        vertex = in_Vertex;
        normal = in_Normal;
        TBN = mat3(T, B, N);
    }

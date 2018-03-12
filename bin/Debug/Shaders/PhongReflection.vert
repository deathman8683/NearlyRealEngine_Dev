
    #version 450

    in vec3 in_Vertex;
    in vec3 in_Color;
    in vec3 in_Normal;

    uniform vec3 cameraV;

    uniform mat4 projection;
    uniform mat4 modelview;

    out vec3 vertex;
    out vec3 color;
    out vec3 normal;
    out vec3 cameraVertex;
    out vec3 lightVertex;

    void main() {
        gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

        vertex = in_Vertex;
        color = in_Color;
        normal = in_Normal;
        cameraVertex = normalize(cameraV - vertex);
    }

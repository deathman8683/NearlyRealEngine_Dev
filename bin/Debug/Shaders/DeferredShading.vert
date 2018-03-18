
    #version 450

    in vec3 in_Vertex;
    in vec3 in_Color;
    in vec3 in_Normal;

    uniform mat4 projection;
    uniform mat4 modelview;
    uniform vec3 cameraV;

    out vec3 cameraVertex;
    out vec3 color;
    out vec3 normal;
    out vec3 vertex;

    void main() {
        gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

        normal = in_Normal;
        color = in_Color;
        vertex = in_Vertex;
        cameraVertex = cameraV;
    }

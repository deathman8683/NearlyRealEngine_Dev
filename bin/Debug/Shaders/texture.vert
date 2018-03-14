
    #version 450 core

    in vec3 in_Vertex;
    in vec2 in_UV;

    uniform mat4 projection;
    uniform mat4 modelview;

    out vec2 UV;

    void main()
    {
        gl_Position = projection * modelview * vec4(in_Vertex, 1.0);

        UV = in_UV;
    }

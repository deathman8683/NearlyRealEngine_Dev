
    #version 450

    in vec2 UV;

    uniform sampler2D texture;

    out vec4 out_Color;

    void main()
    {
        out_Color = texture(texture, UV);
    }

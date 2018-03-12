
    #version 450

    in vec3 UV;

    uniform samplerCube cubemap;

    out vec4 out_Color;

    void main() {
        out_Color = textureCube(cubemap, UV);
    }

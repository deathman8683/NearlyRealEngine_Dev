
    #version 450

    in vec3 vertex;

    uniform samplerCube skyBox;

    out vec4 [2] fragData;

    void main() {
        fragData[0] = textureCube(skyBox, vertex);
    	fragData[1] = vec4(0.0, 0.0, 0.0, 1.0);
    }

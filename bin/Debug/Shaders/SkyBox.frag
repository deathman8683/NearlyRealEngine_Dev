
    #version 450

    in vec3 vertex;

    uniform samplerCube skyBox;

    out vec4 [3] fragData;

    void main() {
        fragData[0] = textureCube(skyBox, vertex);
    	fragData[1] = vec4(vertex, 1.0);
    	fragData[2] = vec4(1.0, 1.0, 1.0, 1.0);
    }

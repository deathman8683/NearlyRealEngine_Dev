
    #version 450

    in vec3 color;
    in vec3 vertex;
    in vec3 normal;
    in vec3 cameraVertex;

    uniform samplerCube skyBox;

    out vec4 [3] fragData;

    void main() {
        if (color == vec3(1.0, 1.0, 1.0)) {
            fragData[0] = texture(skyBox, -refract(normalize(cameraVertex - vertex), normal, 1.0 / 1.333));
        	fragData[2] = vec4(normal, -1.0);
        } else {
    	    fragData[0] = vec4(color, 1.0);
        	fragData[2] = vec4(normal, 1.0);
        }
    	fragData[1] = vec4(vertex, 1.0);
    }

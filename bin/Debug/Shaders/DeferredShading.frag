
    #version 450

    in vec3 color;
    in vec3 vertex;
    in vec3 normal;

    void main() {
    	gl_FragData[0] = vec4(color.rgb, 0);
    	gl_FragData[1] = vec4(vertex.xyz, 0);
    	gl_FragData[2] = vec4(normal.xyz, 0);
    }

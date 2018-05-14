
    #version 450

    in vec4 normal;
    in vec2 uv;

    uniform sampler2DArray texMaterial;

    out vec4 [2] fragData;

    void main() {
	    fragData[0] = vec4(uv, 1.0, 1.0);
        fragData[1] = vec4(normal.xyz * texture(texMaterial, vec3(uv, normal.w)).xyz, normal.w);
    }

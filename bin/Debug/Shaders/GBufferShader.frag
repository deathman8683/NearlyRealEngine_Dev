
    #version 450

    in float id;
    in vec2 uv;
    in mat3 TBN;
    in vec3 vertex;
    in vec3 normal;

    uniform sampler2DArray texNormal;

    out vec4 [2] fragData;

    void main() {
        vec2 outUV = mix(uv, fract(vec2(dot(normal.zxy, vertex), dot(normal.yzx, vertex))), uv == vec2(-1.0, -1.0));
        vec4 outNormal = texture(texNormal, vec3(outUV, id));
        outNormal = normalize(outNormal * 2.0 - 1.0);
        outNormal = normalize(vec4(TBN * outNormal.xyz, 1.0));
        outNormal.w = id;
	    fragData[0] = vec4(outUV, 0.0, 1.0);
        fragData[1] = outNormal;
    }

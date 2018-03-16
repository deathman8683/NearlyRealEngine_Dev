
    #version 450

    in vec3 vertex;
    in vec2 uv;

    uniform sampler2D texDiffuse;
    //uniform sampler2D texPosition;
    //uniform sampler2D texNormal;

    //uniform vec3 cameraV;

    out vec4 out_Color;

    void main() {
    	//vec4 image = texture(texDiffuse, uv);
    	//vec4 position = texture(texPosition, uv);
    	//vec4 normal = texture(texNormal, uv);

    	/*vec3 light = vec3(50,100,50);
    	vec3 lightDir = light - position.xyz ;

    	normal = normalize(normal);
    	lightDir = normalize(lightDir);

    	vec3 eyeDir = normalize(cameraV - position.xyz);
    	vec3 vHalfVector = normalize(lightDir.xyz + eyeDir);

    	out_Color = max(dot(normal.xyz, lightDir), 0) * image + pow(max(dot(normal.xyz, vHalfVector), 0.0), 100) * 1.5;*/
        out_Color = texture(texDiffuse, uv);
    }

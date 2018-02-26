// Version du GLSL

#version 450 core


// Entr�e

in vec2 coordTexture;


// Uniform

uniform sampler2D texture;


// Sortie

out vec4 out_Color;


// Fonction main

void main()
{
    // Couleur du pixel

    out_Color = texture(texture, coordTexture);
}

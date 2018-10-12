#version 410

out vec4 FragColour;
in vec2 vUV;

uniform sampler2D diffuseTexture;

void main()
{
	FragColour = texture(diffuseTexture, vUV);
}
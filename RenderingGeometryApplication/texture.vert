#version 410

layout(location = 0) in vec4 Position;
layout(location = 3) in vec2 UV;

out vec2 vUV;

uniform mat4 ProjectionViewWorld;

void main()
{
	vUV = UV;
	gl_Position = ProjectionViewModel * Position;
}
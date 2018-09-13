#pragma once

class Shader
{
public:
	Shader();
	~Shader();

	const char* vsSource;
	const char* fsSource;

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int m_program;

	void Initialize(const char* vertexShaderSource, const char* fragmentShaderSource);

};

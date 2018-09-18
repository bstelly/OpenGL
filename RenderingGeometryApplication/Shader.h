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

	void DefaultLoad(const char* vertexShaderSource, const char* fragmentShaderSource);
	void Load(const char* filename);

};

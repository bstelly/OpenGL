#pragma once
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	const char* vsSource;
	const char* fsSource;

	unsigned int vertexShader;
	unsigned int fragmentShader;

	std::string vsrc;
	std::string fsrc;


	unsigned int m_program;

	void DefaultLoad();
	void Load(const char* filename, unsigned int type);
	void Attach();
	void SetUpFragmentShader();

};

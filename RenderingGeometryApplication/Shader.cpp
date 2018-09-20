#include <gl_core_4_4.h>
#include "Shader.h"
#include <fstream>
#include <string>

using namespace std;

Shader::Shader()
{
	
}

Shader::~Shader()
{
	
}

void Shader::SetUp()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);

	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);

	m_program = glCreateProgram();

	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);
	glLinkProgram(m_program);
}

void Shader::DefaultLoad(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	vsSource = vertexShaderSource;
	fsSource = fragmentShaderSource;
	SetUp();
}

void Shader::Load(const char* filename)
{
	const char* line;
	fstream file;
	file.open(filename, ios_base::in);
	if (file.is_open())
	{
		string content((std::istreambuf_iterator<char>(file)),
			(std::istreambuf_iterator<char>()));
		
		string vertexShaderSource;
		string fragmentShaderSource;
		int counter = 0;
		int i = 0;
		while (counter < 2)
		{
			if (content[i] == '"')
			{
				counter += 1;
			}
			vertexShaderSource.append(string() + content[i]);
			i++;
		}
		counter = 0;
		while (counter < 2)
		{
			if (content[i] == '"')
			{
				counter += 1;
			}
			fragmentShaderSource.append(string() + content[i]);
			i++;
		}
		vsSource = vertexShaderSource.c_str();
		fsSource = fragmentShaderSource.c_str();
	}
	
	file.close();
	SetUp();
}

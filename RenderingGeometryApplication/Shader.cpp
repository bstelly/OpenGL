#include <gl_core_4_4.h>
#include "Shader.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Shader::Shader()
{

}

Shader::~Shader()
{
	
}

void Shader::Attach()
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




void Shader::DefaultLoad()
{
	vsSource = "#version 410\n \
				layout(location = 0) in vec4 Position; \
				layout(location = 1) in vec4 Color; \
				out vec4 vColor; \
				out vec4 vPosition; \
				uniform mat4 ProjectionViewWorld; \
				void main() { vColor = Color; \
				vPosition = Position;\
				gl_Position = ProjectionViewWorld * Position; }";

	fsSource = "#version 410\n \
				in vec4 vColor; \
				in vec4 vPosition;\
				out vec4 FragColor; \
				void main() { FragColor = vPosition; }";
	Attach();
}


void Shader::Load(const char* filename, unsigned int type)
{
	errno_t err;
	FILE *file;

	err = fopen_s(&file, filename, "r");

	char buf[500];
	int i = 0;
	while (std::fgets(buf, sizeof buf, file))
	{
		if (type == 1)
		{
			vsrc.append(buf);
		}
		if (type == 2)
		{
			fsrc.append(buf);
		}
	}
	if (type == 1)
	{
		vsSource = vsrc.c_str();
	}
	if (type == 2)
	{
		fsSource = fsrc.c_str();
	}
}


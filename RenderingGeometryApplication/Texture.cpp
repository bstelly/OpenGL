#include "Texture.h"
#include "stb_image.h"
#include "../Open_GL/gl_core_4_4.h"

Texture::Texture()
{
}

Texture::Texture(const char * filename)
{
}

Texture::Texture(unsigned int width, unsigned int height, Format format, unsigned char * pixels)
{
}

Texture::~Texture()
{
}

bool Texture::load(const char * filename)
{



	int imageWidth, imageHeight, imageFormat;
	unsigned char* data = stbi_load(filename, &imageWidth, &imageHeight, &imageFormat, STBI_rgb);
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &m_glHandle);
	glBindTexture(GL_TEXTURE_2D, m_glHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	
	stbi_image_free(data);
	return true;
}

void Texture::bind(unsigned int slot) const
{	
}

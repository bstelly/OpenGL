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
	if (m_glHandle != 0)
	{
		glDeleteTextures(1, &m_glHandle);
		m_glHandle = 0;
		m_width = 0;
		m_height = 0;
		m_filename = "";
	}


	int imageWidth, imageHeight, imageFormat;
	m_loadedPixels = stbi_load(filename, &imageWidth, &imageHeight, &imageFormat, STBI_rgb);
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &m_glHandle);
	glBindTexture(GL_TEXTURE_2D, m_glHandle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_loadedPixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(m_loadedPixels);
	return true;
}

void Texture::bind(unsigned int slot) const
{	
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_glHandle);
}

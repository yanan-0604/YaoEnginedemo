#include<glad/glad.h>
#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include"./stb_image.h"

Texture::Texture(const char* ptPath)
{
	glCreateTextures(GL_TEXTURE_2D, 1, &this->m_TextureID);
	glBindTexture(GL_TEXTURE_2D, this->m_TextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	int width, height, nrChannels;

	unsigned char* data = stbi_load("../YaoEngine/Resource/R.jpg", &width, &height, &nrChannels, 4);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->m_TextureID);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, this->m_TextureID);
}

void Texture::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

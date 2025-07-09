#pragma once

class Texture
{
public:
	Texture(const char* ptPath);
	~Texture();

	void bind();
	void unbind();

private:
	unsigned int m_TextureID;

};


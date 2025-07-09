#pragma once

class VertexBuffer
{
public:
	VertexBuffer(float* array, unsigned int size);
	~VertexBuffer();


	void Bind();
	void UnBind();


private:
	unsigned int m_VBOID;
	

};


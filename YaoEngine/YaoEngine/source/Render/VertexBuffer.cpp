#include "VertexBuffer.h"
#include<glad/glad.h>
#include<iostream>
VertexBuffer::VertexBuffer(float* array, unsigned int size)
{
	glCreateBuffers(1, &m_VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	glBufferData(GL_ARRAY_BUFFER, size, array, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_VBOID);
}

void VertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBOID);
	while (auto error = glGetError())
	{
		std::cout << error << std::endl;
	}
}

void VertexBuffer::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

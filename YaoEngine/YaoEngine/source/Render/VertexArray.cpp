#include "VertexArray.h"
#include<glad/glad.h>
#include<iostream>
VertexArray::VertexArray()
	:
	m_VBO(nullptr),m_IBO(nullptr)
{
	glCreateVertexArrays(1,&m_VAOID);
	
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1,&m_VAOID);
}

void VertexArray::BindBuffer(VertexBuffer* Buffer)
{
	glBindVertexArray(m_VAOID);
	Buffer->Bind();
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5* sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
}

void VertexArray::BindIndex(IndexArray*IndexBuffer)
{
	glBindVertexArray(m_VAOID);
	IndexBuffer->Bind();
	while (auto error = glGetError())
	{
		std::cout << error << std::endl;
	}
	
	m_IBO = IndexBuffer;
}



VertexBuffer* VertexArray::GetBuffer()
{
	return m_VBO;
}

IndexArray* VertexArray::GetIndex()
{
	return m_IBO;
}

void VertexArray::Bind()
{
	glBindVertexArray(m_VAOID);

}

void VertexArray::UnBind()
{
	glBindVertexArray(0);
}



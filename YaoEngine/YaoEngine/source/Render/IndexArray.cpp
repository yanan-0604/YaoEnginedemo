#include "IndexArray.h"
#include<glad/glad.h>
#include<filesystem>
#include<iostream>
IndexArray::IndexArray(unsigned int* array, unsigned int size)
	:m_Size(size/sizeof(unsigned int))
{
	glCreateBuffers(1, &m_IndexID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, array, GL_STATIC_DRAW);
}

IndexArray::~IndexArray()
{
	glDeleteBuffers(1, &m_IndexID);
}
void IndexArray::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexID);
}

void IndexArray::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexArray::Getcount()
{
	return m_Size;
}

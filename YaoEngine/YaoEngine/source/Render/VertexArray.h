#pragma once
#include<memory>
#include"VertexBuffer.h"
#include"IndexArray.h"
class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void BindBuffer(VertexBuffer*Buffer);
	void BindIndex(IndexArray* IndexBuffer);

	VertexBuffer* GetBuffer();
	IndexArray* GetIndex();

	void Bind();
	void UnBind();


private:
	unsigned int m_VAOID;
	VertexBuffer* m_VBO=nullptr;
	IndexArray* m_IBO=nullptr;

};


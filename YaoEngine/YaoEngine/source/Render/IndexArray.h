#pragma once
class IndexArray
{
public:
	IndexArray(unsigned int* array, unsigned int size);
	~IndexArray();


	void Bind();
	void UnBind();


	unsigned int Getcount();
private:
	unsigned int m_IndexID;
	unsigned int m_Size;
};


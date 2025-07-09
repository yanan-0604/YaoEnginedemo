#pragma once
#include<string>
/*enum class uniformType :long long
{
	None = 0,
	OneI,TwoI,ThreeI,FourI,
	OneF, TwoF, ThreeF, FourF,
	OneM, TwoM, ThreeM, FourM,
};
union ValueType {

	int u, v, w, a;
	float x, y, z, b;

};*/
class Shader
{
public:
	Shader(const char* vertexsourcePath, const char* framentsourcePath);
	~Shader();

	void Bind();
	void UnBind();

	//void setuniform(uniformType T=uniformType::None,const char*name="", ValueType Valua=ValueType());

	unsigned int m_ShaderID = 0;

private:
	
};


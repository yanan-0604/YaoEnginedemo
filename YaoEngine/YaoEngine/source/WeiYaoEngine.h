#include<core.h>
#include<memory>
#include<Render/Shader.h>
#include<Render/Texture.h>
#include<Render/VertexArray.h>
#include<vector>
#include<glm/glm.hpp>
#include<GLFW/glfw3.h>
#include"Timer/time.h"
#include<functional>
#include<File/File.h>
//#include"Event/Event.h"
WEIYAOAPI class  WeiYaoEngine {
public:
	WeiYaoEngine();
	~WeiYaoEngine();

	void Init();
	void update();
	void OnEvent();
	void run();
private:
	GLFWwindow* m_window;
	VertexArray* m_VAO;
	VertexBuffer* m_VBO;
	IndexArray* m_IBO;
	Shader* m_Shader;
	Texture* m_Texture;
	File* m_File;
	struct WindowData
	{
		glm::vec2 Mousepos;
		glm::vec2 Screen;
	};
	WindowData demo;
};
WeiYaoEngine* Create();
#include<Render/Render.h>

#include<glad/glad.h>
#include<WeiYaoEngine.h>
#include<map>
#include<iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
/*const char* vs = R"(
	#version 330 core

	layout (location = 0) in vec3 aPos;
	layout (location = 2) in vec2 aTexCoord;
	out vec2 TexCoord;
	
	void main()
	{
		gl_Position = vec4(aPos.x,-aPos.y,aPos.z, 1.0f);
		TexCoord = vec2(aTexCoord.x, aTexCoord.y);
	}
	)";
const char* fs = R"(
	#version 330 core
	out vec4 FragColor;
	in vec3 ourColor;
	in vec2 TexCoord;
	
	uniform sampler2D texture1;
	void main()
	{
		FragColor = texture(texture1, TexCoord);
	}
	)";
	*/
void WeiYaoEngine::Init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(900, 900, "YaoEngine", nullptr, nullptr);
	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetWindowUserPointer(m_window, &demo);

	glfwSetFramebufferSizeCallback(m_window,
		[](GLFWwindow* window, int x, int y)
		{
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);
			glViewport(0, 0, x, y);
			d.Screen = glm::vec2((float)x, (float)y);
		}
	);
	glfwSetCursorPosCallback(m_window,
		[](GLFWwindow* window, double x, double y)
		{
			WindowData& d = *(WindowData*)glfwGetWindowUserPointer(window);
			d.Mousepos = glm::vec2((float)x, (float)y);
		}
	);
}
WeiYaoEngine::WeiYaoEngine()
{ 
	Init();
	float San[] = {
		1.0f ,1.0f, 0.0f,			1.0f,0.0f,
		-1.0f,1.0f, 0.0f,			0.0f,0.0f,
		-1.0f , -1.0f, 0.0f,		0.0f,1.0f,
		1.0,-1.0f,0.0f,				1.0f,1.0f,

	};
	unsigned int index[] = {
			1,2,3,
			1,0,3,
	};
	m_File = new File[2];
	m_File[0].ReBind("../YaoEngine/source/Shader/glsl/vs.weiyao");
	m_File[1].ReBind("../YaoEngine/source/Shader/glsl/fs.weiyao");
	m_File[0].LoadFileSrc();
	m_File[1].LoadFileSrc();

	m_Texture = new Texture("../YaoEngine/Resource/R.jpg");
	m_Shader = new Shader(m_File[0].FileSrc().c_str(), m_File[1].FileSrc().c_str());
	m_VAO = new VertexArray();
	m_VBO = new VertexBuffer(San,sizeof(San));
	m_IBO = new IndexArray(index, sizeof(index));
	m_VAO->BindIndex(m_IBO);
	m_VAO->BindBuffer(m_VBO);
}

void WeiYaoEngine::run()
{
	while (!glfwWindowShouldClose(m_window))
	{
		YaoRender::SetclearColor(0.2f, 0.3f, 0.3f, 1.0f);
		m_Shader->Bind();
		glUniform2f(glGetUniformLocation(m_Shader->m_ShaderID, "screenSize"), demo.Screen.x, demo.Screen.y);
		glUniform2f(glGetUniformLocation(m_Shader->m_ShaderID, "Mousepos"), demo.Mousepos.x, demo.Mousepos.y);
		glm::mat4 transform = glm::mat4(1.0f); 
		transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
		transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        
		glUniformMatrix4fv(glGetUniformLocation(m_Shader->m_ShaderID, "transform"), 1, GL_FALSE, glm::value_ptr(transform));
		m_Texture->bind();
		m_VAO->Bind();

		glDrawElements(GL_TRIANGLES, m_VAO->GetIndex()->Getcount(), GL_UNSIGNED_INT, 0);
		OnEvent();
		update();
	}
}
void WeiYaoEngine::OnEvent()
{
	glfwPollEvents();
}
void WeiYaoEngine::update()
{
	glfwSwapBuffers(m_window);
}
WeiYaoEngine::~WeiYaoEngine()
{
	delete m_VBO;
	delete m_VAO;
	delete m_IBO;
	delete m_Texture;
	delete[] m_File;
}
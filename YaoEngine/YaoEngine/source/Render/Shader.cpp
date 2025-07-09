#include "Shader.h"
#include<glad/glad.h>
#include<glm/glm.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
Shader::Shader(const char* VertexSrc, const char* FramentSrc):
m_ShaderID(0)
{
    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs,1,&VertexSrc,nullptr);
    glCompileShader(vs);
    GLint isCompiled = 0;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(vs, maxLength, &maxLength, &errorLog[0]);
        for (GLchar i : errorLog)
        {
            std::cout << i;
        }
        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader(vs); // Don't leak the shader.
        return;
    }

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &FramentSrc, nullptr);
    glCompileShader(fs);
    isCompiled = 0;
    glGetShaderiv(fs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(fs, maxLength, &maxLength, &errorLog[0]);
        std::cout << "fail frament" << std::endl;
        for (GLchar i : errorLog)
        {
            std::cout << i;
        }
        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader(fs); // Don't leak the shader.
        return;
    }
    m_ShaderID = glCreateProgram();
    glAttachShader(m_ShaderID,vs);
    glAttachShader(m_ShaderID, fs);
    glLinkProgram(m_ShaderID);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(m_ShaderID, GL_LINK_STATUS, (int*)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(m_ShaderID, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(m_ShaderID, maxLength, &maxLength, &infoLog[0]);
        std::cout << "fail link" << std::endl;
        for (GLchar i : infoLog)
        {
            std::cout << i;
        }
        // We don't need the program anymore.
        
        // Don't leak shaders either.
        glDeleteShader(vs);
        glDeleteShader(fs);
        glDeleteProgram(m_ShaderID);
        // Use the infoLog as you see fit.

        // In this simple program, we'll just leave
        return;
    }

}

Shader::~Shader()
{
    glDeleteProgram(m_ShaderID);
}

void Shader::Bind()
{
    glUseProgram(m_ShaderID);
}

void Shader::UnBind()
{
    glUseProgram(0);
}
/*void Shader::setuniform(uniformType T, const char* name, ValueType Value)
{
    switch (T)
    {
    case uniformType::OneI:
        glUniform1i(glGetUniformLocation(m_ShaderID, name),Value.u ); break;
    case uniformType::TwoI:
        glUniform2i(glGetUniformLocation(m_ShaderID, name), Value.u, Value.v); break;
    case uniformType::ThreeI:
        glUniform3i(glGetUniformLocation(m_ShaderID, name), Value.u, Value.v, Value.w); break;
    case uniformType::FourI:
        glUniform4i(glGetUniformLocation(m_ShaderID, name), Value.u, Value.v, Value.w,Value.w); break;
    case uniformType::OneF:
        glUniform1f(glGetUniformLocation(m_ShaderID, name), Value.x); break;
    case uniformType::TwoF:
        glUniform2f(glGetUniformLocation(m_ShaderID, name), Value.x, Value.x); break;
    case uniformType::ThreeF:
        glUniform3f(glGetUniformLocation(m_ShaderID, name), Value.x, Value.y, Value.z); break;
    case uniformType::FourF:
        glUniform4f(glGetUniformLocation(m_ShaderID, name), Value.x, Value.y, Value.z, Value.b); break;
    }
}*/
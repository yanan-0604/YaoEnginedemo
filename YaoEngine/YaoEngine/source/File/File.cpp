#include "File.h"
#include<fstream>
#include <iostream>

File::File(const char* Path)
	:m_Path(Path)
{

}
File::File()
	:m_Path(nullptr)
{
	
}

File::~File()
{
}

void File::ReBind(const char* Path)
{
	m_Path = Path;
	LoadFileSrc();
}

void File::LoadFileSrc()
{
	std::ifstream file(m_Path);
	if (file.is_open())
	{
		std::string line;
		m_FileSrc.clear();
		while (std::getline(file, line))
		{
			m_FileSrc += line + "\n";
		}
		file.close();
	}
	else
	{
		m_FileSrc = "Error: Could not open file.";
	}
}

void File::WriteFileSrc(const std::string& src)
{
}

std::string File::FileSrc()
{
    return this->m_FileSrc;
}

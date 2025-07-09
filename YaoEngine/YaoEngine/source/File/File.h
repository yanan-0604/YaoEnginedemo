#pragma once
#include<string>
class File
{
public:
	File(const char* Path);
	File();
	~File();

	void ReBind(const char* Path);

	void LoadFileSrc();

	void WriteFileSrc(const std::string& src);

	std::string FileSrc();


private:
	const char* m_Path;
	std::string m_FileSrc;

};


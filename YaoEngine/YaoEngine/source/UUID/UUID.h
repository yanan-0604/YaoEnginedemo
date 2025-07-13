#pragma once
#include<string>
class UUID
{
public:

	UUID();
	~UUID();
	UUID(const UUID& other) = default;
	std::string GetUUID() const; 

private:
	std::string uuid;



};


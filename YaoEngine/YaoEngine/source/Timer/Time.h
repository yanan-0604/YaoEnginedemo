#pragma once
#include<chrono>
class Time
{
public:
	Time();
	~Time();

	void TimeReset();
	float UsingTime();


private:
	std::chrono::high_resolution_clock::time_point m_start;
};


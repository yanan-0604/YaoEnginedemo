#include "Time.h"

Time::Time()
{
	m_start = std::chrono::high_resolution_clock::now();
}

Time::~Time()
{

}

void Time::TimeReset()
{
	m_start = std::chrono::high_resolution_clock::now();
}

float Time::UsingTime()
{
	auto time = std::chrono::high_resolution_clock::now() - m_start;
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time);
	return static_cast<float>(duration.count()) / 1000.0f;
}

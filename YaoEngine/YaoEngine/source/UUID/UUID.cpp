#include "UUID.h"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
UUID::UUID()
{
	std::random_device rd;
	std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dist(0, 0xFFFFFFFF);

    uint32_t data[4];
    for (auto& x : data) x = dist(gen);

    // 设置版本号 (UUID v4): 版本字段的高 4 位为 0100
    data[1] = (data[1] & 0xFFFF0FFF) | 0x00004000;

    // 设置 variant (10xx)
    data[2] = (data[2] & 0x3FFFFFFF) | 0x80000000;

    std::stringstream ss;
    ss << std::hex << std::setfill('0')
        << std::setw(8) << data[0] << "-"
        << std::setw(4) << ((data[1] >> 16) & 0xFFFF) << "-"
        << std::setw(4) << (data[1] & 0xFFFF) << "-"
        << std::setw(4) << ((data[2] >> 16) & 0xFFFF) << "-"
        << std::setw(4) << (data[2] & 0xFFFF)
        << std::setw(8) << data[3];
	this->uuid = ss.str();

}

UUID::~UUID()
{
}

std::string UUID::GetUUID() const
{
	return this->uuid;
}

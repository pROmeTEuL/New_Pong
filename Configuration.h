#pragma once

#include <fstream>

class Configuration
{
public:
	Configuration() = default;
	~Configuration() = default;
	bool config(float& x, float& y, char* color, char* font, char* window_mode);
private:
	std::ifstream fin;
};

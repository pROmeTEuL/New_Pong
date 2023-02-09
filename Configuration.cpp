#include "Configuration.h"

#define RESOLUTION_X "window_width"
#define RESOLUTION_Y "window_height"
#define WINDOW_MODE "window_mode"
#define COLOR "color"
#define FONT "font"

int transform_to_digits(char* str)
{
	int nr = 0;
	int len = strlen(str);
	while (len) {
		if (str[len - 1] != '-')
			nr = nr * 10 + (str[len - 1] - '0');
		else
			nr *= -1;
		--len;
	}
	return nr;
}

bool Configuration::config(float& x, float& y, char* color, char* font, char* window_mode)
{
	x = 640, y = 480;
	strcpy(color, "undefined");
	strcpy(font, "undefined");
	strcpy(window_mode, "default");
	try {
		fin.open("game.config");
	}
	catch (std::error_code &e) {
		std::cout << e << std::endl;
		return false;
	}

	if (!fin.is_open()) {
		return false;
	}

	char* category = new char[20];
	while (fin.get(category, 20, '=')) {
		if (strcmp(category, RESOLUTION_X)) {
			fin.getline(category, 20);
			x = transform_to_digits(category);
			continue;
		}
		if (strcmp(category, RESOLUTION_Y)) {
			fin.getline(category, 20);
			y = transform_to_digits(category);
			continue;
		}
		if (strcmp(category, WINDOW_MODE)) {
			fin.getline(category, 20);
			window_mode = category;
			continue;
		}
		if (strcmp(category, COLOR)) {
			fin.getline(category, 20);
			color = category;
			continue;
		}
		if (strcmp(category, FONT)) {
			fin.getline(category, 20);
			font = category;
		}
	}
	delete[] category;
	bool result = true;
	if (x < 640) {
		std::cout << "WINDOW WIDTH IS LOWER THAN MINIMUM(PLEASE SET IT TO 640 OR HIGHER)\n";
		result = false;
	}
	if (y < 480) {
		std::cout << "WINDOW HEIGHT IS LOWER THAN MINIMUM(PLEASE SET IT TO 480 OR HIGHER)\n";
		result = false;
	}
	if (color == "undefined") {
		std::cout << "COLOR UNDEFINED\n";
		result = false;
	}
	if (font == "undefined") {
		std::cout << "FONT UNDEFINED\n";
		result = false;
	}
	fin.close();
	return result;
}

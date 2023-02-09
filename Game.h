#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"

using namespace sf;

class Game
{
public:
	Game(float x, float y, char* color, char* font, char* mode);
	~Game();
	void run();
private:
	void input();
	void update(float timeElapsed);
	void draw();
private:
	Ball ball;
	RenderWindow m_window;
	Color m_color;
	Font m_font;
	Vector2f m_resolution;
	int m_mode;
	bool proceed = true;
};
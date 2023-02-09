#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
	Ball(Color color);
	~Ball() = default;
	void handleInput(Event& event);
	void update(float elapsedTime);
public:
	Vector2f direction;
	RectangleShape m_rect;
private:
	float speed = 100;
	Vector2f m_position;
};


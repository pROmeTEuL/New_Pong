#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	Player();
	~Player() = default;
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
public:
	RectangleShape m_player;
private:
	float speed = 100;
	bool left;
	bool right;
};
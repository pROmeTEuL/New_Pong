#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
    Player(Color color, Vector2f resolution);
	~Player() = default;
    void handleInput();
    void update(float elapsedTime);
    RectangleShape getRect();
    Vector2f getPosition();
    bool movingLeft();
    bool movingRight();
private:
    void goLeft(float elapsedTime);
    void goRight(float elapsedTime);
private:
    RectangleShape m_rect;
    Vector2f m_position;
    float m_speed;
    Vector2f m_size;
    bool left = false;
    bool right = false;
};

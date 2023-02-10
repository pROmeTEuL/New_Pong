#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
    Ball(Color color, Vector2f resolution);
	~Ball() = default;
    void handleInput(Event& event, bool& inAir);
    void update(float elapsedTime);
    RectangleShape getRect();
    Vector2f getPosition();
    void changeDirectionX();
    void ceilingHit();
    void batHit();
    void effectDirection_Left();
    void effectDirection_Right();
    void toBat(Vector2f position, Vector2f resolution, bool& inAir);
private:
    RectangleShape m_rect;
    float speed = 100;
	Vector2f m_position;
    Vector2f m_size;
    Vector2f m_direction;
};


#include "Ball.h"

Ball::Ball(Color color, Vector2f resolution)
{
    m_size = Vector2f(resolution.x / 64, resolution.y / 48);
    m_rect.setSize(m_size);
    m_rect.setFillColor(color);
    m_direction.x = 0;
    m_direction.y = 1;
    speed = resolution.x / 2;
}

void Ball::handleInput(Event& event, bool& inAir)
{
    if (event.key.code == Keyboard::Space)
        inAir = true;
}

void Ball::update(float elapsedTime)
{
    m_rect.setPosition(m_position + elapsedTime * speed * m_direction);
    m_position = m_rect.getPosition();
}

RectangleShape Ball::getRect()
{
    return m_rect;
}

Vector2f Ball::getPosition()
{
    return m_position;
}

void Ball::changeDirectionX()
{
    m_direction.x = -m_direction.x;
}

void Ball::ceilingHit()
{
    m_direction.y = 1;
}

void Ball::batHit()
{
    m_direction.y = -1;
}

void Ball::effectDirection_Left()
{
    --m_direction.x;
}

void Ball::effectDirection_Right()
{
    ++m_direction.x;
}

void Ball::toBat(Vector2f position, Vector2f resolution, bool& inAir)
{
    m_position.y = position.y - m_size.y;
    m_position.x = position.x + (resolution.x / 5) / 2 - m_size.x / 2;
    m_direction.x = 0;
    inAir = false;
}

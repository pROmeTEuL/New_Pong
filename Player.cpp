#include "Player.h"

Player::Player(Color color, Vector2f resolution)
{
    m_size = Vector2f(resolution.x / 5, resolution.y / 48);
    m_speed = resolution.x / 0.75;
    m_rect.setSize(m_size);
    m_rect.setFillColor(color);
    m_position = Vector2f(0, resolution.y - m_size.y);
    m_rect.setPosition(m_position);
}

void Player::handleInput()
{
    left = Keyboard::isKeyPressed(Keyboard::Left);
    right = Keyboard::isKeyPressed(Keyboard::Right);
}

void Player::update(float elapsedTime)
{
    goLeft(elapsedTime);
    goRight(elapsedTime);
    m_rect.setPosition(m_position);
}

RectangleShape Player::getRect()
{
    return m_rect;
}

Vector2f Player::getPosition()
{
    return m_position;
}

bool Player::movingLeft()
{
    return left;
}

bool Player::movingRight()
{
    return right;
}

void Player::goLeft(float elapsedTime)
{
    if (left)
        if (m_position.x - m_speed * elapsedTime > 0)
            m_position.x -= m_speed * elapsedTime;
}

void Player::goRight(float elapsedTime)
{
    if (right)
        if (m_position.x + m_size.x + m_speed * elapsedTime < m_size.x * 5)
            m_position.x += m_speed * elapsedTime;
}

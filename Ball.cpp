#include "Ball.h"

Ball::Ball(Color color)
{
	m_rect.setSize(Vector2f(5, 5));
	m_rect.setFillColor(color);
}

void Ball::handleInput(Event& event)
{
	/// SERVE IS GOING TO BE ADDED
}

void Ball::update(float elapsedTime)
{
	m_rect.setPosition(m_position + elapsedTime * speed * direction);
	m_position = m_rect.getPosition();
}

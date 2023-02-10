#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"

using namespace sf;

class Game
{
public:
    Game(float x, float y, char* color, char* font, char* mode);
	~Game();
	void run();
private:
	void input();
    void update(float elapsedTime);
	void draw();
private:
    Ball* m_ball;
    Player* m_player;
	RenderWindow m_window;
    Color m_color;
	Font m_font;
	Vector2f m_resolution;
	int m_mode;
	bool proceed = true;
    bool m_paused = false;
    bool m_ball_in_air = false;
};

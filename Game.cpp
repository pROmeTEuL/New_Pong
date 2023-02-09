#include "Game.h"

#include <iostream>

Color getColor(char* str)
{
	if (strcmp(str, "default") || strcmp(str, "black"))
		return Color::Black;
	if (strcmp(str, "yellow"))
		return Color::Yellow;
	if (strcmp(str, "green"))
		return Color::Green;
	if (strcmp(str, "red"))
		return Color::Red;
	if (strcmp(str, "blue"))
		return Color::Blue;
	char msg[50];
	strcpy(msg, str);
	strcat(msg, " ISN'T A VALID COLOR, TRY OTHER OR DEFAULT!!!\n");
	throw std::exception(msg);
}

/****************************************************************************************************************		
********None       = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)********
********Titlebar   = 1 << 0, ///< Title bar + fixed border                                               ********
********Resize     = 1 << 1, ///< Title bar + resizable border + maximize button                         ********
********Close      = 1 << 2, ///< Title bar + close button                                               ********
********Fullscreen = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)      ********
********                                                                                                 ********
********Default = Titlebar | Resize | Close ///< Default window style                                    ********
****************************************************************************************************************/

int getMode(char* str)
{
	if (strcmp(str, "default") || strcmp(str, "windowed"))
		return 0b0111; // 1 << 0 | 1 << 1 | 1 << 2
	if (strcmp(str, "fullscreen"))
		return 0b1000; // 1 << 3
	if (strcmp(str, "borderless"))
		return 0b0;
	char msg[60];
	strcpy(msg, str);
	strcat(msg, " ISN'T A VALID WINDOW MODE, TRY OTHER OR DEFAULT!!!\n");
	throw std::exception(msg);
}

Game::Game(float x, float y, char* color, char* font, char* mode)
{
	m_resolution.x = x;
	m_resolution.y = y;
	m_font.loadFromFile(font);
	try {
		m_color = getColor(color);
		m_mode = getMode(mode);
	}
	catch (std::exception& e) {
		std::cout << &e;
		proceed = false;
	}
}

Game::~Game()
{
}

void Game::run()
{
	if (!proceed)
		return;
	Clock clock;
	while (m_window.isOpen()) {
		Time elapsedTime = clock.restart();
		input();
		update(elapsedTime.asSeconds());
		draw();
	}
}

void Game::input()
{
	Event event;
	while (m_window.pollEvent(event)) {
		ball.handleInput(event); /// it does nothing for now :)
		if (event.type == Event::Closed)
			m_window.close();
	}
}

void Game::update(float timeElapsed)
{
	ball.update(timeElapsed);
}

void Game::draw()
{
	m_window.clear();
	m_window.draw(ball.m_rect);
	m_window.display();
}

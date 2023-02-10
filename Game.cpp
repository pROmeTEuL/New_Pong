#include "Game.h"

#include <iostream>
#include <cstring>

Color getColor(char* str)
{
    if (!strcmp(str, "default") || !strcmp(str, "white"))
        return Color::White;
    if (!strcmp(str, "yellow"))
        return Color::Yellow;
    if (!strcmp(str, "green"))
        return Color::Green;
    if (!strcmp(str, "red"))
        return Color::Red;
    if (!strcmp(str, "blue"))
        return Color::Blue;
    char msg[100];
    strcpy(msg, str);
    strcat(msg, " ISN'T A VALID COLOR, TRY OTHER OR DEFAULT!!!\n");
    std::cout << msg << std::endl;
    throw std::exception();
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
    if (!strcmp(str, "default") || !strcmp(str, "windowed"))
        return 0b0111; // 1 << 0 | 1 << 1 | 1 << 2
    if (!strcmp(str, "fullscreen"))
        return 0b1000; // 1 << 3
    if (!strcmp(str, "borderless"))
        return 0b0;
    char msg[60];
    strcpy(msg, str);
    strcat(msg, " ISN'T A VALID WINDOW MODE, TRY OTHER OR DEFAULT!!!\n");
    std::cout << msg << std::endl;
    throw std::exception();
}

Game::Game(float x, float y, char* color, char* font, char* mode)
{
    m_resolution.x = x;
    m_resolution.y = y;
    if (strcmp(font, "default") == 0)
        m_font.loadFromFile("default.ttf");
    else
        m_font.loadFromFile(font);
    try {
        m_color = getColor(color);
        m_mode = getMode(mode);
        m_player = new Player(m_color, m_resolution);
        m_ball = new Ball(m_color, m_resolution);
        m_window.create(VideoMode(m_resolution.x, m_resolution.y), "New_Pong", m_mode);
    }
    catch (std::exception& e) {
        proceed = false;
    }
}

Game::~Game()
{
    delete[] m_ball;
}

void Game::run()
{
    if (!proceed)
        return;
    Clock clock;
    while (m_window.isOpen()) {
        Time elapsedTime = clock.restart();
        input();
        if (!m_paused)
            update(elapsedTime.asSeconds());
        draw();
    }
}

void Game::input()
{
    Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
            m_player->handleInput();
            m_ball->handleInput(event, m_ball_in_air);
            if ((event.key.code == Keyboard::P || event.key.code == Keyboard::Pause) && event.type == Event::KeyPressed)
                m_paused = !m_paused;
            if ((event.key.code == Keyboard::Escape || event.key.code == Keyboard::Q) && event.type == Event::KeyPressed)
                m_window.close();
        }
        if (event.type == Event::Closed)
            m_window.close();
    }
}

void Game::update(float elapsedTime)
{
    if (m_ball_in_air) {
        if (m_ball->getPosition().x <= 0 || m_ball->getPosition().x >= m_resolution.x)
            m_ball->changeDirectionX();
        if (m_ball->getPosition().y <= 0)
            m_ball->ceilingHit();
        if (m_ball->getRect().getGlobalBounds().intersects(m_player->getRect().getGlobalBounds())) {
            m_ball->batHit();
            if (m_player->movingLeft())
                m_ball->effectDirection_Left();
            if (m_player->movingRight())
                m_ball->effectDirection_Right();
        }
        if (m_ball->getPosition().y >= m_resolution.y)
            m_ball->toBat(m_player->getPosition(), m_resolution, m_ball_in_air);
    } else {
        m_ball->toBat(m_player->getPosition(), m_resolution, m_ball_in_air);
    }
    m_ball->update(elapsedTime);
    m_player->update(elapsedTime);
}

void Game::draw()
{
    m_window.clear();
    m_window.draw(m_player->getRect());
    m_window.draw(m_ball->getRect());
    m_window.display();
}

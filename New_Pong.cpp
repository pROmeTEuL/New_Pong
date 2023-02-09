#include "Configuration.h"
#include "Game.h"

int main()
{
    Configuration configuration;
    float x, y;
    char* color = new char[20];
    char* font = new char[30];
    char* mode = new char[20];
    if (configuration.config(x, y, color, font, mode)) {
        Game game(x, y, std::move(color), std::move(font), std::move(mode));
        game.run();
        delete[] color, font, mode;
        return 0;
    }
    delete[] color, font, mode;
    return -1;
}
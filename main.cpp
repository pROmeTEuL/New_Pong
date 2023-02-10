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
        Game game(x, y, color, font, mode);
        game.run();
        delete[] color;
        delete[] font;
        delete[] mode;
        return 0;
    }
    delete[] color;
    delete[] font;
    delete[] mode;
    return -1;
}

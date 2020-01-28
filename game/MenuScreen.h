#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuScreen{

    Font font;
    float windowWidth, windowHeight;

    public:

        MenuScreen(Font appFont,float windowWidth, float windowHeight);
        MenuScreen();
        ~MenuScreen();
        void render(RenderWindow &window, Sprite &Background, Clock &deltaClock);

};

#endif //MENUSCREEN_H
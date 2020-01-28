#ifndef MENUSCREEN_H
#define MENUSCREEN_H
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuScreen{

    Font font;
    float windowWidth, windowHeight;

    public:

        MenuScreen(Font appFont, float width, float height);
        MenuScreen();
        ~MenuScreen();
        void render(RenderWindow &window, Sprite &Background, Clock &deltaClock);
        void mouseIn(Text &text);
        void mouseOut(Text &text);

};

#endif //MENUSCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuScreen.h"

using namespace sf;


MenuScreen::MenuScreen(Font appFont, float width, float height)
: font(appFont), windowHeight(height), windowWidth(width)
{
    ;
}


void MenuScreen::render(RenderWindow &window, Sprite &Background){

    Text resume("Resume", font);
    Text quit("Quit", font);
    bool endScreen = false;

    resume.setCharacterSize(60);
    resume.setStyle(Text::Bold);
    resume.setFillColor(Color::White);
    resume.setOutlineColor(Color::Black);
    resume.setOutlineThickness(4);
    resume.setPosition(windowWidth/2-(resume.getLocalBounds().width)/2, windowHeight/6);

    quit.setCharacterSize(60);
    quit.setStyle(Text::Bold);
    quit.setFillColor(Color::White);
    quit.setOutlineColor(Color::Black);
    quit.setOutlineThickness(4);
    quit.setPosition(windowWidth/2-(quit.getLocalBounds().width)/2, windowHeight/4);

    
    while(window.isOpen() && !endScreen){

        Event e;

        if(Mouse::isButtonPressed(Mouse::Left)){

            int mouseX = Mouse::getPosition(window).x;
            int mouseY = Mouse::getPosition(window).y;

            if(resume.getGlobalBounds().contains(mouseX, mouseY)){

                endScreen = true;

            }

            else if(quit.getGlobalBounds().contains(mouseX, mouseY)){

                window.close();

            }

        }


    }

    

}

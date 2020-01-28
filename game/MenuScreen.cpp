#include <SFML/Graphics.hpp>
#include <iostream>
#include "MenuScreen.h"

using namespace sf;


MenuScreen::MenuScreen(Font appFont, float width, float height)
: font(appFont), windowHeight(height), windowWidth(width)
{
    ;
}

MenuScreen::MenuScreen()
{
    ;
}

MenuScreen::~MenuScreen()
{
    ;
}

void MenuScreen::mouseIn(Text &text)
{
    text.setFillColor(Color::Red);
    text.setOutlineColor(Color::Yellow);

}

void MenuScreen::mouseOut(Text &text)
{
    text.setFillColor(Color::White);
    text.setOutlineColor(Color::Black);

}


void MenuScreen::render(RenderWindow &window, Sprite &Background, Clock &deltaClock)
{

    Text resume("Resume", font);
    Text quit("Quit", font);
    bool endScreen = false;
    bool firstTimeInResume = true;
    bool firstTimeOutResume = true;
    bool firstTimeInQuit = true;
    bool firstTimeOutQuit = false;


    resume.setCharacterSize(60);
    resume.setStyle(Text::Bold);
    resume.setFillColor(Color::White);
    resume.setOutlineColor(Color::Black);
    resume.setOutlineThickness(4);
    resume.setPosition(windowWidth/2-(resume.getGlobalBounds().width)/2, windowHeight/6);

    quit.setCharacterSize(60);
    quit.setStyle(Text::Bold);
    quit.setFillColor(Color::White);
    quit.setOutlineColor(Color::Black);
    quit.setOutlineThickness(4);
    quit.setPosition(windowWidth/2-(quit.getGlobalBounds().width)/2, windowHeight/2);

    
    while(!endScreen && window.isOpen()){


        Event e;

        deltaClock.restart();

        endScreen = false;


        while (window.pollEvent(e))
        {

            switch (e.type)
            {
                // window closed
                case Event::Closed:
                    window.close();
                    break;

                case Event::KeyReleased:

                    if(e.key.code == Keyboard::Escape){

                        endScreen = true;

                    }
                    break;

                default:
                    break;
            }
        }


        int mouseX = Mouse::getPosition(window).x;
        int mouseY = Mouse::getPosition(window).y;

        if(resume.getGlobalBounds().contains(mouseX, mouseY)){

            if(firstTimeInResume) {
                mouseIn(resume);
                firstTimeInResume = false;
                firstTimeOutResume = true;
            }

        }
        else {
            if(firstTimeOutResume){
                mouseOut(resume);
                firstTimeInResume = true;
                firstTimeOutResume = false;
            }


        }

        if(quit.getGlobalBounds().contains(mouseX, mouseY)){

            if(firstTimeInQuit){
                mouseIn(quit);
                firstTimeInQuit = false;
                firstTimeOutQuit = true;
            }

        }
        else{

            if(firstTimeOutQuit){
                mouseOut(quit);
                firstTimeInQuit = true;
                firstTimeOutQuit = false;
            }
            

        }

        if(Mouse::isButtonPressed(Mouse::Left)){



            if(resume.getGlobalBounds().contains(mouseX, mouseY)){

                endScreen = true;
                
            }

            else if(quit.getGlobalBounds().contains(mouseX, mouseY)){

                endScreen = true;
                window.close();

            }

        }

        /*if(Keyboard::isKeyPressed(Keyboard::Escape)){

            endScreen = true;

        }*/


    window.draw(Background);
    window.draw(resume);
    window.draw(quit);
    window.display();


    }

}

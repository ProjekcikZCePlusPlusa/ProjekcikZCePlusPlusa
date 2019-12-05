#include "Menu.h"

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("arial.tff"))
    {
        // error
    }

    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Graj");
    text[0].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS +1) * 1));

    text[1].setFont(font);
    text[1].setColor(sf::Color::White);
    text[1].setString("Opcje");
    text[1].setPosition(sf::Vector2f(width/2, height / (MAX_NUMBER_OF_ITEMS +1) * 2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString("Wyjdź");
    text[2].setPosition(sf::Vector2f(width/2, height / ( MAX_NUMBER_OF_ITEMS + 1 ) * 3));
}

void Menu::draw(sf::RenderWindow &app)
{
    for(int i = 0; i<MAX_NUMBER_OF_ITEMS; i++)
    {
        app.draw(text[i]);
    }
}

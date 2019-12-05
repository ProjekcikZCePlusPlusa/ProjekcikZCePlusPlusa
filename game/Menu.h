#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &app);
    void MoveUp();
    void MoveDown();

private:
    int selectedItemId;
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
};
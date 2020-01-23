#ifndef BLOCK_H
#define BLOCK_H
#include<SFML/Graphics.hpp>
using namespace sf;

class Block{

    
    int hits_left;

    int x, y;

    float width, height;

    Texture hit1, hit2, hit3;

    Sprite sprite;

    void loadTextures();
    void setTexture();

    public:

        Block();
        Block(int hl, int coord_x, int coord_y);
        Block(int hl, int coord_x, int coord_y, int block_width, int block_height);


        void hit();

        void setHitsLeft(int newHl);

        void setX(int newX);
        void setY(int newY);
        void setPosition(int newX, int newY);
        void setWidth(int newWidth);
        void setHeight(int newHeight);

        void draw(RenderWindow &window);

        FloatRect getGlobalBounds();

        void move(int dX, int dY);



};

#endif 
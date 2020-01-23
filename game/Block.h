#ifndef BLOCK_H
#define BLOCK_H
#include<SFML/Graphics.hpp>
using namespace sf;

class Block{

    
    int hits_left;

    int x, y;

    float width, height;

    Texture hit1, hit2, hit3;

    void loadTextures();

    public:

        Block();
        Block(int hl, int coord_x, int coord_y);
        Block(int hl, int coord_x, int coord_y, int block_width, int block_height);


        void hit();

        void setHitsLeft();

        void setX();
        void setY();

};

#endif 
#include "Block.h"

#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;


Block::Block(int hl, int coord_x, int coord_y)
:hits_left(hl), x(coord_x), y(coord_y)
{
    loadTextures();
}


Block::Block(int hl, int coord_x, int coord_y, int block_width, int block_height)
:hits_left(hl), x(coord_x), y(coord_y), width(block_width), height(block_height)
{
    loadTextures();
}


Block::Block()
:hits_left(1), x(0), y(0), width(20), height(20)
{
    loadTextures();
}


void Block::loadTextures(){

    hit1.loadFromFile("images/block01.jpg");

}


void Block::hit(){

    hits_left -= 1;

    

}
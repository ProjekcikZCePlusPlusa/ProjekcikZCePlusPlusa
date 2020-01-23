#include "Block.h"

#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;

Block::Block(int hl)
:hits_left(hl)
{
    ;
}

Block::Block()
:hits_left(1)
{
    ;
}

void Block::hit(){

    hits_left -= 1;

}
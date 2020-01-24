#include "Block.h"

#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;


Block::Block(int hl, int coord_x, int coord_y)
:hits_left(hl), x(coord_x), y(coord_y)
{
    loadTextures();
    setTexture();
}


Block::Block(int hl, int coord_x, int coord_y, int block_width, int block_height)
:hits_left(hl), x(coord_x), y(coord_y), width(block_width), height(block_height)
{
    loadTextures();
    setTexture();
}


Block::Block()
:hits_left(1), x(0), y(0), width(20), height(20)
{
    loadTextures();
    setTexture();
}


void Block::loadTextures(){

    hit1.loadFromFile("images/block01.png");
    hit2.loadFromFile("images/block02.png");
    hit3.loadFromFile("images/block03.png");
    hit1.setSmooth(true);
    hit2.setSmooth(true);
    hit3.setSmooth(true);

}


void Block::setTexture(){

    Vector2u textureSize = hit1.getSize();

    switch(hits_left){
        case 1: sprite.setTexture(hit1); textureSize = hit1.getSize();
        break;
        case 2: sprite.setTexture(hit2); textureSize = hit2.getSize();
        break;
        case 3: sprite.setTexture(hit3); textureSize = hit3.getSize();
        break;
    }
    
    sprite.setScale(width / textureSize.x, height / textureSize.y);

}


void Block::setX(int newX){

    x = newX;
    sprite.setPosition(x, y);

}


void Block::setY(int newY){

    y = newY;
    sprite.setPosition(x, y);

}


void Block::setPosition(int newX, int newY){

    x = newX;
    y = newY;
    sprite.setPosition(x,y);

}


void Block::setHeight(int newHeight){

    height = newHeight;
    setTexture();

}


void Block::setWidth(int newWidth){

    width = newWidth;
    setTexture();

}


void Block::setHitsLeft(int newHl){

    hits_left = newHl;
    setTexture();

}


void Block::move(int dX, int dY){

    x += dX;
    y += dY;
    sprite.setPosition(x, y);

}


FloatRect Block::getGlobalBounds(){

    FloatRect r1(x, y, width, height);

    return r1;

}


void Block::draw(RenderWindow &window){

    window.draw(sprite);

}


void Block::hit(){

    hits_left -= 1;

    if(hits_left <= 0){

        setPosition(-100, 0);

    }
    
    setTexture();

}


void Block::hit(int& howMuchLeft){

    hits_left -= 1;

    if(hits_left <= 0){

        setPosition(-100, 0);
        howMuchLeft -= 1;

    }

    setTexture();

}
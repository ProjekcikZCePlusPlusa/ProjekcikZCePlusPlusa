#ifndef BLOCK_H
#define BLOCK_H
#include<SFML/Graphics.hpp>
using namespace sf;

class Block{

    
    int hits_left;

    public:

        Block();
        Block(int hl);

        void hit();

};

#endif 
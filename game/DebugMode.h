#ifndef DEBUGMODE_H
#define DEBUGMODE_H
#include <SFML/Graphics.hpp>
using namespace sf;


class DebugMode{
	public:
        DebugMode(float height,float width,float x,float y,float dx,float dy);
private:
	float height;
	float width;
	float x;
	float y;
	float dx;
	float dy;
};


#endif //DEBUGMODE_H

#include "DebugMode.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void DebugMode(float height,float width,float x,float y,float dx,float dy)
	{
	Text dxtext(dx,font);
	dxtext.setCharacterSize(15);
	dxtext.setFillColor(Color::White);
	dxtext.Transformable::SetPosition(10,10);
	
	Text dytext(dy,font);
	dytext.setCharacterSize(15);
	dytext.setFillColor(Color::White);
	dytext.Transformable::SetPosition(10,20);
	
	Text xtext(x,font);
	xtext.setCharacterSize(15);
	xtext.setFillColor(Color::White);
	xtext.Transformable::SetPosition(height-10,width-10);
	
	Text ytext(y,font);
	ytext.setCharacterSize(15);
	ytext.setFillColor(Color::White);
	dxtext.Transformable::SetPosition(height-20,width-20);
	}
				

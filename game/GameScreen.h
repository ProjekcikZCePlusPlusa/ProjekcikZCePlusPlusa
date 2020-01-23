#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include <SFML/Graphics.hpp>
using namespace sf;


class GameScreen{
	public:
        GameScreen(long width, long height);
		GameScreen();
		void start(RenderWindow &app);
    private:
        long width;
        long height;
};


#endif //GAMESCREEN_H

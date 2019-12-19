#include <SFML/Graphics.hpp>
#include <time.h>
#include "GameScreen.h"
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(700, 500), "Szkielet");
    app.setFramerateLimit(60);

    GameScreen gameScreen(app.getSize().x, app.getSize().y);
    gameScreen.start(app);


  return 0;
}

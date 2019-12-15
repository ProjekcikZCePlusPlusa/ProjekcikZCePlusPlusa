#include <SFML/Graphics.hpp>
#include <time.h>
#include "GameScreen.h"
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(520, 450), "Szkielet");
    app.setFramerateLimit(60);

    GameScreen gameScreen;
    gameScreen.start(app);


  return 0;
}

#include "GameScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

GameScreen::GameScreen(long screenWidth, long screenHeight)
{
    width = screenWidth;
    height = screenHeight;
}

void GameScreen::start(RenderWindow &app)
{
    int hp_left = 3;
    Font font;
    Texture t1,t2,t3,t4,hp;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/background2.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");  
    hp.loadFromFile("images/hp.png");  
    font.loadFromFile("Font/OpenSans_Bold.ttf");

    auto paddleTextureSize = t4.getSize();
    auto paddleWidth = width / 6.0;
    auto paddleThickness = height / 80.0;

    std::cout << paddleTextureSize.y << std::endl;

    Sprite sBackground(t2), sBall(t3), sPaddle(t4), sHp(hp);
    sPaddle.setScale(paddleWidth / paddleTextureSize.x, paddleThickness / paddleTextureSize.y);
    sPaddle.setPosition(width/2.0 - paddleWidth/2.0 , height * 95 / 100.0);

    Text text("Przegrana", font);
    text.setCharacterSize(60);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Red);
    text.setOutlineColor(Color::Yellow);
    text.setOutlineThickness(4);
    text.setPosition(width/2-(text.getLocalBounds().width)/2, height/6);
  
    auto ballSize = paddleThickness * 1.66;
    sBall.setScale(ballSize  / t3.getSize().x, ballSize  / t3.getSize().y);

    int blockCount = 1000;

    Sprite block[blockCount];

    auto blockWidth = (width - paddleWidth) / 10.0;
    auto blockHeight = (height / 20.0);

    auto backgroundWidth = width;
    auto backgroundHeight = height;

    sBackground.setScale(width * 1.0 / t2.getSize().x, height * 1.0 / t2.getSize().y);


    int n=0;
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            block[n].setTexture(t1);
            block[n].setScale(blockWidth/t1.getSize().x, blockHeight/t1.getSize().y);
            block[n].setPosition(i*blockWidth,j*blockHeight);
            n++;
        }

    float x_center = (width/2+ballSize/2);
    float x=x_center, y=300;
    float dx = 2, dy = 2;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        x+=dx;
        for (int i=0;i<n;i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
            {block[i].setPosition(-100,0); dx=-dx;}

        y+=dy;
        for (int i=0;i<n;i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
            {block[i].setPosition(-100,0); dy=-dy;}

        if (x<0 || x>width)  dx=-dx;
        if (y<0)  dy=-dy;
        if(y-ballSize*2 > height){
            dy=-dy;
            hp_left = hp_left-1;
            std::cout << "Pozostale zycia: " << hp_left << std::endl;
            x = x_center, y = 300;
            dx = 2, dy = 2;
            sPaddle.setPosition(width/2.0 - paddleWidth/2.0 , height * 95 / 100.0);
        }

        if(hp_left <= 0){
            dx = 0, dy = 0;
            x = x_center, y = 300;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            sPaddle.move(6,0);
            if(sPaddle.getGlobalBounds().left > width-(paddleWidth/2.0)) sPaddle.setPosition(width-(paddleWidth/2.0), sPaddle.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            sPaddle.move(-6,0);
            if(sPaddle.getGlobalBounds().left < -(paddleWidth/2.0)) sPaddle.setPosition(-(paddleWidth/2.0), sPaddle.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();

        if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);

        sBall.setPosition(x,y);

        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        for(int i=0;i<hp_left;i++){
            sHp.setPosition(width-25-(i*20),10);
            app.draw(sHp);
        }
        for (int i=0;i<n;i++)
            app.draw(block[i]);
        if(hp_left <= 0){
            app.draw(text);
        }
        app.display();
    }

}

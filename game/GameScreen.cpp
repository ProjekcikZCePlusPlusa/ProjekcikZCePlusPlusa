#include "GameScreen.h"
#include "Block.h"
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
    double czas = 0;
    int hp_left = 3;
    int bon_x = -200;
    int bon_y = -200;
    Font font;

    Texture t1,t2,t3,hp, bon;
    t1.loadFromFile("images/background2.jpg");
    t2.loadFromFile("images/ball.png");
    t3.loadFromFile("images/paddle.png");  
    hp.loadFromFile("images/hp.png");  
    bon.loadFromFile("images/bon.png");  
    font.loadFromFile("Font/OpenSans_Bold.ttf");

    t1.setSmooth(true);
    t2.setSmooth(true);

    auto paddleTextureSize = t3.getSize();
    auto paddleWidth = width / 6.0;
    auto paddleThickness = height / 80.0;

    std::cout << paddleTextureSize.y << std::endl;

    Sprite sBackground(t1), sBall(t2), sPaddle(t3), sHp(hp), sBon(bon);

    sPaddle.setScale(paddleWidth / paddleTextureSize.x, paddleThickness / paddleTextureSize.y);
    sPaddle.setPosition(width/2.0 - paddleWidth/2.0 , height * 95 / 100.0);

    Text defeatMessage("Przegrana", font);
    defeatMessage.setCharacterSize(60);
    defeatMessage.setStyle(Text::Bold);
    defeatMessage.setFillColor(Color::Red);
    defeatMessage.setOutlineColor(Color::Yellow);
    defeatMessage.setOutlineThickness(4);
    defeatMessage.setPosition(width/2-(defeatMessage.getLocalBounds().width)/2, height/6);

    Text victoryMessage("Wygrana!", font);
    victoryMessage.setCharacterSize(60);
    victoryMessage.setStyle(Text::Bold);
    victoryMessage.setFillColor(Color::Red);
    victoryMessage.setOutlineColor(Color::Yellow);
    victoryMessage.setOutlineThickness(4);
    victoryMessage.setPosition(width/2-(victoryMessage.getLocalBounds().width)/2, height/6);
  
    auto ballSize = paddleThickness * 1.66;
    sBall.setScale(ballSize  / t2.getSize().x, ballSize  / t2.getSize().y);

    int blockCount = 70; //Tę zmienną zmienić jeżeli chcemy zmienić ilość bloków
    int blocksPerRow = 10; //Tę zmienną zmienić jeżeli chcemy zmienić ilość bloków w jednym rzędzie
    int blocksLeft = blockCount; //Zmienna licząca ile bloków zostało do końca. Potrzebna do wygranej.

    auto blockWidth = (width - paddleWidth) / 10.0;
    auto blockHeight = (height / 20.0);

    Block block[blockCount];

    auto backgroundWidth = width;
    auto backgroundHeight = height;

    sBackground.setScale(width * 1.0 / t1.getSize().x, height * 1.0 / t1.getSize().y);


    int n=0;
    for (int i=0;i<=blockCount/blocksPerRow;i++)
        for (int j=1;j<=blocksPerRow;j++)
        {
            int blocksToDraw = blockCount - (i * blocksPerRow) - j;
            if(blocksToDraw >= 0)
            {
                block[n].setHitsLeft( (i % 3) + 1);
                block[n].setWidth(blockWidth);
                block[n].setHeight(blockHeight);
                block[n].setPosition(j*blockWidth,(i+1)*blockHeight);
                n++;
            }
        }

    float x_center = (width/2+ballSize/2);
    float x=x_center, y=300;

    Clock deltaClock;
    Time deltaTime;

    float dt = 0;
    float dx = rand()%500-250, dy = 200;
    while (dx < 30 && dx > -30){        //bez zakresu miedzy 70 a -70, bo jest za latwo
        dx = rand()%500-250, dy = 200;
    }


    while (app.isOpen())
    {
        Event e;

        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        x += dx * dt; //Updating x coordinate of the ball

        for (int i=0;i<n;i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
            {block[i].hit(blocksLeft); dx =- dx; x += dx * dt;}

        y += dy * dt; //Updating y coordinate of the ball

        for (int i=0;i<n;i++)
            if ( FloatRect(x+3,y+3,6,6).intersects(block[i].getGlobalBounds()) )
            {block[i].hit(blocksLeft); dy =- dy; y += dy * dt;}

        if (x < 0 || x > width - ballSize){

            dx =- dx;

            if (x > width - ballSize){

                x = width - ballSize;

            }

            else{

                x = 0;

            }
        } 

        if (y < 0){

            dy =- dy;

            y = 0;

        }

        if(y - ballSize*2 > height){
            dy =- dy;
            hp_left = hp_left-1;
            std::cout << "Pozostale zycia: " << hp_left << std::endl;
            x = x_center, y = 300;
            dx = rand()%500-250, dy = 200;
            while (dx < 70 && dx > -70){
                dx = rand()%500-250, dy = 200;
            }
            sPaddle.setPosition(width/2.0 - paddleWidth/2.0 , height * 95 / 100.0);
        }

        if(hp_left <= 0){
            dx = 0, dy = 0;
            x = x_center, y = 300;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            sPaddle.move(250 * dt,0);
            if(sPaddle.getGlobalBounds().left > width - paddleWidth) sPaddle.setPosition(width - paddleWidth, sPaddle.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            sPaddle.move(-250 * dt,0);
            if(sPaddle.getGlobalBounds().left < 0) sPaddle.setPosition(0, sPaddle.getPosition().y);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) app.close();

        if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ){
            dy = -(rand()%3+2) * 100 ;
            if(Keyboard::isKeyPressed(Keyboard::Right)){
                dx = dx + 20;
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left)){
                dx = dx - 20;
            }
        } 

        if ( FloatRect(x,y,12,12).intersects(sBon.getGlobalBounds()) ){
            std::cout << "JEB!"<<std::endl;
            hp_left += 1;
            bon_x = -200;
            bon_y = -200;
        }

        sBall.setPosition(x,y);
        sBon.setPosition(bon_x,bon_y);
        czas = czas + deltaTime.asSeconds();

        if(czas > 10){      //bonusy
            bon_x = rand()%(width - 50);
            bon_y = rand()%(height - 50);
            czas = 0;
        }

        deltaTime = deltaClock.restart();
        dt = deltaTime.asSeconds(); //Getting time passed between frames
        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);
        for(int i=0;i<hp_left;i++){
            sHp.setPosition(width-25-(i*20),10);
            app.draw(sHp);
        }

        for (int i=0;i<n;i++){
            block[i].draw(app);
        }
        app.draw(sBon);
        if(hp_left <= 0){
            app.draw(defeatMessage);
        }

        if(blocksLeft <= 0){ // Wygrana

            dx = 0, dy = 0;
            x = x_center, y = 300; 
            app.draw(victoryMessage);   

        }

        app.display();

    }

}

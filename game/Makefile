Arkanoid: main.o GameScreen.o Block.o MenuScreen.o
	g++ main.o GameScreen.o Block.o MenuScreen.o -o Arkanoid -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

GameScreen.o: GameScreen.cpp
	g++ -c GameScreen.cpp

Block.o: Block.cpp
	g++ -c Block.cpp

MenuScreen.o: MenuScreen.cpp
	g++ -c MenuScreen.cpp

clean:
	rm -f *.o Arkanoid


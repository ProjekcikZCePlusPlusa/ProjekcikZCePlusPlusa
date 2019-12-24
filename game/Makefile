sfml-app: main.o GameScreen.o DebugMode.o
	g++ main.o GameScreen.o DebugMode.o -o projekt_test -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

GameScreen.o: GameScreen.cpp
	g++ -c GameScreen.cpp

DebugMode.o: DebugMode.cpp
	g++ -c DebugMode.cpp

clean:
	rm -f *.o projekt_test


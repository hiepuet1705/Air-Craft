#include<SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include<time.h>
int main()
{
	srand(time(0));

	Game game;
	game.run();
	return 0;

}


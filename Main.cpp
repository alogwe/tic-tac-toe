#include <iostream>
#include <exception>
#include "Game.h"


int main()
{	
	Game game = Game("Tic-Tac-Toe", 2);
	game.start();
	
	do
	{
		game.turn();
	} while (!game.isOver());
	
	game.end();
	
	return EXIT_SUCCESS;
}


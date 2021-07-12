#include <iostream>
#include <exception>
#include "Game.h"


int main()
{	
	Game game = Game("Tic-Tac-Toe", 2);
	game.start();
	
	do {
		game.turn();
	} while (!game.hasWinner() && !game.isTied());
	
	game.end();
	
	return EXIT_SUCCESS;
}


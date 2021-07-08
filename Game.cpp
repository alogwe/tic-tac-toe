#include <iostream>
#include <string>
#include "Game.h"
#include "KeyMap.h"
#include "Board.h"
#include <assert.h>

using namespace std;

Game::Game(string title, int maxPlayers)
	: title(title), maxPlayers(maxPlayers)
{
	assert("" != title);
	assert(maxPlayers > 0);

	lastMove = "";
	currentPlayer = 1;
	lastPlayer = 2;
	board = new Board(3, 3);
	keys = new KeyMap();
}

Game::~Game()
{
	delete board;
	delete keys;
}

void Game::start()
{
	cout << "\n\n\n";
	cout << "\t\t\t" << "Welcome to '" << title << "'";
	cout << "\n\n\n";
	cout << "\n\n\n";

	cout << "Press 'Enter' to continue." << endl;
	getchar();
}

string Game::getUserInput(string prompt)
{
	string input = "";

	do {
		cout << prompt << endl;
		getline(cin, input);
	} while (0 == input.length());

	return input;
}

// TODO: exception handling
void Game::turn()
{
	draw();
	
	if ("" != lastError)
	{
		cout << lastError << endl;
		lastError = "";
	}
	else
	{
		if ("" != lastMove)
		{
			cout << "Player " << lastPlayer << " chose " << lastMove << endl;
		}
	}

	cout << endl;

	lastMove = getUserInput("Player " + to_string(currentPlayer) + ", choose your next move (1 - 9), then press 'Enter'");
	
	if (board->update(keys, lastMove, currentPlayer))
	{
		lastError = "";
		draw();
		nextPlayer();
	}
	else
	{
		lastError = "ERROR: board->update unsuccessful\n";
	}
}

void Game::nextPlayer()
{
	if (1 == maxPlayers)
	{
		currentPlayer = maxPlayers;
	}
	if (2 == maxPlayers)
	{
		if (1 == currentPlayer)
		{
			currentPlayer = 2;
			lastPlayer = 1;
		}
		else if (2 == currentPlayer)
		{
			currentPlayer = 1;
			lastPlayer = 2;
		}
	}
	else
	{
		// TODO: support any number of players
	}
}

void Game::draw()
{
	clear();
	cout << endl;
	cout << title << endl;

	board->draw();
}

// TODO: support linux; currently only supports windows ('cls')
void Game::clear()
{
	system("cls");
}

bool Game::hasWinner()
{
	return board->checkWinner("X") || board->checkWinner("O");
}

// lastPlayer made the winning move
void Game::announceWinner()
{
	cout << endl;
	cout << "Player " << to_string(lastPlayer) << " wins!" << endl;
}

void Game::end()
{
	// have to draw final state of board,
	// after winning move is made by lastPlayer
	draw();

	announceWinner();
	
	cout << endl;
	cout << "Game over, thanks for playing!" << endl;
	cout << "Press 'Enter' to exit" << endl;
	
	getchar();
}


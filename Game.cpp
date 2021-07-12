#include <iostream>
#include <string>
#include <assert.h>
#include "Game.h"
#include "KeyMap.h"
#include "Board.h"

using namespace std;

Game::Game(string title, int maxPlayers)
	: title(title), maxPlayers(maxPlayers)
{
	assert("" != title);
	assert(maxPlayers > 0);
	players = createPlayers(maxPlayers);
	board = new Board(3, 3);
	keys = new KeyMap();
}

vector<Player*> Game::createPlayers(int numOfPlayers)
{
	int number = 0;
	string symbol = "";
	vector<Player*> vPlayers;
	for (int i = 0; i < numOfPlayers; i++)
	{
		if (0 == i)
		{
			number = 1;
			symbol = "X";
		}
		else
		{
			number = 2;
			symbol = "O";
		}
		Player* p = new Player(number, symbol);
		vPlayers.push_back(p);

		//auto pp = std::addressof(*p);
		//cout << "Created Player " << to_string(number) << " at " << pp << endl;
}

	//getchar();
	return vPlayers;
}

Game::~Game()
{
	delete board;
	delete keys;
}

void Game::start()
{
	currentPlayer = players[0];
	previousPlayer = players[1];

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

void Game::turn()
{
	draw();
	
	try
	{
		if ("" != lastMove)
		{
			cout << "Player " << previousPlayer->number;
			cout << " chose " << lastMove << endl;
		}

		lastMove = getUserInput("Player " + to_string(currentPlayer->number) + ", choose your next move (1 - 9), then press 'Enter'");

		board->update(keys, lastMove, currentPlayer);
		draw();
		nextPlayer();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		lastMove = ""; // because last move was invalid
		getchar();
	}
}

void Game::nextPlayer()
{
	if (1 == maxPlayers)
	{
		currentPlayer = players[0];
	}
	if (2 == maxPlayers)
	{
		if (1 == currentPlayer->number)
		{
			currentPlayer = players[1];
			previousPlayer = players[0];
		}
		else if (2 == currentPlayer->number)
		{
			currentPlayer = players[0];
			previousPlayer = players[1];
		}
	}
	else
	{
		// TODO: use vector iterator and support any number of players?
	}
}

void Game::draw()
{
	clear();
	cout << endl;
	cout << title << endl;
	cout << endl;
	cout << "Each square on the board corresponds to the numbers on your keyboard's numpad." << endl;

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

bool Game::isTied()
{
	return !board->hasOpenSquares();
}

// lastPlayer made the winning move
void Game::announceWinner()
{
	if (isTied())
	{
		cout << endl;
		cout << "Tie game, no winner!" << endl;
	}
	else
	{
		cout << endl;
		cout << "Player " << to_string(previousPlayer->number) << " wins!" << endl;
	}
}

void Game::end()
{
	// have to draw final state of board,
	// after winning move is made by lastPlayer
	draw();

	announceWinner();
	
	cout << endl;
	cout << "Game over" << endl;
	cout << "Press 'Enter' to exit" << endl;
	
	getchar();
}


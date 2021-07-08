#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "KeyMap.h"
#include "Board.h"

using namespace std;

class Game
{
private:
	string title;
	int maxPlayers;
	string lastMove;
	int currentPlayer;
	int lastPlayer;
	string lastError;

	Board* board;
	KeyMap* keys;

public:
	Game(string, int);
	~Game();
	void start();
	string getUserInput(string);
	void turn();
	void nextPlayer();
	void draw();
	void clear();
	bool hasWinner();
	void announceWinner();
	void end();
};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Board.h"
#include "KeyMap.h"

using namespace std;

class Game
{
private:
	string title = "";
	int maxPlayers = 1;
	string lastMove = "";
	Player* currentPlayer;
	Player* previousPlayer;

	vector<Player*> players;
	Board* board;
	KeyMap* keys;

	vector<Player*> createPlayers(int);

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
	bool isTied();
	void announceWinner();
	void end();
};


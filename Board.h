#pragma once
#include <vector>
#include "KeyMap.h"
#include "Player.h"

using namespace std;

class Board
{
private:
	int columns = 1;
	int rows = 1;
	vector<vector<string>> square;

	bool checkHorizontalWinner(string);
	bool checkVerticalWinner(string);
	bool checkDiagonalWinner(string);

public:
	Board(int, int);
	~Board();

	void draw();
	void update(KeyMap*, string, Player*);
	bool checkWinner(string);
	bool squareIsOpen(string);
	bool hasOpenSquares();
};


#pragma once
#include <vector>
#include "KeyMap.h"

using namespace std;

class Board
{
private:
	int columns;
	int rows;
	vector<vector<string>> square;

	bool checkHorizontalWinner(string);
	bool checkVerticalWinner(string);
	bool checkDiagonalWinner(string);

public:
	Board(int, int);
	~Board();

	void draw();
	bool update(KeyMap*, string, int);
	bool checkWinner(string);
	bool squareIsOpen(string);
};


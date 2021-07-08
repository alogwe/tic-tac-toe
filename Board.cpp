#include <iostream>
#include <string>
#include "Board.h"
#include "KeyMap.h"

using namespace std;


bool Board::checkHorizontalWinner(string symbol)
{
	return 
		(symbol == square[0][0]
			&& symbol == square[0][1]
			&& symbol == square[0][2])
		||
		(symbol == square[1][0]
			&& symbol == square[1][1]
			&& symbol == square[1][2])
		||
		(symbol == square[2][0]
			&& symbol == square[2][1]
			&& symbol == square[2][2]);
}


bool Board::checkVerticalWinner(string symbol)
{
	return
		(symbol == square[0][0]
			&& symbol == square[1][0]
			&& symbol == square[2][0])
		||
		(symbol == square[0][1]
			&& symbol == square[1][1]
			&& symbol == square[2][1])
		||
		(symbol == square[0][2]
			&& symbol == square[1][2]
			&& symbol == square[2][2]);
}


bool Board::checkDiagonalWinner(string symbol)
{
	return
		(symbol == square[0][0]
			&& symbol == square[1][1]
			&& symbol == square[2][2])
		||
		(symbol == square[0][2]
			&& symbol == square[1][1]
			&& symbol == square[2][0]);
}


Board::Board(int columns, int rows) :
	columns(columns), rows(rows)
{
	string defaultValue = " ";
	for (int r = 0; r < rows; r++)
	{
		vector<string> row;
		for (int c = 0; c < columns; c++)
		{
			row.push_back(defaultValue);
		}
		square.push_back(row);
	}
}


Board::~Board()
{
}


void Board::draw()
{
	cout << endl;
	cout << "[ " << square[0][0] << " ][ " << square[0][1] << " ][ " << square[0][2] << " ]" << endl;
	cout << "[ " << square[1][0] << " ][ " << square[1][1] << " ][ " << square[1][2] << " ]" << endl;
	cout << "[ " << square[2][0] << " ][ " << square[2][1] << " ][ " << square[2][2] << " ]" << endl;
	cout << endl;
}


bool Board::update(KeyMap* keys, string move, int player)
{
	string symbol;
	bool updateSuccessful = true;

	if (1 == player)
	{
		symbol = "X";
	}
	else
	{
		symbol = "O";
	}

	if (keys->BOTTOM_LEFT == move && squareIsOpen(square[2][0]))
	{
		square[2][0] = symbol;
	}
	else if (keys->BOTTOM_MIDDLE == move && squareIsOpen(square[2][1]))
	{
		square[2][1] = symbol;
	}
	else if (keys->BOTTOM_RIGHT == move && squareIsOpen(square[2][2]))
	{
		square[2][2] = symbol;
	}
	else if (keys->MIDDLE_LEFT == move && squareIsOpen(square[1][0]))
	{
		square[1][0] = symbol;
	}
	else if (keys->MIDDLE_MIDDLE == move && squareIsOpen(square[1][1]))
	{
		square[1][1] = symbol;
	}
	else if (keys->MIDDLE_RIGHT == move && squareIsOpen(square[1][2]))
	{
		square[1][2] = symbol;
	}
	else if (keys->TOP_LEFT == move && squareIsOpen(square[0][0]))
	{
		square[0][0] = symbol;
	}
	else if (keys->TOP_MIDDLE == move && squareIsOpen(square[0][1]))
	{
		square[0][1] = symbol;
	}
	else if (keys->TOP_RIGHT == move && squareIsOpen(square[0][2]))
	{
		square[0][2] = symbol;
	}
	else
	{
		// TODO: properly handle
		updateSuccessful = false;
		cout << "Invalid choice." << endl;
		getchar();
	}

	return updateSuccessful;
}


bool Board::checkWinner(string symbol)
{
	return checkHorizontalWinner(symbol) 
		|| checkVerticalWinner(symbol) 
		|| checkDiagonalWinner(symbol);
}


bool Board::squareIsOpen(string squareValue)
{
	return squareValue == " " || squareValue == "";
}
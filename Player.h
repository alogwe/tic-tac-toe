#pragma once
#include <string>

using namespace std;

struct Player
{
	int number = 0;
	string symbol = "";
	Player(int, string);
	~Player();
};


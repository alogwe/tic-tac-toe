#pragma once
#include <string>

using namespace std;

class KeyMap
{
private:
public:
	// "\n" is automatically a delimiter for std::getline,
	// so no input means that Enter key was only key that was pressed
	//const string ENTER_ONLY = "";
	
	const string BOTTOM_LEFT = "1";
	const string BOTTOM_MIDDLE = "2";
	const string BOTTOM_RIGHT = "3";
	const string MIDDLE_LEFT = "4";
	const string MIDDLE_MIDDLE = "5";
	const string MIDDLE_RIGHT = "6";
	const string TOP_LEFT = "7";
	const string TOP_MIDDLE = "8";
	const string TOP_RIGHT = "9";

	KeyMap();
	~KeyMap();

	bool isValidKey(string input, string keyCode);
};


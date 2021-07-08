#include "KeyMap.h"


KeyMap::KeyMap()
{
}


KeyMap::~KeyMap()
{
}


bool KeyMap::isValidKey(string input, string keyCode)
{
	return input == keyCode
		|| input == BOTTOM_LEFT
		|| input == BOTTOM_MIDDLE
		|| input == BOTTOM_RIGHT
		|| input == MIDDLE_LEFT
		|| input == MIDDLE_MIDDLE
		|| input == MIDDLE_RIGHT
		|| input == TOP_LEFT
		|| input == TOP_MIDDLE
		|| input == TOP_RIGHT;
}
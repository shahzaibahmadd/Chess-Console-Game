#include "player.h"

player::player(string _n, color _c)
{
	this->name = _n;
	this->C = _c;
}

string player::getname()
{
	return name;
}

color player::getcolor()
{
	return C;
}



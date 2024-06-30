#pragma once
#include <string>

using namespace std;
#include"Header.h"
class player
{
	string name;
	color C;

public :

	player(string _n, color _c);
	string getname();
	color getcolor();

};


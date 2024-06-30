#pragma once
#include <iostream>
#include<Windows.h>

using namespace std;

enum color{BLACK,WHITE=15};
#define BROWN 6
#define GREEN 2
#define RED 4
#define LBLUE 9


void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
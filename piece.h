#pragma once
#include "Header.h"
 


class  board;


class piece
{
protected:
	int ri, ci;
	color C;
	board* b;
	bool firstMove = false;

public:
	piece(int _r, int _c, color _C,board* _b);
	virtual void draw() = 0;
	void move(int _r, int _c);
	color getcolor();
	virtual bool isLegalMove(int sri, int sci, int dri, int dci)=0;
	bool& FirstMove();


};
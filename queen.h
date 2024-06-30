#pragma once
#include"piece.h"

class queen:public piece
{
public:
	queen(int _r, int _c, color _C, board* b);
	 void draw();
	 bool isLegalMove(int sri, int sci, int dri, int dci);

};


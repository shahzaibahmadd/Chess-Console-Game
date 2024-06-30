#pragma once
#include"piece.h"

class rook :public piece
{
public:
	rook(int _r, int _c, color _C, board* b);
	 void draw();
	 bool isLegalMove(int sri, int sci, int dri, int dci);
};


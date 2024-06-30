#pragma once
#include"piece.h"


class pawn :public piece
{
public:
	pawn(int _r, int _c, color _C, board* b);
	 void draw();
	//bool isvalid(int sri, int sci, int dri, int dci, piece* cb[][8]);
	 //bool isLegalMove(int _r, int _c);
	 //bool isvalid(int sri, int sci, int dri, int dci, piece* cb[][8]);
	 bool isLegalMove(int sri, int sci, int dri, int dci);

};

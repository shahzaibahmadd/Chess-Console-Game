#include"piece.h"

piece::piece(int _r, int _c, color _C,board* _b)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->b = _b;
}

void piece::move(int _r, int _c)
{
	this->ri = _r;
	this->ci = _c;
}
color piece::getcolor()
{
	return C;
}

//bool& piece::FirstMove()
//{
//	return firstMove;
//}
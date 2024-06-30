#include "rook.h"
#include"board.h"
#include<iostream>
using namespace std;
rook::rook(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void rook::draw()
{
	cout << ((C == WHITE) ? 'R' : 'r');
}

bool rook::isLegalMove(int sri, int sci, int dri, int dci)
{
	return ((b->ishorizontalmove(sri,dri) && b->isHorizontalPathClear(sri, sci, dri, dci))
		|| (b->isverticalmove(sci,dci) && b->isverticalpathclear(sri, sci, dri, dci)));
}
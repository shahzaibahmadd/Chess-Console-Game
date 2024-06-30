#include "queen.h"
#include"board.h"

#include<iostream>
using namespace std;
queen::queen(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void queen::draw()
{
	cout << ((C == WHITE) ? 'Q' : 'q');
}


bool queen::isLegalMove(int sri, int sci, int dri, int dci)
{
	return ((b->ishorizontalmove(sri, dri) && b->isHorizontalPathClear(sri, sci, dri, dci))|| (b->isverticalmove(sci,dci) && b->isverticalpathclear(sri, sci, dri, dci))
		|| (b->isdiagnolmove(sri, sci, dri, dci) && b->isdiagonalpathclear(sri, sci, dri, dci)));
}

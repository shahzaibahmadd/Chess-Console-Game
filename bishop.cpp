#include "bishop.h"
#include"board.h"
#include<iostream>
using namespace std;
bishop::bishop(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void bishop::draw()
{
	cout << ((C == WHITE) ? 'B' : 'b');
}
bool bishop::isLegalMove(int sri,int sci,int dri,int dci)
{
	return (b->isdiagonalpathclear(sri, sci,  dri,  dci) && b->isdiagnolmove(sri,sci, dri,dci));
}
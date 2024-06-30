#include "king.h"
#include<iostream>
#include"board.h"

using namespace std;
king::king(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void king::draw()
{
	cout << ((C == WHITE) ? 'K' : 'k');
}
//bool king::isLegalMove(int _r, int _c)
//{
//	if (b->getPiece(_c) != nullptr && m_B->getPiece(Dest)->AmIKing())
//		return false;
//
//
//	if (abs(m_pos.ri - Dest.ri) == 1 || abs(m_pos.ci - Dest.ci) == 1)
//	{
//		return ((isVertical(m_pos, Dest) && isVerticalPathClear(m_pos, Dest))
//			|| (isHorizontal(m_pos, Dest) && isVerticalPathClear(m_pos, Dest))
//			|| (isDiagonal(m_pos, Dest) && isDiagonalPathClear(m_pos, Dest)));
//	}
//	return false;
//
//}
//bool King::AmIKing()
//{
//	return true;
//}
bool king::isLegalMove(int sri, int sci, int dri, int dci)
{

	int r = abs(sri - dri);
	int c = abs(sci - dci);
	return (((b->ishorizontalmove(sri, dri) && b->isHorizontalPathClear(sri, sci, dri, dci))
		|| (b->isverticalmove(sci, dci) && b->isverticalpathclear(sri, sci, dri, dci))) ||
		(b->isdiagonalpathclear(sri, sci, dri, dci) && b->isdiagnolmove(sri, sci, dri, dci)) && ((r <= 1) && (c <= 1)));
}
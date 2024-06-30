#include "pawn.h"
#include<iostream>
using namespace std;
#include"board.h"

pawn::pawn(int _r, int _c,color _C,board* _b)
	         :piece(_r,_c,_C,_b)
{
	firstMove = true;

}
void pawn:: draw()
 {
	cout << ((C == WHITE) ? 'P' : 'p');
 }
//bool pawn:: isvalid(int sri, int sci, int dri, int dci, piece* cb[][8])
//{
//    int dr = (C == WHITE) ? -1 : 1;
//    if (dci == sci && cb[dri][dci] == nullptr) {
//        if (sri == dri + dr)
//            return true;
//        if ((C == WHITE && sri == 6 && dri == 4) || (C == BLACK && sri == 1 && dri == 3))
//            return true;
//    }
//    else if (abs(dci - sci) == 1 && cb[dri][dci] != nullptr && cb[dri][dci]->getcolor() != C) {
//        if (sri == dri + dr)
//            return true;
//    }
//    return false;
//}
//bool pawn::isLegalMove(int _r,int _c)
//{
//	int one = 1, two = 1;
//	if (firstMove)
//		two++;
//
//	if (m_color == BLACK)
//	{
//		one = -one;
//		two = -two;
//	}
//
//	// CHECKING DIAGONAL FOR ENEMY PIECE SO IT CAN BE KILLED!!
//	if ((m_pos.ri - Dest.ri) == one && abs(m_pos.ci - Dest.ci) == 1)
//	{
//		if (m_B->getPiece(Dest) != nullptr && m_B->getPiece(Dest)->getColor() != m_color)
//		{
//			return true;
//		}
//	}
//
//	//CHECKING THE VALIDATION OF VERTICAL MOVEMENT
//	if (m_pos.ci == Dest.ci && ((m_pos.ri - Dest.ri) == one || (m_pos.ri - Dest.ri) == two) &&
//		(m_B->getPiece(Dest) == nullptr) && isVerticalPathClear(m_pos, Dest))
//	{
//		return true;
//	}
//	return false;
//}
//bool Pawn::AmIPawn()
//{
//	return true;
//}
//bool pawn::isvalid(int sri, int sci, int dri, int dci, piece* cb[][8]) 
//{
//	int dr = (c == WHITE) ? -1 : 1;
//	if (dci == sci && cb[dri][dci] == nullptr) {
//		if (sri == dri + dr)
//			return true;
//		if ((c == WHITE && sri == 6 && dri == 4) || (c == BLACK && sri == 1 && dri == 3))
//			return true;
//	}
//	else if (abs(dci - sci) == 1 && cb[dri][dci] != nullptr && cb[dri][dci]->getcolor() != c) {
//		if (sri == dri + dr)
//			return true;
//	}
//	return false;
//}
bool pawn::isLegalMove(int sri, int sci, int dri, int dci)
{
	
	int r = ((C == WHITE) ? dri - sri : sri - dri);
	int c = (sci - dci);
	return b->isverticalmove(sci, dci) && b->isverticalpathclear(sri, sci, dri, dci) && r == 1 && c == 0;


}

















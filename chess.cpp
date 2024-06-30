#include "chess.h"
#include <vector>
#include"player.h"
#include<iostream>
#include <time.h>
#include<string>
#include"board.h"
#include"piece.h"
#include"Header.h"
#include "king.h"
using namespace std;
chess::chess()
{

	ps[0] = new player("shahzaib", BLACK);
	ps[1] = new player("YOU", WHITE);
	
	
	b = new	board();
	naqli = new board();
	srand(time(0));
	turn = 0;
}
void chess::displayturnmsg(player* AP)
{
    cout << AP->getname() << "'s turn";
}

void chess::selectpositionfrom()
 {
    gotoRowCol(0, 50);

    cout << "select piece";
    
    getRowColbyLeftClick(sri, sci);
    sri /= 3;
    sci /= 3;



}
void chess::selectpositionyto()
{
    gotoRowCol(0, 50);

    cout << "drop piece" << "  ";
    

    getRowColbyLeftClick(dri, dci);
    dri /= 3;
    dci /= 3;

}
bool chess::validsourceselection(player* AP, int r, int c)
{
    if (r < 0 || r >= 8 || c < 0 || c >= 8)
        return false;
    piece* p = b->getpieceat(r, c);
    return p != nullptr && p->getcolor() == AP->getcolor();
}
bool  chess:: validdestselection(player* AP, int r, int c)
{
    if (r < 0 || r >= 8 || c < 0 || c >= 8)
        return false;

    piece* p = b->getpieceat(r, c);
    return p == nullptr || p->getcolor() != AP->getcolor();

}
void chess::move(int sri,int sci, int dri,int dci,board* a)
{
    piece* p = a->getpieceat(sri, sci);
    a->setpieceat(dri, dci, p);
    a->setpieceat(sri, sci, nullptr);
}
void chess:: turnchange()
{
    turn = (turn + 1) % 2;
}








bool** chess::computehighlight(int sri, int sci, int dri, int dci)
{
	int dim = 8;
	bool** bmap = new bool* [dim];
	for (int b = 0; b < dim; b++)
	{
		bmap[b] = new bool[dim] {};
	}
	/*position dc;*/
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			dri = ri;
			dci = ci;
			if (validdestselection(ps[turn],dri,dci) && b->getpieceat(sri,sci)->isLegalMove(sri,sci,dri,dci))
			{
				bmap[ri][ci] = true;
			}
			else
			{
				bmap[ri][ci] = false;
			}
		}
	}
	return bmap;
}
void chess::boxhighlight(int sri, int sci, int brows, int bcols)
{
	int clr = 3;
	SetClr(3);
	for (int r = 0; r < brows; r++)
	{
		for (int c = 0; c < bcols; c++)
		{
			if (r == 0 || c == 0 || r == brows - 1 || c == bcols - 1)
			{
				gotoRowCol(sri + r, sci + c);
				cout << char(-37);
			}
		}
	}
}
void chess::highlightboard(int sri, int sci, int dri, int dci,bool**& bmap)
{
	bmap = computehighlight( sri, sci, dri,  dci);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (bmap[i][j] == true)
			{
				boxhighlight(i * 3, j * 3, 3, 3);
			}


		}
	}
}


void chess::unhighlightboard(bool**& bmap)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (bmap[i][j] == true)
			{
				if (i + j % 2 == 0)
				{
					b->drawbox(i * 3, i * 3,3, 3, 15);
					/*gotoRowCol(i * 3 + 3 / 2, i * 3 + 3 / 2);

					cout << b[i][i];*/

				}
				else
				{
					b->drawbox(i * 3, i * 3, 3, 3, 15);
					gotoRowCol(i * 3+ 3 / 2, i * 3 + 3 / 2);

					/*cout << b[i][i];*/
				}
			}


		}
	}
}

void chess::findking(int& dri,int& dci,int turn,board*a)
{


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
	/*		if (turn == WHITE)
			{
				if (ps[i][j] == 'k')
					dri = i, dci = j;
				
			}
			if (turn == BLACK)
			{
				if (ps[i][j] == 'K')
					dri = i, dci = j;
			}
	*/
			piece* p = a->getpieceat(i, j);
			if (dynamic_cast<king*>(p) != nullptr && dynamic_cast<king*>(p)->getcolor() == ps[turn]->getcolor())
			{
				dri = i;
				dci = j;
				return;

			}
		
		}

	}
	//return dc;
	

}
bool chess::check(int sri,int sci,int dri,int dci,int turn,board* a)
{
	/*position dc;
	position sc;*/
	/*turnf(turn);*/
	/*dc = */findking(dri,dci, turn,a);
	/*turnf(turn);*/
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			sri = ri, sci = ci;
			if (validsourceselection((ps[(turn+1)%2]), sri, sci) && a->getpieceat(sri, sci)->isLegalMove(sri, sci, dri, dci))
				return true;


		}
	}
	return false;
}
bool chess::selfcheck(int sri, int sci, int dri, int dci, int t, board* a)
{

	return check(sri,sci,dri,dci,t, a);
}






void chess::play()
{

	bool** bmap;
    b->drawboard(8, 3, 3, 15);
    b->displayboard();
    
    while (true)
	{
		do
		{
			do
			{
				cout << "\n\n";
				gotoRowCol(0, 100);
				cout << "                  ";
				gotoRowCol(0, 100);
				displayturnmsg(ps[turn]);
				do
				{
					do
					{
						selectpositionfrom();
					} while (!validsourceselection(ps[turn], sri, sci));
					highlightboard(sri, sci, dri, dci, bmap);
					selectpositionyto();

				} while (!validdestselection(ps[turn], dri, dci));
				unhighlightboard(bmap);
				b->displayboard();
			} while (!b->getpieceat(sri, sci)->isLegalMove(sri, sci, dri, dci));
			naqli->copyboard(b);
			move(sri, sci, dri, dci,naqli);
		} while (selfcheck(sri, sci, dri, dci, turn,naqli));
		if (check(sri, sci, dri, dci, turn, naqli)==true)
		{
			gotoRowCol(20, 60);
			cout << "king in check,pls move king";
			}
		move(sri, sci, dri, dci,b);
			
			b->drawboard(8, 3, 3, 15);
			b->displayboard();
			turnchange();
	}
	

}


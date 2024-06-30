#include "board.h"
#include"piece.h"
#include "pawn.h"
#include"bishop.h"
#include"horse.h"
#include"king.h"
#include"queen.h"
#include"rook.h"
#include"chess.h"
board::board()
{
	ps = new piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		ps[r] = new piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (r == 1)
			{
				ps[r][c] = new pawn(r, c, WHITE, this);
			}
			else if (r == 6)
			{
				ps[r][c] = new pawn(r, c, BLACK, this);
			}
			else if ((r == 0 && c == 0) || (r == 0 && c == 7))
			{
				ps[r][c] = new rook(r, c, WHITE, this);
			}
			else if ((r == 7 && c == 0) || (r == 7 && c == 7))
			{
				ps[r][c] = new rook(r, c, BLACK, this);
			}
			else if ((r == 0 && c == 1) || (r == 0 && c == 6))
			{
				ps[r][c] = new bishop(r, c, WHITE, this);
			}
			else if ((r == 7 && c == 1) || (r == 7 && c == 6))
			{
				ps[r][c] = new bishop(r, c, BLACK, this);
			}
			else if ((r == 0 && c == 2) || (r == 0 && c == 5))
			{
				ps[r][c] = new horse(r, c, WHITE, this);
			}
			else if ((r == 7 && c == 2) || (r == 7 && c == 5))
			{
				ps[r][c] = new horse(r, c, BLACK, this);
			}
			else if (r == 0 && c == 3)
			{
				ps[r][c] = new queen(r, c, WHITE, this);
			}
			else if ((r == 7 && c == 4))
			{
				ps[r][c] = new queen(r, c, BLACK, this);
			}
			else if (r == 0 && c == 4)
			{
				ps[r][c] = new king(r, c, WHITE, this);
			}
			else if ((r == 7 && c == 3))
			{
				ps[r][c] = new king(r, c, BLACK, this);
			}
			else
			{
				ps[r][c] = nullptr;
			}
		}
	}
}
void board::drawbox(int sr, int sc, int  brows, int bcols, int col)
{
	for (int r = 0; r < brows; r++)
	{
		for (int c = 0; c < bcols; c++)
		{
			SetClr(col);
			gotoRowCol(sr + r, sc + c);
			cout << char(-37);
		}
	}

}
void board::drawboard(int dim, int brows, int bcols, int color)
{
	for (int ri = 0; ri < dim; ri++)
	
	{	for (int ci = 0; ci < dim; ci++)
		{
			if ((ri + ci) % 2 == 0)
			{
				drawbox(ri * brows, ci * bcols, brows, bcols, 15);

			}
			else
			{
				drawbox(ri * brows, ci * bcols, brows, bcols, 6);
			}
		}
	}
}
void board :: displayboard()
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (ps[r][c] == nullptr)
			{
				gotoRowCol(r * 3 + 3 / 2, c * 3 + 3 / 2);
				cout << "-";
			}
			else
			{
				gotoRowCol(r * 3 + 3 / 2, c * 3 + 3 / 2);
				ps[r][c]->draw();
			}

		}
		cout << endl;
	}
}
piece* board::getpieceat(int r, int c)
{
	return ps[r][c];
}
piece* board::setpieceat(int r, int c, piece* p)
{
	return ps[r][c] = p;
}
bool board::ishorizontalmove(int sri, int dri)
{
	return sri == dri;

}
bool board::isverticalmove(int sci, int dci)
{
	return sci == dci;

}
bool board::isdiagnolmove(int sri, int sci, int dri, int dci)
{
	int r = abs(sri - dri);
	int c = abs(sci - dci);
	return r == c;
}
bool board::isHorizontalPathClear(int sri, int sci, int dri, int dci)
{
	if (dci > sci)
	{
		for (int i = sci + 1; i < dci; i++)
		{
			if (ps[sri][i] != nullptr)
				return false;
		}
		return true;
	}
	if (dci < sci)
	{
		for (int i = sci - 1; i >= dci; i--)
		{
			if (ps[sri][i] !=nullptr)
				return false;
		}
	}
}
bool board::isverticalpathclear(int sri,int sci,int dri,int dci)
{
	if (sri < dri)
	{
		for (int i = sri + 1; i < dri; i++)
		{
			if (ps[i][sci] !=nullptr)
			{
				return false;
			}
		}
		return true;
	}
	if (sri > dri)
	{
		for (int i = sri - 1; i > dri; i--)
		{
			if (ps[i][sci] != nullptr)
			{
				return false;
			}
		}
	}   return true;
}

bool board:: isdiagonalpathclear(int sri,int sci,int dri,int dci)
{
	int x, y;
	x = abs(sri - dri);
	y = abs(sci - dci);

	//top left
	if (sri > dri && sci > dci)
	{
		for (int a = 1; a < x; a++)
		{
			if (ps[sri - a][sci - a] != nullptr)
			{
				return false;
			}
			
		}
		return true;
	}
	//bottom right
	if (sri < dri && sci < dci)
	{
		for (int a = 1; a < x; a++)
		{
			if (ps[sri + a][sci + a] != nullptr)
			{
				return false;
			}
			
		}
		return true;
	}
	//bottom left
	if (sri<dri && sci>dci)
	{
		for (int a = 1; a < x; a++)
		{
			if (ps[sri + a][sci - a] != nullptr)
			{
				return false;
			}
			
		}
		return true;
	}
	//top right
	if (sri > dri && sci < dci)
	{
		for (int a = 1; a < x; a++)
		{
			if (ps[sri - a][sci + a] != nullptr)
			{
				return false;
			}
			
		}
		return true;
	}
}



void board::copyboard(board* a)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ps[i][j] = a->ps[i][j];
		}

	}

}














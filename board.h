#pragma once
class piece;

class board
{
	piece* ** ps;

public:
	board();
	void displayboard();
	piece* getpieceat(int r, int c);
	piece* setpieceat(int r, int c, piece* p);
	void drawbox(int sr, int sc, int  brows, int bcols, int col);
	void drawboard(int dim, int brows, int bcols, int color);

	bool ishorizontalmove(int sri, int dri);
	bool isverticalmove(int sci, int dci);
	bool isdiagnolmove(int sri, int sci, int dri, int dci);
	bool isHorizontalPathClear(int sri, int sci, int dri, int dci);
	bool isverticalpathclear(int sri, int sci, int dri, int dci);

	bool isdiagonalpathclear(int sri, int sci, int dci, int dri);
	void copyboard(board* a);


};


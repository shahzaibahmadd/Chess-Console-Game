#pragma once
class piece;
class board;
class player;
class chess
{
	int sri, sci, dri, dci;
	int turn;
	player* ps[2];
	board* b;
	board* naqli;


public:
	chess();
	void play();
	void displayturnmsg(player* AP);
	bool validsourceselection(player* AP, int r, int c);
	bool validdestselection(player* AP, int r, int c);
	void move(int sri, int sci, int  dri, int dci,board* a);
	void updateboard();
	void selectpositionfrom();
	void selectpositionyto();
	void turnchange();


	bool** computehighlight(int sri, int sci, int dri, int dci);
	void boxhighlight(int sri, int sci, int brows, int bcols);
	void highlightboard(int sri, int sci, int dri, int dci, bool**& bmap);


	void unhighlightboard(bool**& bmap);

	void findking(int& dri, int& dci, int turn,board* a);
	bool check(int sri, int sci, int dri, int dci, int turn, board* a);
	bool selfcheck(int sri, int sci, int dri, int dci, int turn, board* a);



};
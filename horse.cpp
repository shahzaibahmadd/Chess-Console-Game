#include "horse.h"
#include<iostream>
using namespace std;
horse::horse(int _r, int _c, color _C, board* _b)
	:piece(_r, _c, _C, _b)
{

}
void horse::draw()
{
	cout << ((C == WHITE) ? 'H' : 'h');
}
bool horse::isLegalMove(int sri, int sci, int dri, int dci)
{

	int r = abs(sri - dri);
	int c = abs(sci - dci);
	return (r == 2 && c == 1);
}

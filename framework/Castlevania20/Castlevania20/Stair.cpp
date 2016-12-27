#include "Stair.h"

Stair::Stair(int x, int y, int type, int len) {
	this->_x = x;
	this->_y = y;
	this->_Stair_Type = type;
	this->_Lenght = len;
	if (type == 1) {
		inStep = 1;
	}
	else {
		inStep = _Lenght;
	}
}

Stair* Stair::getTair(int x, int y, bool up) {
	x += 15;
	if (up) {
		if (x > STAR1 && x < STAR1 + 32 && y > 1484 && y < 1586) {
			return new Stair(3808, 1552, 1, 8); //tair 1
		}
		if (x > 3727 && x < 3768  && y > 1290 && y < 1380) {
			return new Stair(3742, 1360, 1, 8); //tair 1
		}
		if(x>1616 && x< 1654 && y>859 && y< 930) 
		{
			return new Stair(1632, 914, 1, 4);
		}
		if (x>282 && x< 295 && y>635 && y< 645)
		{
			return new Stair(320, 690, 1, 4);
		}
		if (x>1280 && x< 1300 && y>470 && y< 500)
		{
			return new Stair(1310, 527, 1, 4);
		}
	}
	
	else {
		if (x > 3900 && x < 3932 && y > 1360 && y < 1450) {
			return new Stair(3808, 1552, 1, 8);//tair 1
		}
		if (x>360 && x< 370 && y>580 && y< 590)//
		{
			return new Stair(320, 690, 1, 4);
		}
	}
	return nullptr;//default
}
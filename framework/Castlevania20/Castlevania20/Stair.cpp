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
	}
	
	else {
		if (x > 3900 && x < 3932 && y > 1360 && y < 1450) {
			return new Stair(3808, 1552, 1, 8);//tair 1
		}
	}
	return nullptr;//default
}
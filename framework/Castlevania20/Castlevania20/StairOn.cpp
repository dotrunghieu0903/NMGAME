#include "StairOn.h"


StairOn::StairOn(int id, int x, int y, int w, int h) :BaseObject(TYPE, x, y, w, h) {
	this->_id = id;
	this->_sptrite = new Sprite((new Texture(STAIR_SPITE)), 50);
}

StairOn::StairOn()
{
}

void StairOn::Draw() {
	RECT rect;
	rect.top = this->_y;
	rect.bottom = this->_y + this->_height;
	rect.left = this->_x;
	rect.right = this->_x + this->_width;
	this->_sptrite->DrawRect(_x, _y, rect);
}
StairOn::~StairOn()
{
}

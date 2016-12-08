#include "Ground.h"



Ground::Ground()
{
}

Ground::Ground(int id, int x, int y, int width, int heiht) : BaseObject(TYPE, x, y, width, heiht){
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(GROUND_SPRITE), 10);
}

void Ground::Draw() {
	this->_sptrite->DrawRect(this->_x, this->_y, this->_bound);
}


Ground::~Ground()
{
}

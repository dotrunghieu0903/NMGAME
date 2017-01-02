#include "Ground.h"



Ground::Ground()
{
}

Ground::Ground(int id, int x, int y, int width, int heiht) : BaseObject(TYPE, x, y, width, heiht){
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(GROUND_SPRITE), 10);
}

void Ground::UpdateEvent(float deltatime) {
	tickcount += deltatime;
	if (tickcount > 2000) {
		collission_bot = false;
	}
}

void Ground::Draw() {
	RECT rect;
	rect.top = this->_y;
	rect.bottom = this->_y + this->_height;
	rect.left = this->_x;
	rect.right = this->_x + this->_width;
	this->_sptrite->DrawRect(this->_x, this->_y, rect);
}

Ground::~Ground()
{
}

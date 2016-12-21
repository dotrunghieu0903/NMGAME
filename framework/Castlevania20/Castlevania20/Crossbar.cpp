#include "Crossbar.h"



Crossbar::Crossbar()
{
}

Crossbar::Crossbar(int id, int x, int y, RECT bound) :BaseObject(TYPE, x, y, BAR_WIDTH, BAR_HEIGHT, bound) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(BAR_SPRITE), 1000);
	is_direction_right = true;
	_vx = BAR_SPEED;
}

void Crossbar::MoveUpdate(float deltatime) {
	if (this->_x < this->_bound.left)
	{
		this->is_direction_right = true;
		_vx = BAR_SPEED;
	}
	if (this->_x + this->_width > this->_bound.right) {
		this->is_direction_right = false;
		_vx = -BAR_SPEED;
	}
	UpdatePosition(deltatime);
}


void Crossbar::Draw() {
	this->_sptrite->Draw(_x, _y);
}


Crossbar::~Crossbar()
{
}

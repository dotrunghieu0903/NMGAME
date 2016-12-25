#include "Snake.h"



Snake::Snake()
{
}

Snake::Snake(int x, int y,bool is_left) : BaseObject(TYPE, x, y, SNAKE_WIDTH, SNAKE_HEIGHT){
	this->_sptrite = new Sprite(new Texture(SNAKE_SPRITE,2,1,2), 10);
	this->_vy = 0.3f;
	this->is_left = is_left;
}

void Snake::MoveUpdate(float deltatime) {
	tickcount += deltatime;
	if (tickcount > 2000) {
		is_remove = true;
	}
	if (_y >= 332) {
		_vy = 0;
		_vx = is_left ? -0.3f : 0.3f;
	}
	if (_x >= 416) {
		_vx = 0.0f;
		_vy = 0.3f;
		this->_sptrite->SetFrame(0, 0);
	}
	UpdatePosition(deltatime);
}

void Snake::Draw() {
	if (_vx >= 0.0f) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}


Snake::~Snake()
{
}

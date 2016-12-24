#include "FireBall.h"



FireBall::FireBall()
{
}

FireBall::FireBall(int x, int y,bool is_left) :BaseObject(Other_FireBall, x, y, FIREBALL_WIDTH, FIREBALL_HEIGHT) {
	this->_sptrite = new Sprite(new Texture(FIREBALL_SPRITE),10);
	this->_vy = 0;
	if (is_left) {
		_vx = -FIREBALL_SPEED;
	}
	else {
		_vx = FIREBALL_SPEED;
	}
}

void FireBall::MoveUpdate(float deltatime) {
	tickcount++;
	UpdatePosition(deltatime);
	if (tickcount > 4000) {//4s
		this->is_remove = true;
	}
}

void FireBall::Draw() {
	if (_vx > 0.0f) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}

FireBall::~FireBall()
{
	delete _sptrite->_texture;
	delete _sptrite;
}

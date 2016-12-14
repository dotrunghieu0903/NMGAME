#include "BlackKnight.h"



BlackKnight::BlackKnight()
{
}


BlackKnight::BlackKnight(int id, int x, int y, RECT rect) :BaseObject(TYPE, x, y, KNIGHT_WIDTH, KNIGHT_HEIGHT, rect) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(KNIGHT_SPRITE, 4, 1, 4), 70);
	stage = ENEMY_STAGE::LEFT;//fix to WAIT
}
void BlackKnight::MoveUpdate(float deltatime) {
	if (this->stage == ENEMY_STAGE::RIGHT) {
		_vx = KNIGHT_SPEED;
	}
	else {
		_vx = -KNIGHT_SPEED;
	}
	if (this->_x < this->_bound.left)
	{
		this->stage = ENEMY_STAGE::RIGHT;
	}
	if (this->_x + this->_width > this->_bound.right) {
		this->stage = ENEMY_STAGE::LEFT;
	}
	UpdatePosition(deltatime);
}
void BlackKnight::Draw() {
	if (this->stage == ENEMY_STAGE::RIGHT) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}

BlackKnight::~BlackKnight()
{
}

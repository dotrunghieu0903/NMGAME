#include "BlackKnight.h"



BlackKnight::BlackKnight()
{
}


BlackKnight::BlackKnight(int id, int x, int y, RECT rect) :BaseObject(TYPE, x, y, KNIGHT_WIDTH, KNIGHT_HEIGHT, rect) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(KNIGHT_SPRITE, 4, 1, 4), 70);
	stage = ENEMY_STAGE::LEFT;//fix to WAIT
}

void BlackKnight::UpdateEvent(float deltatime) {
	if (tickcount > 300) {
		this->stage = ENEMY_STAGE::END;
		this->is_remove = true;
	}
	if (this->stage == ENEMY_STAGE::DIE) {
		tickcount += deltatime;
		return;
	}
	if (tickcount > 100) {
		damaged = false;
	}
	if (damaged == true) {
		tickcount += deltatime;
	}
	if (this->heath <= 0) {
		this->stage = ENEMY_STAGE::DIE;
		this->Die();
	}

}

void BlackKnight::MoveUpdate(float deltatime) {
	if (this->stage == ENEMY_STAGE::DIE) {
		return;
	}
	if (this->stage == ENEMY_STAGE::RIGHT) {
		_vx = KNIGHT_SPEED;
	}
	else {
		_vx = -KNIGHT_SPEED;
	}
	if (damaged == true) {
		_vx = 0;
		
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

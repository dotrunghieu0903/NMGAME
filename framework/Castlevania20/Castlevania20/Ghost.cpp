#include "Ghost.h"



Ghost::Ghost()
{
}


Ghost::Ghost(int x, int y, RECT bound) : BaseObject(TYPE, x, y, GHOST_WIDTH, GHOST_HEIGHT, bound)
{
	this->_sptrite = new Sprite(new Texture(GHOST_SPRITE, 2, 1, 2), 70);
	stage = STATEGHOST::LEFT;//fix to WAIT
}

void Ghost::Draw() {
	if (this->stage == STATEGHOST::RIGHT) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}

void Ghost::MoveUpdate(float deltatime) {
	if (this->stage == STATEGHOST::RIGHT) {
		_vx = GHOST_SPEED;
	}
	else {
		_vx = -GHOST_SPEED;
	}
	UpdatePosition(deltatime);
}

Ghost::~Ghost()
{
}

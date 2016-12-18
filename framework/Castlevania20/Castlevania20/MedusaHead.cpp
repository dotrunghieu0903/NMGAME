#include "MedusaHead.h"



MedusaHead::MedusaHead()
{
}


MedusaHead::MedusaHead(int id, int x, int y, RECT rect) :BaseObject(TYPE, x, y, MEDUSAHEAD_WIDTH, MEDUSAHEAD_HEIGHT, rect) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(MEDUSAHEAD_SPRITE, 2, 1, 2), 100);
	stage = ENEMY_STAGE::RIGHT;//fix to WAIT
	this->heath = 50;
}

void MedusaHead::MoveUpdate(float deltatime)
{

	if (this->stage == ENEMY_STAGE::DIE) {
		UpdatePosition(deltatime);
		return;
	}

	count++;
	_vy = (float)cos((double)count / 15)*0.35f;
	

	if (this->stage == ENEMY_STAGE::RIGHT) {
		_vx = MEDUSAHEAD_SPEED;
	}
	else {
		_vx = -MEDUSAHEAD_SPEED;
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

void MedusaHead::UpdateEvent(float deltatime) {
	if (this->heath <= 0) {
		this->stage = ENEMY_STAGE::DIE;
		this->Die();
	}
}

void MedusaHead::Draw() {
	if (this->stage == ENEMY_STAGE::RIGHT) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}


MedusaHead::~MedusaHead()
{
}

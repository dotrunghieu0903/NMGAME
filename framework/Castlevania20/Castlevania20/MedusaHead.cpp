#include "MedusaHead.h"



MedusaHead::MedusaHead()
{
}


MedusaHead::MedusaHead(int id, int x, int y, bool is_left) :BaseObject(TYPE, x, y, MEDUSAHEAD_WIDTH, MEDUSAHEAD_HEIGHT) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(MEDUSAHEAD_SPRITE, 2, 1, 2), 100);
	state = ENEMY_STAGE::WAIT;//fix to WAIT
	this->p_x = x;
	this->p_y = y;
	this->is_left = is_left;
	if (p_y < 0) {
		int a = 0;
	}
	this->heath = 1;
}

void MedusaHead::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	if (p_y < 0) {
		p_y = _y;
	}
	tickcount += deltatime;
	if (tickcount >= 3000) {
		this->reborn(simon_x < p_x);
		tickcount = 0;
	}
	
	if (heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		this->Die();
		timedie += deltatime;
	}

	switch (state)
	{
	case WAIT:
		if ((simon_x - p_x >  230 && simon_x - p_x <  500 && !is_left) ||( p_x - simon_x >  230 && p_x - simon_x <  500 && is_left) && simon_y  < p_y + 100 && simon_y > p_y - 100) {
			if (simon_x > p_x + _width) {
				state = ENEMY_STAGE::RIGHT;
				_vx = MEDUSAHEAD_SPEED;
			}
			if (simon_x + 40 < p_x) {
				state = ENEMY_STAGE::LEFT;
				_vx = -MEDUSAHEAD_SPEED;
			}
		}
		else {
			this->is_remove = true;
			_x = 0;
			_y = 0;
		}
		break;
	case DIE:
		timedie += deltatime;
		if (timedie > 300)
		{
			is_remove = true;
			timedie = 0;
		}
		break;
	case END:
		break;
	default:
		count++;
		_vy = (float)cos((double)count / 15)*0.2f;
		if (_x - simon_x > 230) {
			//_vx *= -1;
		}
		break;
	}

	if (this->state == ENEMY_STAGE::DIE) {
		UpdatePosition(deltatime);
		return;
	}
	
	

	UpdatePosition(deltatime);
}


void MedusaHead::reborn(bool is_left) {
	this->damaged = false;
	this->_x = p_x;
	this->_y = p_y;
	this->heath = 1;
	is_remove = false;
	state = ENEMY_STAGE::WAIT;
	this->_sptrite = new Sprite(new Texture(MEDUSAHEAD_SPRITE, 2, 1, 2), 100);
}


void MedusaHead::Draw() {
	if (_vx > 0) {
		this->state == ENEMY_STAGE::RIGHT;
	}
	else {
		this->state == ENEMY_STAGE::LEFT;
	}
	if (!is_remove) {
		if (this->state == ENEMY_STAGE::RIGHT) {
			this->_sptrite->DrawFlipX(_x, _y);
		}
		else {
			this->_sptrite->Draw(_x, _y);
		}
	}
}


MedusaHead::~MedusaHead()
{
}

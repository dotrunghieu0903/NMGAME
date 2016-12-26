#include "Ghost.h"



Ghost::Ghost()
{
}


Ghost::Ghost(int id, int x, int y) : BaseObject(TYPE, x, y, GHOST_WIDTH, GHOST_HEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(GHOST_SPRITE, 2, 1, 2), 70);
	stage = ENEMY_STAGE::WAIT;//fix to WAIT
}

void Ghost::Draw() {
	if (stage != ENEMY_STAGE::WAIT) {
		if (this->_vx > 0.0f) {
			stage = ENEMY_STAGE::RIGHT;
		}
		if (this->_vx < 0.0f) {
			stage = ENEMY_STAGE::LEFT;
		}

		if (stage == ENEMY_STAGE::RIGHT) {
			this->_sptrite->DrawFlipX(_x, _y);
		}
		else {
			this->_sptrite->Draw(_x, _y);
		}
	}
}

Box Ghost::getBox() {
	if (stage == ENEMY_STAGE::WAIT) {
		return Box();
	} else
	return Box(this->_x, this->_y, this->_width, this->_height, _vx, _vy);
}

void Ghost::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	if (this->heath <= 0) {
		this->stage = ENEMY_STAGE::DIE;
		this->Die();
	}
	else {
		if (damaged) {
			this->stage = ENEMY_STAGE::DAMAGED;
		}
	}

	
	switch (stage)
	{
	case WAIT:
		switch (_id)
		{
		case 105:
			if (_x - simon_x > 190 && _x - simon_x < 200 && simon_y > 570) {
				stage = ENEMY_STAGE::RIGHT;
			}
			break;
		case 106:
			if (_x - simon_x < -190 && _x - simon_x > -200 && simon_y < 570) {
				stage = ENEMY_STAGE::RIGHT;
			}
			break;
		default:
			break;
		}
		break;
	case LEFT:
	case RIGHT:
		if (_x + _width / 2 < simon_x) {
			_vx = GHOST_SPEED;
		}
		else {
			if (_x > simon_x + 32) {
				_vx = -GHOST_SPEED;
			}
			else {
				_vx = 0;
			}
		}


		if (_y + _height < simon_y + 30) {
			_vy = GHOST_SPEED;
		}
		else {
			if (_y > simon_y + 30) {
				_vy = -GHOST_SPEED;
			}
			else {
				_vy = 0;
			}
		}

		UpdatePosition(deltatime);
		break;
	case DAMAGED:
		tickcount += deltatime;
		if (tickcount > 50) {
			stage = ENEMY_STAGE::RIGHT;
			this->damaged = false;
			tickcount = 0.0f;
		}
		break;
	case DIE:
		tickcount += deltatime;
		if (tickcount > 300) {
			this->stage = ENEMY_STAGE::END;
			this->is_remove = true;
		}
		break;
	case END:
		this->is_remove = true;
		break;
	default:
		break;
	}
}

Ghost::~Ghost()
{
}

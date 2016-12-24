#include "MedusaQueen.h"



MedusaQueen::MedusaQueen()
{
}

MedusaQueen::MedusaQueen(int id, int x, int y) : BaseObject(TYPE,x,y, MEDUSA_WIDTH,MEDUSA_HEIGHT){
	tick = 0;
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(MEDUSA_SPRITE, 5,1,5), 70);
	this->_vx = 0;
	this->_vy = 0;
	this->state = WAIT;
	this->_sptrite->SetFrame(4, 4);
	this->heath = 400;
}

void MedusaQueen::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	tickcount += deltatime;
	if (this->heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		this->Die();
	}
	else {
		if (damaged) {
			this->state = ENEMY_STAGE::DAMAGED;
		}
	}

	switch (state)
	{
	case WAIT:
		if (simon_x < _x + 210 && simon_x > _x - 210) {
			tick += deltatime;
		}
		if (tick > 4000) {
			this->state = RIGHT;
			this->_sptrite->SetFrame(0, 3);
		}
		break;
	case DAMAGED:
		break;
	case DIE:
		break;
	case END:
		break;
	default://left or right
		if (_x + _width / 2 < simon_x) {
			_vx = MEDUSA_SPEED;
		}
		else {
			if (_x > simon_x + 32) {
				_vx = -MEDUSA_SPEED;
			}
			else {
				_vx = 0;
			}
		}


		if (_y + _height < simon_y + 30) {
			_vy = MEDUSA_SPEED;
		}
		else {
			if (_y > simon_y + 30) {
				_vy = -MEDUSA_SPEED;
			}
			else {
				_vy = 0;
			}
		}

		UpdatePosition(deltatime);
		break;
	}
}

void MedusaQueen::Draw() {
	this->_sptrite->Draw(_x, _y);
}


MedusaQueen::~MedusaQueen()
{
}

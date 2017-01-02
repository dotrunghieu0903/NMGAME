#include "Raven.h"


Raven::Raven() {
}
Raven::Raven(int id, int x, int y) : BaseObject(TYPE, x, y, RAVEN_WIDTH, RAVEN_HEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(RAVEN_SPRITE, 5, 1, 5), 70);
	state = ENEMY_STAGE::WAIT;//fix to WAIT
	this->_sptrite->SetFrame(0, 0);
	this->heath = 1; attack = false;
}
void Raven::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	if (this->heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		if (tickcount > 330) {
			tickcount = 0;
		}
		this->Die();
	}
	switch (state)
	{
	case WAIT:
		if (simon_x < _x + 230 && simon_x > _x - 230) {
			state = ENEMY_STAGE::LEFT;
			this->_sptrite->SetFrame(1, 4);
			_vx = -0.1f;
			_vy = -0.1f;
			attack = true;
			tickcount = 800;
		}
		break;
	case DAMAGED:
		break;
	case DIE:
		tickcount += deltatime;
		if (tickcount > 300) {
			this->is_remove = true;
		}
		break;
	case END:
		break;
	default://left , right
		tickcount += deltatime;
		if (tickcount >= 1200) {
			attack = !attack;
			tickcount = 0;
		}

		if(!attack)
		{
			_vx = 0;
			_vy = 0;
		
		}
		else {

			if (_vx == 0 && _vy == 0) {
				if (_x + _width / 2 < simon_x) {
					_vx = RAVEN_SPEED;
				}
				else {
					if (_x > simon_x + 32) {
						_vx = -RAVEN_SPEED;
					}
					else {
						_vx = 0;
					}
				}


				if (_y + _height < simon_y +10) {
					_vy = RAVEN_SPEED;
				}
				else {
					if (_y > simon_y +10 ) {
						_vy = -RAVEN_SPEED;
					}
					else {
						_vy = 0;
					}
				}
			}
			
		}
		
		UpdatePosition(deltatime);
		
		break;
	}
}
void Raven::Draw() {
	if (state != WAIT) {
		if (_vx > 0) {
			state = ENEMY_STAGE::RIGHT;
		}
		else {
			state = ENEMY_STAGE::LEFT;
		}
	}
	if (state == ENEMY_STAGE::RIGHT) {
		this->_sptrite->Draw(_x, _y);
	}
	else {
		this->_sptrite->DrawFlipX(_x, _y);
	}
}

Raven::~Raven()
{
}

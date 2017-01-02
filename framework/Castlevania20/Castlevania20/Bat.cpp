#include "Bat.h"

Bat::Bat()
{
}

Bat::Bat(int id,int x,int y,RECT bound): BaseObject(TYPE,x,y,_batWIDTH,_batHEIGHT,bound)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(BAT_SPRITE,4,1,4),70);
	this->state = WAIT;
	this->_vx = 0;
	this->_vy = 0;
	this->_sptrite->SetFrame(0, 0);
	this->heath = HP;
}

void Bat::MoveUpdate(int simon_x,int simon_y, float deltatime) {
	if (heath <= 0) {
		if (tickcount == 0) {
			this->Die();
		}
		this->state = ENEMY_STAGE::DIE;
	}
	switch (state)
	{
	case WAIT:
		if (simon_x > _bound.left && simon_x < _bound.right &&
			simon_y > _bound.top && simon_y < _bound.bottom) {
			this->_sptrite->SetFrame(1, 3);
			if (_x + _batWIDTH / 2 > simon_x) {
				this->state = ENEMY_STAGE::LEFT;
				_vx = -BAT_SPEED;
			}
			else {
				this->state = ENEMY_STAGE::RIGHT;
				_vx = BAT_SPEED;
			}
		}
		break;
	case DAMAGED:
		break;
	case DIE:
		tickcount += deltatime;
		if (tickcount > 300) {
			is_remove = true;
		}
		break;
	case END:
		break;
	default://left , right
		if (_x > _bound.right || _x < _bound.left) {
			_vx *= -1;
		}
		_temp++;
		_vy = (float)cos((double)_temp/5)*0.2f;
		this->UpdatePosition(deltatime);
		break;
	}
}

void Bat::Draw() {
	if (state == ENEMY_STAGE::LEFT) {
		this->_sptrite->Draw(_x, _y);
	}
	else {
		this->_sptrite->DrawFlipX(_x, _y);
	}
}

Bat::~Bat()
{
}

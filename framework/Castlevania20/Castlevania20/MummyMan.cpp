#include "MummyMan.h"


MummyMan::MummyMan() {

}
MummyMan::MummyMan(int id, int x, int y, int var1) : BaseObject(TYPE, x, y, MUMMYMAN_WIDTH, MUMMYMAN_HEIGHT) {
	tick = 0;
	this->_id = id;
	this->number = var1;
	this->_sptrite = new Sprite(new Texture(MUMMYMAN_SPRITE, 5, 1, 5), 70);
	this->_vx = 0;
	this->_vy = 0;
	this->state = ENEMY_STAGE::WAIT;
	this->_sptrite->SetFrame(0, 0);
	this->heath = 500;
	tickcount = 0;
	
}
void MummyMan::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	if (simon_x < 6433) {
		this->state = ENEMY_STAGE::WAIT;
		this->_sptrite->SetFrame(0, 0);
		this->heath = 500;
		tickcount = 0;
	}

	if (this->heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		if (timedie == 0) {
			this->Die();
		}
		timedie += deltatime;
	}
	else {
		if (damaged) {
			this->state = ENEMY_STAGE::DAMAGED;
		}
	}
	switch (state)
	{
	case WAIT:
		if (simon_x > 6910 || tickcount != 0) {
			tickcount += deltatime;
		}
		if (tickcount > 3000) {
			if (simon_x - 30 > _x) {
				this->state = ENEMY_STAGE::RIGHT;
			}
			else {
				this->state = ENEMY_STAGE::LEFT;
			}
			tickcount = 0;
		}
		break;
	case DAMAGED:
		tickcount += deltatime;
		if (tickcount > 50) {
			state = ENEMY_STAGE::RIGHT;
			this->damaged = false;
			tickcount = 0.0f;
		}
		break;
	case DIE:
		if (timedie > 300) {
			is_remove = true;
		}
		break;
	case END:
		break;
	default://left right
		tickcount += deltatime;
		if (_x + _width / 2 < simon_x) {
			_vx = MUMMYMAN_SPEED;
		}
		else {
			if (_x > simon_x + 32) {
				_vx = -MUMMYMAN_SPEED;
			}
			else {
				_vx = 0;
			}
		}
		if (tickcount > (number == 1 ? 1000 : 1200)) {
			delete band;
			band = new Bandage(_x + 30, _y, simon_x < _x + 20);
			tickcount = 0;
		}
		if (band != nullptr) {
			band->Update(deltatime);

			if (band->is_remove) {
				delete band;
				band = nullptr;
			}
			tickcount = 0;
		}
		UpdatePosition(deltatime);
		break;
	}
}
void MummyMan::Draw() {
	if (this->_vx > 0.0f) {
		state = ENEMY_STAGE::RIGHT;
	}
	if (this->_vx < 0.0f) {
		state = ENEMY_STAGE::LEFT;
	}
	if (state == ENEMY_STAGE::RIGHT) {
		this->_sptrite->Draw(_x, _y);
	}
	else {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	if (band != nullptr) {
		band->Draw();
	}
}
void MummyMan::Die() {
	delete _sptrite;
	this->_sptrite = new Sprite(new Texture(DIE_SPRITE, 3, 1, 3), 100);
	this->_vx = 0.0f;
	this->_vy = 0.0f;
}
Box MummyMan::getBox() {
	if (state == ENEMY_STAGE::WAIT) {
		return Box();
	}
	return Box(this->_x, this->_y, this->_width, this->_height);
}

Bandage* MummyMan::getBandage() {
	return band;
}


MummyMan::~MummyMan()
{
}

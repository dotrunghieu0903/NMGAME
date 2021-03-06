#include "DragonSkull.h"



DragonSkull::DragonSkull()
{
}

DragonSkull::DragonSkull(int id, int x, int y) : BaseObject(TYPE, x, y, DRAGON_WIDTH, DRAGON_HEIGHT){
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(DRAGON_SPRITE), 70);
	this->_vx = 0;
	this->_vy = 0;
	this->state = WAIT;
	shot = shot1;
}

void DragonSkull::MoveUpdate(int simon_x, int simon_y, float deltatime) {//update event
	
	tickcount += deltatime;
	if (this->heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		if (timedie == 0) {
			this->Die();
		}
		tickcount = 0;
	}
	else {
		if (damaged) {
			this->state = ENEMY_STAGE::DAMAGED;
		}
	}

	switch (state)
	{
	case WAIT:
		if (simon_x < _x + 240 && simon_x > _x - 240) {
			state = ENEMY_STAGE::RIGHT;
		}
		break;
	case DAMAGED:
		if (simon_x > _x + _width) {
			state = ENEMY_STAGE::RIGHT;
		}
		if (simon_x + 40 < _x) {
			state = ENEMY_STAGE::LEFT;
		}
		this->damaged = false;
	
		break;
	case DIE:
		timedie += deltatime;
		for (int i = 0; i < _listFireBall.size(); i++) {
			if (_listFireBall[i]->is_remove) {
				_listFireBall.erase(_listFireBall.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < _listFireBall.size(); i++) {
			_listFireBall[i]->Update(deltatime);
		}
		if (timedie > 300) {
			this->state = ENEMY_STAGE::END;
			this->is_remove = true;
		}
		break;
	case END:
		break;
	default://left or right
		DWORD now = GetTickCount();
		if (simon_x > _x + _width) {
			state = ENEMY_STAGE::RIGHT;
		}
		if (simon_x + 40 < _x) {
			state = ENEMY_STAGE::LEFT;
		}
		if (now - _lastUpdate >= (shot == shot1 ? TIMEFIRE : TIMEFIRE2)) {
			_lastUpdate = now;
			if (shot == shot1) {
				shot = shot2;
			}
			else {
				shot = shot1;
			}
			this->Fire();
			tickcount = 0;
		}
		for (int i = 0; i < _listFireBall.size(); i++) {
			if (_listFireBall[i]->is_remove) {
				_listFireBall.erase(_listFireBall.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < _listFireBall.size(); i++) {
			_listFireBall[i]->Update(deltatime);
		}
		break;
	}
}

void DragonSkull::Fire() {
	if (state == ENEMY_STAGE::WAIT) {
		return;
	}
	_listFireBall.push_back(new FireBall(_x + 16,_y + 18, (state == LEFT)));
}

void DragonSkull::Draw() {
	if (state == ENEMY_STAGE::WAIT) {
		return;
	}
	if (state == ENEMY_STAGE::LEFT) {
		this->_sptrite->Draw(_x, _y);
	}
	else {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	for (int i = 0; i < _listFireBall.size(); i++) {
		_listFireBall[i]->Draw();
	}
}


DragonSkull::~DragonSkull()
{
}

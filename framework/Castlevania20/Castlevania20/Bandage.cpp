#include "Bandage.h"


Bandage::Bandage(int x, int y, bool is_left) : BaseObject(TYPE, x, y, BAND_WIDTH, BAND_HEIGHT) {
	this->_sptrite = new Sprite(new Texture(BAND_SPRITE, 2, 1, 2), 10);
	this->_vy = 0.3f;
	this->is_left = is_left;
	this->heath = 1;
}

void Bandage::MoveUpdate(float deltatime) {
	if (heath <= 0) {
		if (timedie != 0) {
			this->Die();
		}
		timedie += deltatime;
		if (timedie >= 300) {
			is_remove = true;
		}
		_sptrite->Update(deltatime);
		return;
	}
	tickcount += deltatime;
	if (tickcount > 2000) {
		is_remove = true;
	}
	if (_y >= 395) {
		_vy = 0;
		_vx = is_left ? -0.3f : 0.3f;
	}
	UpdatePosition(deltatime);
}

void Bandage::Draw() {
	if (_vx >= 0.0f) {
		this->_sptrite->Draw(_x, _y);
	}
	else {
		this->_sptrite->DrawFlipX(_x, _y);
	}
}
Bandage::~Bandage()
{
}

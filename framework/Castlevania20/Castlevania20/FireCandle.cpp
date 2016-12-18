#include "FireCandle.h"



FireCandle::FireCandle()
{
}

FireCandle::FireCandle(int id, int x, int y) :BaseObject(TYPE, x, y, CANDLE_WIDTH, CANDLE_HEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(CANDLE_SPRITE, 2, 1, 2), 100);
	off = false;
	heath = 1;
}

void FireCandle::UpdateEvent(float deltatime) {
	if (heath <= 0) {
		off = true;
		this->Die();
	}
	if (tickcount >= 200) {
		is_remove = true;
	}
	if (off) {
		tickcount += deltatime;
	}
}

void FireCandle::Draw() {
	this->_sptrite->Draw(_x, _y);
}


FireCandle::~FireCandle()
{
}

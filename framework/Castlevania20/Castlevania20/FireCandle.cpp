#include "FireCandle.h"
#include "Item.h"

extern vector<ITEM*> listItem;

FireCandle::FireCandle()
{
}

FireCandle::FireCandle(int id, int x, int y, int item) :BaseObject(TYPE, x, y, CANDLE_WIDTH, CANDLE_HEIGHT)
{
	this->_id = id;
	this->_item = item;
	this->_sptrite = new Sprite(new Texture(CANDLE_SPRITE, 2, 1, 2), 100);
	off = false;
	heath = 1;
}

void FireCandle::UpdateEvent(float deltatime) {
	if (tickcount >= 100) {
		is_remove = true;
	}
	if (off) {
		tickcount += deltatime;
		return;
	}
	if (heath <= 0) {
		off = true;
		PlaySound(get_hit);
		if (_item >= 23)
		{
			listItem.push_back(new ITEM(_item, _x, _y));
		}
		this->Die();
	}
}

void FireCandle::Draw() {
	this->_sptrite->Draw(_x, _y);
}


FireCandle::~FireCandle()
{
	StopSound(get_hit);
}

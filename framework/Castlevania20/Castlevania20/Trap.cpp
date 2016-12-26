#include "Trap.h"

#define TIME_UP 110
#define TIME_DOWN 30
#define TIME_DELAY 100



void Trap::MoveUpdate(float deltatime) {
	tickcount += deltatime;
	switch (stage)
	{
	case UP: {
		if (tickcount > (order == 3 ? TIME_UP : TIME_UP + deltatime)) {
			tickcount = 0;
			_y -= 8;
			number--;
			if (_y < 604) {
				stage = DELAY;
			}
		}
		break;
	}
	case DOWN: {
		if (tickcount > TIME_DOWN) {
			_y += 8;
			number++;
			if (_y > (order == 2 ? 642 : 690)) {
				stage = DELAY;
			}
			tickcount = 0;
		}
		break;
	}
	case DELAY: {
		if (tickcount >(order == 1 ? TIME_DELAY + 500 : TIME_DELAY)) {
			if (_y < 612) {
				stage = DOWN;
			}
			else {
				stage = UP;
			}
			tickcount = 0;
		}
		break;
	}
		
	default:
		break;
	}
}


Trap::Trap()
{
}

int Trap::CheckCollision(BaseObject *object2, float deltatime) {
	if (AABBCheck(object2->getBox(), this->getBox())) {
		return COLLIDED_IN;
	}
}

Trap::Trap(int id, int x, int y, int order) : BaseObject(TYPE, x, y, 64, 36) {
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(TRAP_SPRITE), 10);
	this->order = order;
	pillar = new Sprite(new Texture(PILLAR_SPRITE), 10);
}

void Trap::Draw() {
	this->_sptrite->Draw(_x, _y);
	for (int i = 0; i < number; i++) {
		this->pillar->Draw(_x, _y - i * 8 - 8);
	}
}

Trap::~Trap()
{
}

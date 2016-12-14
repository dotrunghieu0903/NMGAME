#include "BaseObject.h"

BaseObject::BaseObject(int type, int x, int y, int width, int height)
{
	_type = type;
	_x = x;
	_y = y;
	_vx = 0;
	_vy = 0;
	last_x = 0;
	last_y = 0;
	_gravity = GRAVITY;
	_width = width;
	_height = height;
}

BaseObject::BaseObject(int type, int x, int y, int width, int height, RECT rect)
{
	_type = type;
	_x = x;
	_y = y;
	last_x = 0;
	last_y = 0;
	_vx = 0;
	_vy = 0;
	_gravity = GRAVITY;

	_width = width;
	_height = height;

	_bound = rect;
}


void BaseObject::UpdatePosition(int time)
{
	//_vy += _gravity * time;
	_x += int(_vx * time);
	_y += int(_vy * time);
}


int BaseObject::CheckCollision(BaseObject *object2, float deltatime) {
	
	Box thisBox = this->getBox();
	int b  = 0;
	//check now
	if (thisBox.x + thisBox.w <= object2->getBox().x ||
		thisBox.y + thisBox.h <= object2->getBox().y ||
		thisBox.x >= object2->getBox().x + object2->getBox().w ||
		thisBox.y >= object2->getBox().y + object2->getBox().h)
	{//check in next game loop
		thisBox.x += thisBox.vx*deltatime;
		thisBox.y += thisBox.vy*deltatime;
		if (thisBox.x + thisBox.w <= object2->getBox().x ||
			thisBox.y + thisBox.h <= object2->getBox().y ||
			thisBox.x >= object2->getBox().x + object2->getBox().w ||
			thisBox.y >= object2->getBox().y + object2->getBox().h)
			return COLLIDED_NONE;
	}


	thisBox = this->getBox();
	Box objectBox = object2->getBox();
	if (objectBox.y + objectBox.h > thisBox.y + thisBox.h && thisBox.x < (objectBox.x +objectBox.w) && (thisBox.x + thisBox.w) > objectBox.x) {
		return COLLIDED_TOP;
	}

	if (objectBox.x > thisBox.x + thisBox.w && thisBox.y < (objectBox.y + objectBox.h) && (thisBox.y + thisBox.h) > objectBox.y) {
		return COLLIDED_LEFT;
	}

	if ((objectBox.x +objectBox.w)< thisBox.x && thisBox.y < (objectBox.y + objectBox.h) && (thisBox.y + thisBox.h) > objectBox.y) {
		return COLLIDED_RIGHT;
	}

 	if ((objectBox.y)< thisBox.y && thisBox.x < (objectBox.x + objectBox.w) && (thisBox.x + thisBox.w) > objectBox.x) {
		return COLLIDED_BOT;
	}

}

Box BaseObject::getBox() {
	return Box(this->_x, this->_y, this->_width, this->_height, _vx, _vy);
}

void BaseObject::Update(float deltatime){
	InputUpdate(deltatime);
	SetFrame(deltatime);
	MoveUpdate(deltatime);
	_sptrite->Update(deltatime);
}




BaseObject::~BaseObject()
{

}
BaseObject::BaseObject()
{

}
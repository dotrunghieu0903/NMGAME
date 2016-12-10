#include "BaseObject.h"

BaseObject::BaseObject(int type, int x, int y, int width, int height)
{
	_type = type;
	_x = x;
	_y = y;
	_vx = 0;
	_vy = 0;
	_gravity = GRAVITY;

	_width = width;
	_height = height;
	_bound.left = _x;
	_bound.top = _y;
	_bound.right = _x + width;
	_bound.bottom = _y + height;

	//sweptAB = new Swept();


}


void BaseObject::UpdatePosition(int time)
{
	_vy += _gravity * time;
	_x += int(_vx * time);
	_y += int(_vy * time);
}


bool BaseObject::CheckCollision(BaseObject *object2) {
	if (AABBCheck(this->getBox(), object2->getBox())) {
		return true;
	}
	else {
		
		float normalx, normaly;
		if (AABB(this->getBox(), object2->getBox(), normalx, normaly)) {
			return true;
		}
		float result = SweptAABB(this->getBox(), object2->getBox(), normalx, normaly);
		if(result >0 && result < 1){
			return true;
		}
	}
	return false;
}

Box BaseObject::getBox() {
	return Box(this->_x, this->_y, this->_width, this->_height, _vx, _vy);
}


BaseObject::~BaseObject()
{

}
BaseObject::BaseObject()
{

}
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
	
	Box thisBox = GetSweptBroadphaseBox(this->getBox(), deltatime);
	if (_x + _width <= object2->_x ||
		_y + _height <= object2->_y ||
		_x >= object2->_x + object2->_width ||
		_y >= object2->_y + object2->_height)
		return COLLIDED_NONE;

	//TODO MINH

	
	//AABBCHECK

	//float normalx = 0, normaly = 0;

	//float result = SweptAABB(thisBox, object2->getBox(), normalx, normaly, deltatime);

	//if (result > 0 && result < 1) {
	//	if (normalx == 1.0f && normaly == 0.0f) {
	//		return COLLIDED_LEFT;//phai
	//	}
	//	if (normalx == -1.0f && normaly == 0.0f) {
	//		return COLLIDED_RIGHT;//trai
	//	}
	//	if (normalx == 0.0f && normaly == 1.0f) {
	//		return COLLIDED_BOT;//tren
	//	}
	//	if (normalx == 0.0f && normaly == -1.0f) {
	//		return COLLIDED_TOP;//duoi
	//	}
	//}


	if (sqrt(_vx*_vx + _vy*_vy) <= 0.1f)
	{
		int r = abs(object2->_x - (_x + _width));
		int l = abs(_x - (object2->_x + object2->_width));
		int t = abs(object2->_y - (_y + _height));
		int b = abs(_y - (object2->_y + object2->_height));

		int fix = min(r, min(l, min(t, b)));

		if (fix == r) return COLLIDED_RIGHT;
		else if (fix == l) return COLLIDED_LEFT;
		else if (fix == t) return COLLIDED_TOP;
		else return COLLIDED_BOT;
	}

	if (_vy > 0)
	{
		if (_vx > 0)
		{
			float t_1 = float(object2->_x - (last_x + _width)) / abs(_vx*deltatime);
			float t_2 = float(object2->_y - (last_y + _height)) / abs(_vy*deltatime);
			if (t_1 * t_2 > 0)
			{
				if (abs(t_1) > abs(t_2)) return COLLIDED_TOP;
				else return COLLIDED_RIGHT;
			}
			else
				if (t_1 < 0) return COLLIDED_TOP;
				else return COLLIDED_RIGHT;
		}
		else
		{
			float t_1 = float(last_x - (object2->_x + object2->_width)) / abs(_vx*deltatime);
			float t_2 = float(object2->_y - (last_y + _height)) / abs(_vy*deltatime);
			if (t_1 * t_2 > 0)
			{
				if (abs(t_1) > abs(t_2)) return COLLIDED_TOP;
				else return COLLIDED_LEFT;
			}
			else
				if (t_1 < 0) return COLLIDED_TOP;
				else return COLLIDED_LEFT;
		}
	}
	else
	{
		if (_vx > 0)
		{
			float t_1 = float(object2->_x - (last_x + _width)) / abs(_vx*deltatime);
			float t_2 = float(last_y - (object2->_y + object2->_height)) / abs(_vy*deltatime);
			if (t_1 * t_2 > 0)
			{
				if (abs(t_1) > abs(t_2)) return COLLIDED_BOT;
				else return COLLIDED_RIGHT;
			}
			else
				if (t_1 < 0) return COLLIDED_BOT;
				else return COLLIDED_RIGHT;
		}
		else
		{
			float t_1 = float(last_x - (object2->_x + object2->_width)) / abs(_vx*deltatime);
			float t_2 = float(last_y - (object2->_y + object2->_height)) / abs(_vy*deltatime);
			if (t_1 * t_2 > 0)
			{
				if (abs(t_1) > abs(t_2)) return COLLIDED_BOT;
				else return COLLIDED_LEFT;
			}
			else
				if (t_1 < 0) return COLLIDED_BOT;
				else return COLLIDED_LEFT;
		}
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

void BaseObject::Land(BaseObject * object) {
	this->_y = object->_y - this->_height;
}


BaseObject::~BaseObject()
{

}
BaseObject::BaseObject()
{

}
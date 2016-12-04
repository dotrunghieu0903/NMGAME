#include "Simon.h"

Simon::Simon()
{
}

Simon::Simon(int _x, int _y) {
		_isFalling = true;
		_isMoveRight = false;
		_isOnStair = false;
		_state = StateSimon::FALLING;
		_vy = 0.3f;
		this->_sprite = new Sprite(SIMON_SPRITE, SIMON_WIDTH, SIMON_HEIGHT,24,8);
		Box *_box = new Box((float)_x, (float)_y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
}

bool Simon::isDead() {
	return true;
}

void Simon::SetFrame(float _del) {
	switch (_state)
	{
	case StateSimon::STANDING:
	case StateSimon::FALLING:
	{
		this->_sprite->_Start=0;
		this->_sprite->_End = 0;
		break;
	}
	case StateSimon::JOGGING:
	{
		this->_sprite->_Start = 0;
		this->_sprite->_End = 3;
		break;
	}
	default:
		break;
	}
}

void Simon::MoveUpdate(float _del) {
	
}

void Simon::Draw() {
	if (this->_isMoveRight) {
		_sprite->RenderFlipX(_x, _y);
	}
	else
	{
		_sprite->Render(_x, _y);
	}
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(150, 150);
	return _simon;
}
Simon* Simon::_simon = 0;

Simon::~Simon()
{
}
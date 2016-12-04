#include "Simon.h"
Simon::Simon() {

}
Simon::Simon(int _x, int _y) {
		_isFalling = true;
		_isMoveRight = false;
		_isMoveLeft = false;
		_isOnStair = false;
		_state = StateSimon::FALLING;
		this->_x = 25;
		this->_y = 400;
		this->_vx = 2.0f;
		this->_sprite = new Sprite(SIMON_SPRITE, SIMON_WIDTH, SIMON_HEIGHT,24,8);
		Box *_box = new Box((float)_x, (float)_y, SIMON_WIDTH, SIMON_HEIGHT, this->_vx, this->_vy);
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
	if (this->_isOnStair) {
		this->_x += this->_vx*_del;
	}
	else
	{
		if (this->_state == StateSimon::STANDING) {
			this->_vx = 0;
			
		}
		else if (this->_state == StateSimon::FALLING) {
			_vy = SIMON_SPEED;
			
			if (this->_y > 60 + 66) {
				this->_y -= _vy*_del;
			
			}
			else {
				this->_state == StateSimon::STANDING;
				
			}
			if (this->_isMoveLeft)
			{
				if (this->_vx < 0)
				{
					this->_x += this->_vx * _del;
				}
			}
			else if (this->_isMoveRight)
			{
				if (this->_vx > 0)
				{
					this->_x += this->_vx * _del;
				}
			}
		}
		
	}
	
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

void Simon::UpdateKeyboard(float _del ) {
	/*if( (_input->IsKeyDown(DIK_LEFT) || _input->IsKeyDown(DIK_RIGHT)) && this->_state!=StateSimon::FALLING && this->_state != StateSimon::JUMPING ){*/
	//Input* _input = new Input();
	//if (Input::GetInput()->IsKeyDown(DIK_RIGHT) ) {
	//
	//	this->_x += this->_vx * _del;
	//		/*this->_isMoveRight = true;
	//		this->_isMoveLeft = false;
	//		this->_vx = SIMON_SPEED;*/
	//		
	//	
	//	//else {
	//	//	/*this->_isMoveRight = false;
	//	//	this->_isMoveLeft = true;
	//	//	this->_vx = -SIMON_SPEED;*/
	//	//
	//	//}
	//}
}
void Simon::Update(float _del) {
	this->UpdateKeyboard(_del);
	this->MoveUpdate(_del);
	this->SetFrame(_del);
}
Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(60, 60);
	return _simon;
}
Simon* Simon::_simon = 0;

Simon::~Simon()
{
}
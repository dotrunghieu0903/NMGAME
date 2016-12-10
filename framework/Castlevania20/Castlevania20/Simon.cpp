#ifndef __SIMON_CPP__
#define __SIMON_CPP__

#include "Simon.h"

Simon::Simon() {
}

Simon* Simon::_simon = 0;
Simon::Simon(int x, int y) :
	BaseObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
	_isMoveleft = true;
	_isMoveright = false;
	_isOnStair = false;
	_isJumping = false;
	_isFalling = false;
	_stateCurrent = STATE::IS_STANDING;
	_vy = SIMON_SPEED;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 50);
}

void Simon::MoveUpdate(float deltaTime)
{

	//doi tuong leo cau thang
	if (this->_isOnStair)
	{
		this->_x += int(this->_vx * deltaTime);
		//this->_y -= int(this->_vx*deltaTime);
	}
	else
	{
		if (this->_stateCurrent == STATE::IS_STANDING)
		{
			this->_vx = 0;
			_vy = SIMON_SPEED;
		}
		else
		{
			if (this->_isFalling) {
				
				this->_y += int(this->_vy*deltaTime);
				/*if (this->_y > 380) {
					this->_vy = 0;
				}*/
			}
		}
		if (this->_isMoveleft)
		{
			if (this->_vx < 0)
			{
				this->_x += int(this->_vx * deltaTime);
			}
		}
		else if (this->_isMoveright)
		{
			if (this->_vx > 0)
			{
				this->_x += int(this->_vx * deltaTime);
			}
		}
		if (this->_stateCurrent == STATE::IS_JUMPING) {
			this->_y += int(this->_vy * deltaTime);
			this->_x += int(this->_vx * deltaTime);
			if (_vy < -0.3)
				_vy += 0.2f;
			else {
				this->_stateCurrent = STATE::IS_FALLING;
				_isFalling = true;
				_isJumping = false;
			}
		}

	}

	/*_box.x = _x;
	_box.y = _y;
	_box.vx = _vx;
	_box.vy = _vy;*/
}

void Simon::SetFrame(float deltaTime)
{

	if (!this->_isOnStair) //dang o duoi dat
	{
		switch (this->_stateCurrent)
		{
		case STATE::IS_STANDING://dung
		case STATE::IS_FALLING://roi
		{
			this->_sptrite->_start = 0;
			this->_sptrite->_end = 0;
			break;
		}
		case STATE::IS_JOGGING://Chay bo
		{
			this->_sptrite->_start = 0;
			this->_sptrite->_end = 3;
			break;
		}
		case STATE::IS_JUMPING://Nhay
		case STATE::IS_SITTING://Ngoi
		{
			this->_sptrite->_start = 4;
			this->_sptrite->_end = 4;
			break;
		}
		case STATE::IS_FIGHTING:
		{
			this->_sptrite->_start = 5;
			this->_sptrite->_end = 7;
			break;
		}
		case STATE::IS_PASSGATE:
		{
			this->_sptrite->_start = 9;
			this->_sptrite->_end = 9;
			break;
		}
		case STATE::IS_SITFIGHT:
		{
			this->_sptrite->_start = 15;
			this->_sptrite->_end = 17;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else //tren cau thang
	{
		switch (this->_stateCurrent)
		{
		case STATE::IS_UPING:
		{
			this->_sptrite->_start = 12;
			this->_sptrite->_end = 13;
			break;
		}
		case STATE::IS_DOWNING:
		{
			this->_sptrite->_start = 10;
			this->_sptrite->_end = 11;
			break;
		}
		case STATE::IS_UPFIGHT:
		{
			this->_sptrite->_start = 21;
			this->_sptrite->_end = 23;
			break;
		}
		case STATE::IS_DOWNFIGHT:
		{
			this->_sptrite->_start = 18;
			this->_sptrite->_end = 20;
			break;
		}
		default:
			break;
		}
	}

}

void Simon::InputUpdate(float deltaTime)
{
	//Không nhảy
	if (!this->_isJumping)
	{
		this->_vx = 0;
	}
	if (this->_stateCurrent != STATE::IS_FALLING) 
		_stateCurrent = STATE::IS_STANDING;

	//xử lý nhảy
	if (Input::getCurrentInput()->IsKeyDown(DIK_SPACE))
	{
		if (!_isJumping) {
			this->_stateCurrent = STATE::IS_JUMPING;
			_vy = -SIMON_JUMP_SPEED;
			_vx = 0;
			this->_x += _vx*deltaTime;
			this->_y += this->_x*this->_x;
			//_isJumping = true;
			/*if (_isMoveright)
				this->_vx = SIMON_SPEED;
			if (_isMoveleft)
				this->_vx = -SIMON_SPEED;*/
		}

	}
	
// đi qua trái or phải
	if ((Input::getCurrentInput()->IsKeyDown(DIK_LEFT) || Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
		&& this->_stateCurrent != STATE::IS_JUMPING&& this->_stateCurrent != STATE::IS_FALLING)
	{
		this->_stateCurrent = STATE::IS_JOGGING;
		if (Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
		{
			this->_isMoveright = true;
			this->_isMoveleft = false;
			this->_vx = SIMON_SPEED;
		}
		else
		{
			this->_isMoveright = false;
			this->_isMoveleft = true;
			this->_vx = -SIMON_SPEED;
		}
	}

}

void Simon::Update(float deltatime) {
	this->InputUpdate(deltatime);
	this->SetFrame(deltatime);
	this->MoveUpdate(deltatime);
	this->_sptrite->Update(deltatime);
}

void Simon::Draw() {
	if (this->_isMoveright) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}

//void Simon::Jump() {
//	if (!_isJumping) {
//		if (this->_isFighting) {
//			this->_stateCurrent = STATE::IS_JUMPFIGH;
//		}
//		else
//		{
//			this->_stateCurrent = STATE::IS_JUMPING;
//		}
//		_vy = -3.0f;
//		_isJumping = true;
//		if (Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
//			this->_vx = SIMON_SPEED;
//		if (Input::getCurrentInput()->IsKeyDown(DIK_LEFT))
//			this->_vx = -SIMON_SPEED;
//	}
//}

void Simon::ChangeState(int state) {
	this->_stateCurrent = state;
	switch (state) {
	case STATE::IS_STANDING:
		this->_isFalling = false;
		this->_isJumping = false; break;
	case STATE::IS_FALLING: this->_isFalling = true;
		this->_isJumping = false;  break;
	}
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(100, 330);
	return _simon;
}

Simon::~Simon() {
}

#endif
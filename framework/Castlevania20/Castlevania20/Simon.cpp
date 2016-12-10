#ifndef __SIMON_CPP__
#define __SIMON_CPP__

#include "Simon.h"

Simon* Simon::_simon = 0;

Simon::Simon() {
}

Simon::Simon(int x, int y) :BaseObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
	_isMoveleft = true;
	_isMoveright = false;
	_isOnStair = false;
	_isJumping = false;
	_isFalling = false;
	_stateCurrent = STATESIMON::STANDING;
	_vy = SIMON_SPEED;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 50);
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
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
		if (this->_stateCurrent == STATESIMON::STANDING)
		{
			this->_vx = 0;
			_vy = SIMON_SPEED;
		}
		else
		{
			if (this->_isFalling) {
				
				this->_y += int(this->_vy*deltaTime);
				if (this->_x > SIMON_HEIGHT + SIMON_WIDTH) {
					this->_vy = 0;
				}
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
		if (this->_stateCurrent == STATESIMON::JUMPING) {
			this->_y += int(this->_vy * deltaTime);
			this->_x += int(this->_vx * deltaTime);
			if (_vy < -0.3){
				_vy += 0.2f;
			}
			else {
				this->_stateCurrent = STATESIMON::FALLING;
				_isFalling = true;
				_isJumping = false;
			}
		}

	}

}

void Simon::SetFrame(float deltaTime)
{

	if (!this->_isOnStair) //dang o duoi dat
	{
		switch (this->_stateCurrent)
		{
		case STATESIMON::STANDING://dung
		case STATESIMON::FALLING://roi
		{
			this->_sptrite->_start = 0;
			this->_sptrite->_end = 0;
			break;
		}
		case STATESIMON::JOGGING://Chay bo
		{
			this->_sptrite->_start = 0;
			this->_sptrite->_end = 3;
			break;
		}
		case STATESIMON::JUMPING://Nhay
		case STATESIMON::SITTING://Ngoi
		{
			this->_sptrite->_start = 4;
			this->_sptrite->_end = 4;
			break;
		}
		case STATESIMON::FIGHTING:
		{
			this->_sptrite->_start = 5;
			this->_sptrite->_end = 7;
			break;
		}
		case STATESIMON::PASSGATE:
		{
			this->_sptrite->_start = 9;
			this->_sptrite->_end = 9;
			break;
		}
		case STATESIMON::SITFIGHT:
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
		case STATESIMON::UPING:
		{
			this->_sptrite->_start = 12;
			this->_sptrite->_end = 13;
			break;
		}
		case STATESIMON::DOWNING:
		{
			this->_sptrite->_start = 10;
			this->_sptrite->_end = 11;
			break;
		}
		case STATESIMON::UPFIGHT:
		{
			this->_sptrite->_start = 21;
			this->_sptrite->_end = 23;
			break;
		}
		case STATESIMON::DOWNFIGHT:
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
	if (this->_stateCurrent != STATESIMON::FALLING)
		_stateCurrent = STATESIMON::STANDING;

	//xử lý nhảy
	if (Input::getCurrentInput()->IsKeyDown(DIK_Z))
	{
		if (this->_isFighting) {
			this->_stateCurrent = STATESIMON::JUMPFIGH;
		}
		else
		{
			this->_stateCurrent = STATESIMON::JUMPING;
			_vy = -0.3f;
			_isJumping = true;
		}
	}
	
// đi qua trái or phải
	if ((Input::getCurrentInput()->IsKeyDown(DIK_LEFT) || Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
		&& this->_stateCurrent != STATESIMON::JUMPING && this->_stateCurrent != STATESIMON::FALLING)
	{
		this->_stateCurrent = STATESIMON::JOGGING;
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

	//xử lý đi lên đi xuống cầu thang
	if (Input::getCurrentInput()->IsKeyDown(DIK_UP)) {
		if (this->_isOnStair) {
			this->_stateCurrent = STATESIMON::UPING;
		}
		else
		{
			this->_stateCurrent = STATESIMON::JOGGING;
		}

	}
	else if(Input::getCurrentInput()->IsKeyDown(DIK_DOWN))
	{
		if (this->_isOnStair) {
			this->_stateCurrent = STATESIMON::DOWNING;
		}
		else
		{
			this->_stateCurrent = STATESIMON::SITTING;
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

void Simon::Jump() {
	if (!_isJumping) {
		if (this->_isFighting) {
			this->_stateCurrent = STATESIMON::JUMPFIGH;
		}
		else
		{
			this->_stateCurrent = STATESIMON::JUMPING;
		}
		_vy = -3.0f;
		_isJumping = true;
		if (Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
			this->_vx = SIMON_SPEED;
		if (Input::getCurrentInput()->IsKeyDown(DIK_LEFT))
			this->_vx = -SIMON_SPEED;
	}
}

void Simon::ChangeState(int STATESIMON) {
	this->_stateCurrent = STATESIMON;
	switch (STATESIMON) {
	case STATESIMON::STANDING:
		this->_isFalling = false;
		this->_isJumping = false; break;
	case STATESIMON::FALLING: this->_isFalling = true;
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
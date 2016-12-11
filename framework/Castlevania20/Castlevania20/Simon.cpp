#ifndef __SIMON_CPP__
#define __SIMON_CPP__

#include "Simon.h"

Simon* Simon::_simon = 0;

Simon::Simon() {
}

Simon::Simon(int x, int y) :BaseObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
<<<<<<< HEAD
	//_vy = SIMON_SPEED;
	_vy = 0;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 200);
=======
	_isMoveleft = false;
	_isMoveright = true;
	_isOnStair = true;
	_isJumping = false;
	_isFalling = false;
	_stateCurrent = STATESIMON::UPING;
	_vy = SIMON_SPEED;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 40);
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
	_Facing = FACE_LEFT;
	is_control = true;//note
	Move_State = STAND;
	this->_sptrite->SetFrame(0, 0);
}

void Simon::MoveUpdate(float deltaTime)
{
<<<<<<< HEAD
	//update x, y <- vx, vy

	if (this->Move_State == JUMP) {
		_vy += 0.1f;
	}
	if (_vy > 0.1f) {
		_vy = 0.1f;
=======
	//doi tuong leo cau thang
	if (this->_isOnStair)
	{
		//this->_x += int(_vx * deltaTime);
		//this->_y -= int(_vy*deltaTime);
		
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
			//if (_vy < -0.3){
			_vy += 0.1f;
			if (_vy > 0.1f) {
				_vy = 0.1f;
			}
		}
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
	}


	this->_x += _vx*deltaTime;
	this->_y += _vy*deltaTime;
	_sptrite->Update(deltaTime);
}




void Simon::InputUpdate(float deltaTime)
{	
	bool presskey = false;
	if (!is_control) {
		return;
	}
<<<<<<< HEAD
=======

>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
	//xử lý nhảy
	if (Input::getCurrentInput()->IsKeyDown(DIK_SPACE) && (Move_State!=JUMP))
	{
		this->Jump();//set vx, vy
		presskey = true;
	}
<<<<<<< HEAD
	
=======

>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
	// đi qua trái or phải
	if ((Input::getCurrentInput()->IsKeyDown(DIK_LEFT) || Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
		&& (Move_State != JUMP) && (Move_State != FALL))
	{
		Move_State = MOVE;
		if (Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
		{
			_Facing = FACE_RIGHT;
			this->_vx = SIMON_SPEED;
		}
		else
		{
			_Facing = FACE_LEFT;
			this->_vx = -SIMON_SPEED;
		}
		this->Move();
		presskey = true;
	}
	if (!presskey && (Move_State != JUMP) && (Move_State != FALL)) {
		Move_State = STAND;
		Action_State = REST;
		_vx = 0.0f;
		this->_sptrite->SetFrame(0, 0);
	}
<<<<<<< HEAD
=======
	else if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN))
	{
		if (this->_isOnStair) {
			this->_stateCurrent = STATESIMON::DOWNING;
		}
		else
		{
			this->_stateCurrent = STATESIMON::SITTING;
		}
	}

>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
}

void Simon::Draw() {
	if (this->_Facing == FACE_RIGHT) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}
}

void Simon::Jump() {
<<<<<<< HEAD
	if (!is_control)
		return;
	if (Move_State == STAND || Move_State == MOVE)
	{
		_vy = -SIMON_JUMP_SPEED;
		Move_State = JUMP;
		this->_sptrite->SetFrame(4, 4);
	}
}

void Simon::Move() {

	if (Move_State == MOVE)
	{
		this->_sptrite->SetFrame(0, 3);
	}
}


void Simon::ReturnCheckCollision(vector<BaseObject*> lisobject){
=======
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
	}
}

//void Simon::ChangeState(int STATESIMON) {
//	this->_stateCurrent = STATESIMON;
//	switch (STATESIMON) {
//	case STATESIMON::STANDING:
//		this->_isFalling = false;
//		this->_isJumping = false; break;
//	case STATESIMON::FALLING: this->_isFalling = true;
//		this->_isJumping = false;  break;
//	}
//}

void Simon::ReturnCheckCollision(vector<BaseObject*> lisobject) {
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
	bool collision = false;
	for (int i = 0; i < lisobject.size(); i++) {
		if (this->CheckCollision(lisobject[i])) {
			collision = true;
			//function
			switch (lisobject[i]->_type)
			{
			case TypeGame::Ground_Stair_Up:
				/*this->_stateCurrent == STATESIMON::UPING;*/
				this->_isOnStair = true;
				_vy = SIMON_VX_STAIR;
				_vx = SIMON_VX_STAIR;
				break;
			case TypeGame::Ground_Brick://ground
				this->_vx = 0;
				this->_vy = 0;
				break;
			default:
				break;
			}
		}
	}
	if (!collision &&  (Move_State != JUMP)) {
		this->Move_State = FALL;
		this->_vy = _gravity;
	}
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(2700, 300);
	return _simon;
}

Simon::~Simon() {
}

#endif
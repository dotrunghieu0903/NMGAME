#ifndef __SIMON_CPP__
#define __SIMON_CPP__

#include "Simon.h"

Simon* Simon::_simon = 0;

Simon::Simon() {
}

Simon::Simon(int x, int y) :BaseObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
	//_vy = SIMON_SPEED;
	_vy = 0;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 200);
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
	_Facing = FACE_LEFT;
	is_control = true;//note
	Move_State = STAND;
	this->_sptrite->SetFrame(0, 0);
}

void Simon::MoveUpdate(float deltaTime)
{
	
	last_x = _x;
	last_y = _y;
	if (this->Move_State == JUMP) {
		_vy += 0.1f;
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
	//xử lý nhảy
	if (Input::getCurrentInput()->IsKeyDown(DIK_SPACE) && (Move_State!=JUMP))
	{
		this->Jump();//set vx, vy
		presskey = true;
	}
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
	//xử lý ngồi
	if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN)) {
		this->Sit();
		/*this->_height -= 14;*/
		if (Move_State == SIT || Move_State == JUMP)
		{
			if (_height == SIMON_HEIGHT)
				_height -= 14;
		}
		else if (_height != SIMON_HEIGHT)
			_height = SIMON_HEIGHT;
	}
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

void Simon::Sit(){
	if (Move_State != JUMP && Move_State != TAIR && Action_State == REST) {
		_vx = 0.0f;
		_vy = SIMON_JUMP_SPEED;
		Move_State = SIT;
		this->_sptrite->SetFrame(4,4);
	}
}

void Simon::ReturnCheckCollision(vector<BaseObject*> lisobject, float dt){
	bool collision = false;
	for (int i = 0; i < lisobject.size(); i++) {
		int result = this->CheckCollision(lisobject[i], dt);
		if (result != COLLIDED_NONE) {
			collision = true;
			//function
			switch (lisobject[i]->_type)
			{
			case TypeGame::Ground_Stair_Up:
				_vy = SIMON_VX_STAIR;
				_vx = SIMON_VX_STAIR;
				break;
			case TypeGame::Ground_Brick://ground
				/*if (result == COLLIDED_TOP) {
					this->Land(lisobject[i]);
					Move_State = STAND;
				}*/
				_vy = 0;
				Move_State = STAND;

				
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

Box Simon::getBox() {
	return Box(this->_x+10, this->_y, this->_width-20, this->_height, _vx, _vy);
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(2700, 300);
	return _simon;
}

Simon::~Simon() {
}

#endif
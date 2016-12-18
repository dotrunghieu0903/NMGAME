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
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 150);
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
	_Facing = FACE_RIGHT;
	is_control = true;//note
	Move_State = STAND;
	this->_sptrite->SetFrame(0, 0);
	this->weapon = new Sprite(new Texture(L"resource\\sprite\\morningstar.png", 3, 3, 9), 70);
	this-> _index_weapon = WEAPON1;

	//this->stairOn = 
}

void Simon::Update(float deltatime) {
	if (_x > 3825 && _x < 3835 && _y > 1195 && _y < 1205) {
		this->stairOn = new Stair(3855, 1185, 1, 9);
		this->stairOn->inStep = 1;
	}
	if (Action_State == ATTACK) {
		_vx = 0;
		_sptrite->Update(deltatime/3);
	
		if (this->_sptrite->_index == 7 || this->_sptrite->_index == 17) {
			if (stop(80, deltatime)) { //delay 0.050s
				Action_State = REST;
			}
		}
		MoveUpdate(deltatime);
		return;
	}


	if (Move_State == TAIR) {
		if (stairOn->inStep > stairOn->_Lenght || stairOn->inStep < 1) {
			Move_State = STAND;
			return;
		}
		if (Input::getCurrentInput()->IsKeyDown(DIK_UP)) {
			//face
			if (this->stairOn->_Stair_Type == STAIR_UP) {
				_Facing = FACE_RIGHT;
			}
			else {
				_Facing = FACE_LEFT;
			}
			//other
			if (stop(250, deltatime)) {
				
				stairOn->inStep++;
				this->_x = stairOn->_x + 16 * stairOn->inStep - 40;
				this->_y = stairOn->_y - 16 * stairOn->inStep - this->_height + 34;
				
			}
			else {
				_vx = 0.09f;
				_vy = -0.04f;
				MoveUpdate(deltatime);
				this->_sptrite->_start = 12;
				this->_sptrite->_end = 13;
				_sptrite->Update(deltatime/4);
				
			}
		}
		if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN)) {
			//face
			if (this->stairOn->_Stair_Type == STAIR_UP) {
				_Facing = FACE_LEFT;
			}
			else {
				_Facing = FACE_RIGHT;
			}
			//other
			if (stop(250, deltatime)) {

				stairOn->inStep--;
				this->_x = stairOn->_x + 16 * stairOn->inStep - 40;
				this->_y = stairOn->_y - 16 * stairOn->inStep - this->_height + 34;

			}
			else {
				_vx = -0.06f;
				_vy = 0.05f;
				MoveUpdate(deltatime);
				this->_sptrite->_start = 10;
				this->_sptrite->_end = 11;
				_sptrite->Update(deltatime / 4);

			}
		}
		if((Input::getCurrentInput()->IsKeyDown(DIK_DOWN)== false)&&(Input::getCurrentInput()->IsKeyDown(DIK_UP) == false))
		//else
		{
			_vx = 0.0f;
			_vy = 0.0f;
			if (_Facing == FACE_RIGHT) {
				this->_sptrite->_index = 12;
			}
			else {
				this->_sptrite->_index = 10;
			}
			this->_x = stairOn->_x + 16 * stairOn->inStep - 40;
			this->_y = stairOn->_y - 16 * stairOn->inStep - this->_height + 34;
		}
		InputUpdate(deltatime);
		return;
	}


	InputUpdate(deltatime);
	_sptrite->Update(deltatime);
	MoveUpdate(deltatime);
}

void Simon::MoveUpdate(float deltaTime)
{
	
	last_x = _x;
	last_y = _y;
	if (this->Move_State == JUMP) {
		_vy += 0.08f;
	}
	else {
		if (this->Move_State == FALL) {
			_vy += 0.1f;
		}
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
	if (Input::getCurrentInput()->IsKeyDown(DIK_SPACE) && (Move_State!=JUMP) && (Move_State != SIT))
	{
		if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN)) { return; }
		this->Jump();//set vx, vy
		presskey = true;
	}
	// đi qua trái or phải

	if ((Input::getCurrentInput()->IsKeyDown(DIK_LEFT) || Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))&& (Move_State != JUMP) && (Move_State != FALL))
	{
		if (Move_State == TAIR) {
			if (Input::getCurrentInput()->IsKeyDown(DIK_RIGHT))
			{
				_Facing = FACE_RIGHT;
				if (this->stairOn->_Stair_Type == 1) {

				}
			}
			else
			{
				_Facing = FACE_LEFT;
			}
			return;
		}

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
	if (!presskey && (Move_State != JUMP) && (Move_State != FALL) && (Move_State != TAIR)) {
		Move_State = STAND;
		Action_State = REST;
		_vx = 0.0f;
		this->_sptrite->SetFrame(0, 0);
	}
	//xử lý ngồi
	if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN)) {
		if (Move_State == TAIR) {
			return;
		}
		this->stairOn = Stair::getTair(this->_x, this->_y, false);//check stair
		if (stairOn != nullptr) {
			Move_State = TAIR;
			this->_sptrite->SetFrame(10, 11);
			this->stairOn->inStep = this->stairOn->_Lenght;
			this->_x = stairOn->_x + 16 * stairOn->inStep - 40;
			this->_y = stairOn->_y - 16 * stairOn->inStep - this->_height + 34;
			if (stairOn->_Stair_Type == STAIR_UP) {
				this->_Facing = FACE_LEFT;
			}
			else {
				this->_Facing = FACE_RIGHT;
			}
		}
		else {
			this->Sit();
			/*this->_height -= 14;*/
			if (Move_State == SIT || Move_State == JUMP)
			{
				if (_height == SIMON_HEIGHT)
					_height -= 14;
			}
		}
	}
	else if (_height != SIMON_HEIGHT)
		_height = SIMON_HEIGHT;


	//up
	if (Input::getCurrentInput()->IsKeyDown(DIK_UP) && Move_State != TAIR) {
		this->stairOn = Stair::getTair(this->_x, this->_y, true);//check stair
		if (stairOn != nullptr) {
			Move_State = TAIR;
			this->_sptrite->SetFrame(12, 13);
			this->stairOn->inStep = 1;
			this->_x = stairOn->_x + 16 * stairOn->inStep - 40;
			this->_y = stairOn->_y - 16 * stairOn->inStep - this->_height + 34;
			if (stairOn->_Stair_Type == STAIR_UP) {
				this->_Facing = FACE_RIGHT;
			}
			else {
				this->_Facing = FACE_LEFT;
			}
		}
	}

	if (Input::getCurrentInput()->IsKeyDown(DIK_Z)) {//attack
	
		Action_State = ATTACK;
		if (Move_State == SIT) {
			this->_sptrite->SetFrame(15,17);
		}
		else {
			this->_sptrite->SetFrame(5, 7);
		}
	}

	
}

void Simon::Draw() {

	if (this->_sptrite->_index == 5 || this->_sptrite->_index == 15) {
		this->weapon->_index = this->_index_weapon;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x-58, this->_y);
		}
		else {
			this->weapon->Draw(this->_x+10, this->_y);
		}
		
	}

	if (this->_sptrite->_index == 6 || this->_sptrite->_index == 16) {
		this->weapon->_index = this->_index_weapon + 1;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x - 50, this->_y);
		}
		else {
			this->weapon->Draw(this->_x +10, this->_y);
		}

	}

	if (this->_sptrite->_index == 7 || this->_sptrite->_index == 17) {
		this->weapon->_index = this->_index_weapon + 2;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x + 40, this->_y);
		}
		else {
			this->weapon->Draw(this->_x - 80, this->_y);
		}

	}
	

	if (this->_Facing == FACE_RIGHT) {
		this->_sptrite->DrawFlipX(_x, _y);
	}
	else {
		this->_sptrite->Draw(_x, _y);
	}

	
}

Box Simon::getBoxWeapon() {
	if (this->_Facing == FACE_RIGHT) {
		switch (this->_index_weapon)
		{
		case WEAPON1:
			return Box(this->_x + 60, this->_y + 30, 55, 17);
			break;
		case WEAPON2:
			return Box(this->_x + 60, this->_y + 30, 55, 17);
			break;
		case WEAPON3:
			return Box(this->_x + 60, this->_y + 30, 80, 17);
			break;
		default:
			break;
		}
	}
	else {
		switch (this->_index_weapon)
		{
		case WEAPON1:
			return Box(this->_x - 55, this->_y + 30, 55, 17);
			break;
		case WEAPON2:
			return Box(this->_x - 55, this->_y + 30, 55, 17);
			break;
		case WEAPON3:
			return Box(this->_x - 80, this->_y + 30, 80, 17);
			break;
		default:
			break;
		}
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


//return collision
void Simon::ReturnCollisionTop(BaseObject * object) {
	this->_y = object->_y - this->_height;
	_vy = 0;
}

void Simon::ReturnCollisionLeft(BaseObject *object) {
	this->_x = object->_x - this->_width;
}

void Simon::ReturnCollisionRight(BaseObject *object) {
	this->_x = object->_x + object->_width;
}

void Simon::ReturnCollisionBot(BaseObject *object) {
	this->Move_State = FALL;
	_vy = 0;
}

bool Simon::CheckAttack(BaseObject* object2) {
	if (this->Action_State == ATTACK) {
		int a = 0;
	}
	if (this->Action_State == ATTACK && (this->_sptrite->_index == 7) || (this->_sptrite->_index == 17)) {

		Box thisBox = this->getBoxWeapon();
		if (thisBox.x + thisBox.w <= object2->getBox().x ||
			thisBox.y + thisBox.h <= object2->getBox().y ||
			thisBox.x >= object2->getBox().x + object2->getBox().w ||
			thisBox.y >= object2->getBox().y + object2->getBox().h)
		{
			return false;
		}
		return true;
	}
	else
	{
		return false;
	}

}

void Simon::ReturnCheckCollision(vector<BaseObject*> lisobject, float dt){

	if (Move_State == TAIR) {
		return;
	}
	bool collision = false;
	for (int i = 0; i < lisobject.size(); i++) {
		int result = 0;
			switch (lisobject[i]->_type)
			{
			case TypeGame::Ground_Stair_Up:
				_vy = SIMON_VX_STAIR;
				_vx = SIMON_VX_STAIR;
				break;
			case TypeGame::Ground_Brick://ground
				result = this->CheckCollision(lisobject[i], dt);
				if (result != COLLIDED_NONE && Move_State != TAIR) {
					collision = true;
					if (result == COLLIDED_TOP) {
						this->ReturnCollisionTop(lisobject[i]);
						Move_State = STAND;
					}
					if (result == COLLIDED_LEFT) {
						this->ReturnCollisionLeft(lisobject[i]);
					}
					if (result == COLLIDED_RIGHT) {
						this->ReturnCollisionRight(lisobject[i]);
					}
					if (result == COLLIDED_BOT) {
						this->ReturnCollisionBot(lisobject[i]);
					}
				}
				break;
			case TypeGame::Enemy_Knight:
				if (CheckAttack(lisobject[i])) {
					lisobject[i]->Damaged(50, dt);
				}
			case TypeGame::Enemy_Medusahead:
				if (CheckAttack(lisobject[i])) {
					lisobject[i]->Damaged(50, dt);
				}
				
				break;
			default:
				break;
			}
		}
	
	if ((!collision) &&  Move_State != JUMP && Move_State != TAIR) {
		this->Move_State = FALL;
		this->_vy = _gravity;
	}
}



Box Simon::getBox() {
	return Box(this->_x+10, this->_y, this->_width-20, this->_height, _vx, _vy);
}

void Simon::UpdateState(int face, MOVE_STATE state) {
	this->_Facing = face;
	this->Move_State = state;
}

Simon* Simon::getCurrentSimon() {
	if (!_simon)
		_simon = new Simon(2700, 300);
	return _simon;
}

Simon::~Simon() {
}

#endif
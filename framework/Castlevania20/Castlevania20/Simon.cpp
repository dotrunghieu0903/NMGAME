#ifndef __SIMON_CPP__
#define __SIMON_CPP__

#include "Simon.h"

Simon* Simon::_simon = 0;

Simon::Simon() {
}

Simon::Simon(int x, int y) :BaseObject(TYPE, x, y, SIMON_WIDTH, SIMON_HEIGHT)
{
	this->heath = 16;
	//_vy = SIMON_SPEED;
	_vy = 0;
	this->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 150);
	_box = Box(x, y, SIMON_WIDTH, SIMON_HEIGHT, _vx, _vy);
	_Facing = FACE_RIGHT;
	_currentStage = 1;
	_score = 0;
	_life = 3;
	_enemyHP = 16;
	is_control = true;//note
	Move_State = STAND;
	this->_sptrite->SetFrame(0, 0);
	this->weapon = new Sprite(new Texture(L"resource\\sprite\\morningstar.png", 3, 3, 9), 70);
	this-> _index_weapon = WEAPON1;


}

void Simon::Update( float deltatime) {
	if (heath <= 0) {
		if (timedie == 0) {
			this->Die();
			timedie += deltatime;
		}
		else {
			timedie += deltatime;
			if (timedie > 1000) {
				this->reborn();
			}
		}
		return;
	}

	if (atkend && Action_State!= REST)  {
		Action_State = REST;
		this->_sptrite->SetFrame(0, 0);
	}
	if (staging) {
		tickcount += deltatime;
		if (tickcount > 1000) {
			staging = false;
		}
		this->Move_State = MOVE;
		this->_vx = (_currentStage >= 7 ? (SIMON_SPEED - 0.1f) : -(SIMON_SPEED - 0.1f));
		this->_vy = 0.0f;
		this->_sptrite->_start = 1;
		_sptrite->Update(deltatime);
		MoveUpdate(deltatime);

		return;
	}
	if (is_wounded) {

		tickcount += deltatime;
		_vy += 0.055f;
		if (tickcount > 150) {
			is_control = true;
		}
		if (tickcount > 1500) {
			is_wounded = false;
			tickcount = 0;
		}
		InputUpdate(deltatime);
		MoveUpdate(deltatime);
		if (Action_State != ATTACK) {
			return;
		}
	}

	if (Action_State == ATTACK) {
		tickcount += deltatime;
		if (tickcount > 1000) {
			Action_State = REST;
			tickcount = 0;
		}
		if (this->Move_State != MOVE_STATE::JUMP) {
			_vx = 0;
		}
		_sptrite->Update(deltatime);
	
		if (this->_sptrite->_index == 7 || this->_sptrite->_index == 17 || this->_sptrite->_index == 23 || this->_sptrite->_index == 20) {
			atkend = true;
		}
		if (Move_State == JUMP && !is_wounded ) {
			if (_vy >0) {
				_vy += 0.1f;
			}
			else {
				_vy += 0.08f;
			}
		}
		if (Move_State == TAIR) {
			return;
		}
		MoveUpdate(deltatime);
		return;
	}

	

	switch (Move_State)
	{
	case TAIR: {
		if (stairOn->inStep > stairOn->_Lenght || stairOn->inStep < 1) {
			Move_State = STAND;
			break;
		}
		if (Input::getCurrentInput()->IsKeyDown(DIK_Z)) {
			PlaySound(attack);
			atkend = false;
			Action_State = ATTACK;
			if (this->stairOn->_Stair_Type == STAIR_UP) {
				if (_Facing == FACE_RIGHT) {
					this->_sptrite->SetFrame(21, 23);
				}
				else {
					this->_sptrite->SetFrame(18, 20);
				}
			}
			else {
				if (_Facing == FACE_LEFT) {
					this->_sptrite->SetFrame(21, 23);
				}
				else {
					this->_sptrite->SetFrame(18, 20);
				}
			}
			break;
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
				_sptrite->Update(deltatime / 4);

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
		if ((Input::getCurrentInput()->IsKeyDown(DIK_DOWN) == false) && (Input::getCurrentInput()->IsKeyDown(DIK_UP) == false))
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
		//InputUpdate(deltatime);
		break;
	}
	case FALL: {
		_vy += 0.2f;
		InputUpdate(deltatime);
		_sptrite->Update(deltatime);
		MoveUpdate(deltatime);
		break;
	}
	case SIT:
		break;
	case JUMP: {
		if  (_vy >0) {
			_vy += 0.1f;
		}
		else {
			_vy += 0.08f;
		}
		if (this->_height == SIMON_HEIGHT) {
			this->_height -= 12;
		}
		//break; use update
		InputUpdate(deltatime);
		_sptrite->Update(deltatime);
		MoveUpdate(deltatime);
		break;
	}
	default:
		InputUpdate(deltatime);
		_sptrite->Update(deltatime);
		MoveUpdate(deltatime);
		break;
	}

	if ( this->heath < 1 )
	{
		if ( _life > 0)
		{
			_life--;
			this->heath = 16;
			
		}
	}
}

void Simon::MoveUpdate(float deltatime)
{
	tickcountM += deltatime;
	if (tickcountM >= deltatime) {
		last_x = _x;
		last_y = _y;
		this->_x += _vx*deltatime;
		this->_y += _vy*deltatime;
		_sptrite->Update(deltatime);
		tickcountM = 0;
	}
}




void Simon::InputUpdate(float deltatime)
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
		if (!onCrossBar) {
			_vx = 0.0f;
		}
		this->_sptrite->SetFrame(0, 0);
	}
	//xử lý ngồi
	if (Input::getCurrentInput()->IsKeyDown(DIK_DOWN)) {
		if (Move_State == TAIR || is_wounded) {
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
					_height -= 12;
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
		PlaySound(attack);
		Action_State = ATTACK;
		atkend = false;
		if (Move_State == SIT) {
			this->_sptrite->SetFrame(15,17);
		}
		else {
			if (Move_State == TAIR) {

			}
			else {
				this->_sptrite->SetFrame(5, 7);
			}
		}
	}

	
}

void Simon::Draw() {
	if (this->_sptrite->_index == 5 || this->_sptrite->_index == 15 || this->_sptrite->_index == 18 || this->_sptrite->_index == 21) {
		this->weapon->_index = this->_index_weapon;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x-58, this->_y);
		}
		else {
			this->weapon->Draw(this->_x+10, this->_y);
		}
		
	}

	if (this->_sptrite->_index == 6 || this->_sptrite->_index == 16 || this->_sptrite->_index == 19 || this->_sptrite->_index == 22) {
		this->weapon->_index = this->_index_weapon + 1;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x - 50, this->_y);
		}
		else {
			this->weapon->Draw(this->_x +10, this->_y);
		}

	}

	if (this->_sptrite->_index == 7 || this->_sptrite->_index == 17 || this->_sptrite->_index == 20 || this->_sptrite->_index == 23) {
		this->weapon->_index = this->_index_weapon + 2;
		if (this->_Facing == FACE_RIGHT) {
			this->weapon->DrawFlipX(this->_x + 33, this->_y);
		}
		else {
			this->weapon->Draw(this->_x - 80, this->_y);
		}

	}
	

	if (is_wounded) {
		int count = GetTickCount() - tickcountW;
		if (count > 100) {
			tickcountW = GetTickCount();
			return;
		}
	}
	int fix = ((this->_sptrite->_index == 4 || 
		(this->_sptrite->_index >= 15 && this->_sptrite->_index <= 17)) ? 8 : 0);
	if (this->_Facing == FACE_RIGHT) {
		this->_sptrite->DrawFlipX(_x , _y + fix);
	}
	else {
		this->_sptrite->Draw(_x, _y + fix);
	}

	
}

Box Simon::getBoxWeapon() {
	if (this->_Facing == FACE_RIGHT) {
		switch (this->_index_weapon)
		{
		case WEAPON1:
			return Box(this->_x + 33, this->_y + 29, 65, 22, _vx,_vy);
			break;
		case WEAPON2:
			return Box(this->_x + 33, this->_y + 29, 65, 22, _vx, _vy);
			break;
		case WEAPON3:
			return Box(this->_x + 33, this->_y + 29, 90, 22, _vx, _vy);
			break;
		default:
			break;
		}
	}
	else {
		switch (this->_index_weapon)
		{
		case WEAPON1:
			return Box(this->_x - 70, this->_y + 30, 65, 17, _vx, _vy);
			break;
		case WEAPON2:
			return Box(this->_x - 70, this->_y + 30, 65, 17, _vx, _vy);
			break;
		case WEAPON3:
			return Box(this->_x - 70, this->_y + 30, 90, 17, _vx, _vy);
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
		PlaySound(falling);
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
	int a = 0;
	this->_x = object->_x - this->_width + 3;
}

void Simon::ReturnCollisionRight(BaseObject *object) {
	this->_x = object->_x + object->_width -3;
}

void Simon::ReturnCollisionBot(BaseObject *object) {
	this->Move_State = FALL;
	_vy = 0;
}

bool Simon::CheckAttack(BaseObject* object2) {
	if (this->Action_State != ATTACK) {
		return false;
	}
	if (this->Action_State == ATTACK && (this->_sptrite->_index == 7 || this->_sptrite->_index == 17 || this->_sptrite->_index == 21 || this->_sptrite->_index == 23)) {
		if (AABBCheck(this->getBoxWeapon(), object2->getBox())) {
			return true;
		}
		else
		{
			if (this->CheckCollision(this->getBoxWeapon(), object2->getBox(), true, 32.0f) != COLLIDED_NONE) {
				return true;
			}
		}
	}
	return false;

}

void Simon::ReturnCheckCollision(vector<BaseObject*> lisobject, float dt){
	bool collision = false;
	int now = GetTickCount();
	for (int i = 0; i < lisobject.size(); i++) {
		int result = 0;
		if (lisobject[i]->_id == 97) {
			int a = 0;
		}
		result = this->CheckCollision(lisobject[i], dt);
			switch (lisobject[i]->_type)
			{
			case TypeGame::Ground_Brick://ground
				if (((Ground*)lisobject[i])->collission_bot) {
					break;
				}
				if (result != COLLIDED_NONE && Move_State != TAIR) {
					collision = true;
					if (result == COLLIDED_TOP) {
						this->ReturnCollisionTop(lisobject[i]);
						standOn = lisobject[i];
						Move_State = STAND;
					}
     					if (result == COLLIDED_LEFT) {
						this->ReturnCollisionLeft(lisobject[i]);
					}
					if (result == COLLIDED_RIGHT) {
						this->ReturnCollisionRight(lisobject[i]);
					}
					if (result == COLLIDED_BOT) {
						if (lisobject[i]->_id == 101 || lisobject[i]->_id == 102) {
							this->ReturnCollisionBot(lisobject[i]);
						}
					}
				}
				break;
			case TypeGame::Ground_Moving_Brick://crossbar
				if (result != COLLIDED_NONE && Move_State != TAIR) {
					if (result == COLLIDED_TOP) {
						this->ReturnCollisionTop(lisobject[i]);
						Move_State = STAND;
						this->_vx = lisobject[i]->_vx;
						collision = true;
						this->onCrossBar = true;
					}
				}
				else {
					this->onCrossBar = false;
				}
				break;
			case TypeGame::Ground_Lockdoor://Ground_Lockdoor
				if (result != COLLIDED_NONE && Move_State != TAIR) {
					if (((BlockDoor*)lisobject[i])->getType() == TYPE_DOOR::GO_RIGHT) {
						if (result == COLLIDED_RIGHT) {
							this->ReturnCollisionRight(lisobject[i]);
							break;
						}
						if (result == COLLIDED_LEFT ) {
							if (Move_State == MOVE_STATE::JUMP || lisobject[i]->_id == 125) {
								this->ReturnCollisionLeft(lisobject[i]);
								break;
							}
							((BlockDoor*)lisobject[i])->Open();
							this->staging = true;
						}
						
					}
					if (((BlockDoor*)lisobject[i])->getType() == TYPE_DOOR::GO_LEFT) {
						if (result == COLLIDED_LEFT) {
							this->ReturnCollisionLeft(lisobject[i]);
							break;
						}
						if (result == COLLIDED_RIGHT) {
							if (Move_State == MOVE_STATE::JUMP || lisobject[i]->_id == 125) {
								this->ReturnCollisionRight(lisobject[i]);
								break;
							}
							((BlockDoor*)lisobject[i])->Open();
							this->staging = true;
						}
					}
				}
				break;
			case TypeGame::Ground_Firecandle:
				if (CheckAttack(lisobject[i]) && (now - last_attack > 200)) {
					lisobject[i]->Damaged(50, dt);
					last_attack = now;
				}
				break;
			case TypeGame::Enemy_DragonSkull:
			case TypeGame::Ground_Trap:
			case TypeGame::Enemy_Knight:
			case TypeGame::Enemy_Medusahead:
			case TypeGame::Enemy_Ghost:
			case TypeGame::Boss_Medusa:
#pragma region GROUND TRAP
				if (lisobject[i]->_type == TypeGame::Ground_Trap) {
					if (is_wounded) {
						break;
					}
					int rs = lisobject[i]->CheckCollision(this, dt);
					if (rs == COLLIDED_IN) {
						_vy = -0.47f;
						Move_State = MOVE_STATE::JUMP;
						this->_sptrite->SetFrame(8, 8);
						if (this->_Facing == FACE_LEFT) {
							_Facing = FACE_LEFT;
							_vx = -0.1f;
						}
						else {
							_Facing = FACE_RIGHT;
							_vx = 0.1f;
						}
						is_wounded = true;
						this->heath -= SIMON_HEATH_DAMAGED;
						is_control = false;
						break;
					}
				}
#pragma endregion

#pragma region DragonSkull
				if (lisobject[i]->_type == TypeGame::Enemy_DragonSkull) {
					DragonSkull *dragon = ((DragonSkull*)lisobject[i]);
					for each (FireBall * fireball in dragon->_listFireBall){
						//check attack
						if (CheckAttack(fireball) && (now - last_attack > 200)) {
							fireball->Damaged(50, dt);
							last_attack = now;
						}
						//check collision
						if (is_wounded) {
							break;
						}
						int rs = this->CheckCollision(fireball, dt);
						if (rs != COLLIDED_NONE) {
							if (rs != COLLIDED_BOT) {
								_vy = -0.6f;
							}
							Move_State = MOVE_STATE::JUMP;
							this->_sptrite->SetFrame(8, 8);
							if (rs == COLLIDED_LEFT) {
								_Facing = FACE_LEFT;
								_vx = -0.1f;
							}
							if (rs == COLLIDED_RIGHT) {
								_Facing = FACE_RIGHT;
								_vx = 0.1f;
							}
							is_wounded = true;
							is_control = false;
						}
					}
				}
#pragma endregion

#pragma region Boss_Medusa
				if (lisobject[i]->_type == TypeGame::Boss_Medusa) {
					MedusaQueen *medusa = ((MedusaQueen*)lisobject[i]);
					Snake *snake = medusa->getSnake();
					if (snake != nullptr) {
						//check attack
						if (CheckAttack(snake) && (now - last_attack > 200)) {
							snake->Damaged(50, dt);
							last_attack = now;
						}
						//check collision
						if (is_wounded) {
							break;
						}
						int rs = this->CheckCollision(snake, dt);
						if (rs != COLLIDED_NONE) {
							_vy = -0.6f;
							Move_State = MOVE_STATE::JUMP;
							this->_sptrite->SetFrame(8, 8);
							if (rs == COLLIDED_LEFT) {
								_Facing = FACE_LEFT;
								_vx = -0.1f;
							}
							if (rs == COLLIDED_RIGHT) {
								_Facing = FACE_RIGHT;
								_vx = 0.1f;
							}
							is_wounded = true;
							this->heath -= SIMON_HEATH_DAMAGED;
							is_control = false;
						}
					}
				}
#pragma endregion

#pragma region GENERAL

				
				if (CheckAttack(lisobject[i]) && (now - last_attack > 200)) {
					lisobject[i]->Damaged(50, dt);
					last_attack = now;
				}
		
				if (is_wounded) {
					break;
				}
				
				
				if (result != COLLIDED_NONE) {
					_vy = -0.6f; 
					Move_State = MOVE_STATE::JUMP;
					this->_sptrite->SetFrame(8, 8);
					if (result == COLLIDED_LEFT) {
						_Facing = FACE_LEFT;
						_vx = -0.1f;
					}
					if (result == COLLIDED_RIGHT) {
						_Facing = FACE_RIGHT;
						_vx = 0.1f;
					}
					is_wounded = true;
					this->heath -= SIMON_HEATH_DAMAGED;
					is_control = false;
					if ( lisobject[i]->_type == TypeGame::Enemy_Ghost) {
						lisobject[i]->heath = -1;
						lisobject[i]->Die();
					}
				}
#pragma endregion
				break;
			default:
				break;
			}
		}
	
	if ((!collision) &&  Move_State != JUMP && Move_State != TAIR && Move_State != DINHCHUONG) {
		this->Move_State = FALL;
		this->_vy = _gravity;
	}
}

Box Simon::getBox(BaseObject *object2) {
	return Box(this->_x+10, this->_y, this->_width-20, (Move_State == JUMP || Move_State == SIT ? this->_height - 14 : this->_height), this->_vx - object2->_vx, _vy - object2->_vy);
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

void Simon::goStage(int stage) {
	_currentStage = stage;
	int current_stage = stage - 1;
	switch (current_stage)
	{
	case 1: {
		this->stairOn = new Stair(3855, 1185, 1, 9);
		this->stairOn->inStep = 1;
		break;
	}
	case 3: {
		this->stairOn = new Stair(1664, 818, 1, 4);
		this->stairOn->inStep = 1;
		break;
	}
	case 5: {
		this->stairOn = new Stair(1344, 432, 1, 6);
		this->stairOn->inStep = 1;
		break;
	}
	case 2:
	case 4:
	case 6: {//7
		this->_sptrite->_start = 1;
		this->_sptrite->_start = 3;
		this->staging = true;
		if (stage == 7) {
			Move_State = MOVE;
			_vx = SIMON_SPEED;
			this->_x = 2693;
			this->_y = 230;
		}
		break;
	}
	default:
		break;
	}
}

void Simon::Die() {
	delete _sptrite;
	this->_sptrite = new Sprite(new Texture(SIMON_DEATH), 30);
	this->_vx = 0.0f;
	this->_vy = 0.0f;
}

void Simon::reborn() {
	if(_life < 0) {
		_life--;
	}else {
		heath = 16;
		_life--;
		//remove weapon
		timedie = 0;
		atkend = false;
		_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 150);
		this->_sptrite->SetFrame(0, 0);
		this->_index_weapon = WEAPON1;
		switch (_currentStage)
		{
		case 1: {
			this->_x = 3646;
			this->_y = 1500;
			break;
		}
		case 2: {
			this->_x = 3866;
			this->_y = 909;
			break;
		}
		case 3: {
			this->_x = 3005;
			this->_y = 924;
			break;
		}
		case 4: {
			this->_x = 1737;
			this->_y = 700;
			break;
		}
		case 5: {
			this->_x = 1489;
			this->_y = 607;
			break;
		}
		case 6: {
			this->_x = 1360;
			this->_y = 254;
			break;
		}
		default:
			break;
		}
	}
}

void Simon::PickUpItem(ITEM * item)
{
	switch (item->GetItemType())
	{
	case Item_small_heart:
		_heartNum++;
		PlaySound(collect_heart);
		break;
	case Item_big_heart:
		_heartNum += 5;
		PlaySound(collect_heart);
		break;
	case Item_double_shot:
		_index_weapon = WEAPON::WEAPON2;
		PlaySound(collect_weapon);
		break;
	case Item_money_bag:
		_score += 400;
		PlaySound(collect_item);
		break;
	case Item_morning_star:
		PlaySound(collect_weapon);
		break;
	case Item_roast:
		PlaySound(collect_item);
		break;
	case Item_rosary:
		PlaySound(rosary);
		break;
	case Item_spirit_ball:
		PlaySound(rosary);
		
		PlaySound(clear);
		break;
	case Item_knife:
		_currentWeapon = WEAPONNAME::Knife;
		PlaySound(collect_weapon);
		break;
	case Item_axe:
		_currentWeapon = WEAPONNAME::Axe;
		PlaySound(collect_weapon);
		break;
	case Item_holy_water:
		_currentWeapon = WEAPONNAME::HollyWater;
		PlaySound(collect_weapon);
		break;
	case Item_stop_watch:
		_currentWeapon = WEAPONNAME::Watch;
		PlaySound(collect_weapon);
		break;
	case Item_cross:
		_currentWeapon = WEAPONNAME::Cross;
		PlaySound(collect_weapon);
		break;
	default:
		break;
	}
}
#endif
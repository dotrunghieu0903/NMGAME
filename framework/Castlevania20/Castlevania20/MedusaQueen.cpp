#include "MedusaQueen.h"



MedusaQueen::MedusaQueen()
{
}

MedusaQueen::MedusaQueen(int id, int x, int y) : BaseObject(TYPE,x,y, MEDUSA_WIDTH,MEDUSA_HEIGHT){
	tick = 0;
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(MEDUSA_SPRITE, 5,1,5), 70);
	this->_vx = 0;
	this->_vy = 0;
	this->state = ENEMY_STAGE::WAIT;
	this->_sptrite->SetFrame(4, 4);
	this->heath = 400;
	//snake =  new Snake(x+30, y,)
}

void MedusaQueen::MoveUpdate(int simon_x, int simon_y, float deltatime) {
	if (this->heath <= 0) {
		this->state = ENEMY_STAGE::DIE;
		if (timedie == 0) {
			this->Die();
		} 
		timedie += deltatime;
	}
	else {
		if (damaged) {
			this->state = ENEMY_STAGE::DAMAGED;
		}
	}
	tickcount += deltatime;

	switch (state)
	{
	case WAIT:
		if (simon_x < _x + 210 && simon_x > _x - 210) {
			tick += deltatime;
		}
		if (tick > 4000) {
			this->state = RIGHT;
			this->_sptrite->SetFrame(0, 3);
		}
		break;
	case DAMAGED:
		tickcount += deltatime;
		if (tickcount > 50) {
			state = ENEMY_STAGE::RIGHT;
			this->damaged = false;
			tickcount = 0.0f;
		}
		break;
	case DIE:
		if (timedie > 300) {
			is_remove = true;
		}
		break;
	case END:
		break;
	default://left or right

		//medusa move
		if (_x + _width / 2 < simon_x) {
			_vx = MEDUSA_SPEED;
		}
		else {
			if (_x > simon_x + 32) {
				_vx = -MEDUSA_SPEED;
			}
			else {
				_vx = 0;
			}
		}


		if (_y + _height < simon_y + 30) {
			_vy = MEDUSA_SPEED;
		}
		else {
			if (_y > simon_y + 30) {
				_vy = -MEDUSA_SPEED;
			}
			else {
				_vy = 0;
			}
		}

		//snake
		if (tickcount > 3000) {
			snake = new Snake(_x+30, _y, simon_x < _x + 20);
			tickcount = 0;
		}
		if (snake != nullptr) {
			snake->Update(simon_x, simon_y, deltatime);

			if (snake->is_remove) {
				delete snake;
				snake = nullptr;
			}
			tickcount = 0;
		}

		//test
		_x = 215;
		_y = 251;

		UpdatePosition(deltatime);
		break;
	}
}

void MedusaQueen::Die() {
	delete _sptrite;
	this->_sptrite = new Sprite(new Texture(DIE_SPRITE, 3, 1, 3), 100);
	this->_vx = 0.0f;
	this->_vy = 0.0f;
}

Snake * MedusaQueen::getSnake() {
	return snake;
}

void MedusaQueen::Draw() {
	this->_sptrite->Draw(_x, _y);
	if (snake != nullptr) {
		snake->Draw();
	}
}


MedusaQueen::~MedusaQueen()
{
}

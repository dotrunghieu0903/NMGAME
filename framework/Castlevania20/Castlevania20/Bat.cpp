#include "Bat.h"

Bat::Bat()
{
}

Bat::Bat(int id,int x,int y): BaseObject(TYPE,x,y,_batWIDTH,_batHEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(BAT_SPRITE,1,1,1),50);
	_isSleep = true;
	_vx = BAT_SPEED;
	//_box = new Box(x,y, _batWIDTH, _batHEIGHT, _vx, _vy);
	/*_awakeBox = new Box(x,y,);
	_damage = DAMAGE;*/
	this->heath = HP;
}

void Bat::MoveUpdate(float deltatime) {
	if (this->_isSleep) {
		this->_sptrite->SetFrame(0, 0);
		return;
	}
	if (ENEMY_STAGE::LEFT) {
		_vx *= -1;
		this->_sptrite->SetFrame(1, 1);
	}
	this->_x += int(this->_vx * deltatime);
	this->_temp += (this->_vx * deltatime / 10);
	this->_y += int(3 * sin(float(_temp)));
}

void Bat::ChangeState(int state) {
	if (state == BATSTATE::isSleep) {
		this->_isSleep = true;
	}
	else
		if (state == BATSTATE::isAwake) {
			this->_isSleep = false;
		}
}

void Bat::Update(float deltatime) {
	if (heath == 0) {
		ENEMY_STAGE::DIE;
	}
}

void Bat::Collistion(float deltatime) {
	if (heath == 0) {
		return;
	}
}

void Bat::Draw() {
	this->_sptrite->Draw(_x,_y);
}

Bat::~Bat()
{
}

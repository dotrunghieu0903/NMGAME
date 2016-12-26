#include "BaseObject.h"

BaseObject::BaseObject(int type, int x, int y, int width, int height)
{
	_type = type;
	_x = x;
	_y = y;
	_vx = 0;
	_vy = 0;
	last_x = 0;
	last_y = 0;
	_gravity = GRAVITY;
	_width = width;
	_height = height;
}

BaseObject::BaseObject(int type, int x, int y, int width, int height, RECT rect)
{
	_type = type;
	_x = x;
	_y = y;
	last_x = 0;
	last_y = 0;
	_vx = 0;
	_vy = 0;
	_gravity = GRAVITY;

	_width = width;
	_height = height;

	_bound = rect;
}


void BaseObject::UpdatePosition(int time)
{
	//_vy += _gravity * time;
	_x += int(_vx * time);
	_y += int(_vy * time);
}

void BaseObject::Die() {
	this->_sptrite = new Sprite(new Texture(FIRE_SPRITE, 2, 1, 2), 30);
	this->_vx = 0.0f;
	this->_vy = 0.0f;
}


int BaseObject::CheckCollision(BaseObject *object2, float deltatime) {
 	Box thisBox = this->getBox(object2);
	Box objectBox = object2->getBox();

	if (thisBox.x + thisBox.w >= object2->getBox().x &&
		thisBox.y + thisBox.h >= object2->getBox().y &&
		thisBox.x <= object2->getBox().x + object2->getBox().w &&
		thisBox.y <= object2->getBox().y + object2->getBox().h && object2->_type != TypeGame::Ground_Brick)
	{
//		return COLLIDED_IN;
	}
	Box broadphasebox = GetSweptBroadphaseBox(thisBox, deltatime);
	if (!AABBCheck(broadphasebox, objectBox)) {
		return COLLIDED_NONE;
	}
	

 	int a = 0;
	//return COLLIDED_RIGHT;

	float KhoangCachDen_x, KhoangCachDen_y;
	float KhoangCachRa_x, KhoangCachRa_y;
	if (thisBox.vx > 0.0f) {
		KhoangCachDen_x = objectBox.x - (thisBox.x + thisBox.w);
		KhoangCachRa_x = (objectBox.x + objectBox.w) - thisBox.x;
	}
	else {
		KhoangCachDen_x = (objectBox.x + objectBox.w) - thisBox.x;
		KhoangCachRa_x = objectBox.x - (thisBox.x + thisBox.w);
	}

	if (thisBox.vy > 0.0f)
	{
		KhoangCachDen_y = objectBox.y - (thisBox.y + thisBox.h);
		KhoangCachRa_y = (objectBox.y + objectBox.h) - thisBox.y;
	}
	else
	{
		KhoangCachDen_y = (objectBox.y + objectBox.h) - thisBox.y;
		KhoangCachRa_y = objectBox.y - (thisBox.y + thisBox.h);
	}

	float ThoiGianVaCham_x, ThoiGianHetVaCham_x;
	float ThoiGianVaCham_y, ThoiGianHetVaCham_y;
	//t = S/v

	//neu van toc  = 0
	if (thisBox.vx == 0.0f) { // da va cham,hoacko va cham
		//thoi giam va cham cuc nho ???
		ThoiGianVaCham_x = -INFINITY;
		//thoi gian het va cham cuc lon
		ThoiGianHetVaCham_x = INFINITY;
	}
	else { //t = s/v
		ThoiGianVaCham_x = KhoangCachDen_x / thisBox.vx;
		ThoiGianHetVaCham_x = KhoangCachRa_x / thisBox.vx;
	}

	//neu van toc  = 0
	if (thisBox.vy == 0.0f) { // da va cham,hoacko va cham
		//thoi giam va cham cuc nho ???
		ThoiGianVaCham_y = -INFINITY;
		//thoi gian het va cham cuc lon
		ThoiGianHetVaCham_y = INFINITY;
	}
	else { //t = s/v
		ThoiGianVaCham_y = KhoangCachDen_y / thisBox.vy;
		ThoiGianHetVaCham_y = KhoangCachRa_y / thisBox.vy;
	}

	//va cham x truoc hay va cham y truoc
	float ThoiGianVaCham = ThoiGianVaCham_x > ThoiGianVaCham_y ? ThoiGianVaCham_x : ThoiGianVaCham_y;
	//het va cham x truoc hay het va cham y truoc
	float ThoiGianHetVaCham = ThoiGianHetVaCham_x < ThoiGianHetVaCham_y ? ThoiGianHetVaCham_x : ThoiGianHetVaCham_y;

	//truong hop khong co va cham
	if (
		ThoiGianVaCham > ThoiGianHetVaCham ||
		(ThoiGianVaCham_x < 0.0f && ThoiGianVaCham_y < 0.0f) || // cang ngay cang xa //ThoiGianVaCham < 0.0f
		ThoiGianVaCham_x > deltatime||
		ThoiGianVaCham_y > deltatime) {
		if (objectBox.y + objectBox.h > thisBox.y + thisBox.h && thisBox.x < (objectBox.x + objectBox.w) && (thisBox.x + thisBox.w) > objectBox.x) {
			return COLLIDED_TOP;
		}
		return COLLIDED_NONE;
		//return noclission
	}
	//if (KhoangCachDen_y < 0.0f || KhoangCachDen_x <0.0f)//da co va cham
	//{
	//	if (objectBox.y + objectBox.h > thisBox.y + thisBox.h && thisBox.x < (objectBox.x + objectBox.w) && (thisBox.x + thisBox.w) > objectBox.x) {
	//		return COLLIDED_TOP;
	//	}
	//}
	//if (ThoiGianVaCham > 0.0f && ThoiGianVaCham < deltatime) {
		if (ThoiGianVaCham_x > ThoiGianVaCham_y) { //va cham x => left or right
			if (KhoangCachDen_x > 0.0f) {
				return COLLIDED_LEFT;
			}
			else {
				return COLLIDED_RIGHT;
			}
		}
		else {
			if (KhoangCachDen_y > 0.0f) {
				return COLLIDED_TOP;
			}
			else {
				return COLLIDED_BOT;
			}
		}
	//}
}

Box BaseObject::getBox() {
	return Box(this->_x, this->_y, this->_width, this->_height, _vx, _vy);
}

Box BaseObject::getBox(BaseObject *object2) {
	return Box(this->_x, this->_y, this->_width, this->_height, _vx - object2->_vx, _vy - object2->_vy);
}


void BaseObject::Update(float deltatime){
	UpdateEvent(deltatime);
	InputUpdate(deltatime);
	SetFrame(deltatime);
	_sptrite->Update(deltatime);
	MoveUpdate(deltatime);
}

void BaseObject::Update(int simon_x, int simon_y, float deltatime) {
	MoveUpdate(simon_x, simon_y,deltatime);
	InputUpdate(deltatime);
	SetFrame(deltatime);
	_sptrite->Update(deltatime);
	MoveUpdate(deltatime);
}

bool BaseObject::stop(float time, float deltatime) {
	if (this->tickcount > time) {
		tickcount = 0.0f;
		return true;
	}
	else {
		this->tickcount += deltatime;
		return false;
	}
}

void BaseObject::Damaged(int h, float dt) {	
	if (!this->damaged) {//khac dinh damage
		this->heath -= h;
		damaged = true;
	}

}

BaseObject::~BaseObject()
{

}
BaseObject::BaseObject()
{

}
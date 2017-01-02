#include "BlockDoor.h"

#define DOOR_SPRITE			L"resource\\sprite\\ground\\Gate1.png"
#define DOOR_WIDTH			16
#define DOOR_HEIGHT			64

#define TYPE 16

BlockDoor::BlockDoor()
{
}

BlockDoor::BlockDoor(int id, int x, int y) :BaseObject(TYPE, x + 13, y, DOOR_WIDTH, DOOR_HEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(DOOR_SPRITE, 4, 1, 4), 500);
	this->_sptrite->SetFrame(0, 0);
	//this->opening = true;
}

void BlockDoor::SetFrame(float detaTime) {
	if (opening) {
		this->_sptrite->SetFrame(0, 2);
	}
	else {
		if (closing) {
			this->_sptrite->SetFrame(3, 3);
		}
	}
	if (this->_sptrite->_index == 2 && opening) {
		this->_sptrite->SetFrame(2, 2);
	}
	if (!closing && !opening) {
		this->_sptrite->SetFrame(0, 0);
	}
}
void BlockDoor::Open() {
	this->opening = true;
}

TYPE_DOOR BlockDoor::getType() {
	if (this->_id == 14 || this->_id == 17) {
		return  TYPE_DOOR::GO_RIGHT;
	}
	return TYPE_DOOR::GO_LEFT;
}
void BlockDoor::Draw() {
	this->_sptrite->Draw(_x, _y);
}

BlockDoor::~BlockDoor()
{
}

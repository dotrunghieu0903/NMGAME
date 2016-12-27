#include "Item.h"
#include "Resources.h"
#include <d3dx9.h>
#include <stdio.h>

extern vector<BaseObject*> listObject;

ITEM::ITEM()
{
}

ITEM::ITEM(int Item_Type, int X, int Y) :
	BaseObject(Item_Type, X, Y, ITEM_WIDTH, ITEM_HEIGHT)
{
	_gravity = GRAVITY / 3.0f;
	item_type = Item_Type;
	appear_time = GetTickCount();
	landed = false;
	_gravity = 0;
	_vy = 0.1f;
	heath = 1;
	last_time = 0.0f;
	this->_id = Item_Type;
	this->_sptrite = new Sprite(new Texture(ITEM_PATH, 1, 1, 1), 100);
	switch (item_type)
	{
	case ITEM_BIG_HEART:
		_width = _height = 20;
		break;
	case ITEM_MONEY_BAG:
		_width = _height  = 30;
		break;
	case ITEM_AXE:
		_width = _height  = 30;
		break;
	case ITEM_CROSS:
		_width = _height  = 30;
		break;
	case ITEM_KNIFE:
		_width = _height  = 21;
		break;
	case ITEM_HOLY_WATER:
		_width = _height  = 32;
		break;
	case ITEM_STOP_WATCH:
		_width = _height  = 30;
		break;
	case ITEM_MORNING_STAR:
		_width = _height  = 32;
		break;
	case ITEM_DOUBLE_SHOT:
		_width = _height  = 28;
		break;
	case ITEM_ROAST:
		_width = _height  = 26;
		break;
	case ITEM_ROSARY:
		_width = _height  = 34;
		break;
	case ITEM_SPIRIT_BALL:
		_width = _height  = 32;
		break;
	default:
		_width = _height  = 16;
		break;
	}

}

void ITEM::Update(int deltatime)
{
	UpdateEvent(deltatime);
}

void ITEM::UpdateEvent(int deltatime)
{
	if ( item_state != ALIVE )
	{
		return;
	}
	if ( last_time > 999999999 && item_state == ALIVE) // 5000 : time item exist
	{
		item_state = DESTROYED;
		this->Die();
		return;
	}
	if (item_type == ITEM_SMALL_HEART && !landed)
	{
		_vx = (float)cos((double)GetTickCount() / 150) *0.1f;
	}

	UpdatePosition(deltatime);
	last_time += deltatime;
}

void ITEM::ReturnCheckCollision(vector<BaseObject*> listobject, float dt) {

	bool collision = false;
	for (int i = 0; i < listobject.size(); i++) {
		int result = 0;
		switch (listobject[i]->_type)
		{
		case TypeGame::Ground_Brick://ground
			result = this->CheckCollision(listobject[i], dt);
			if (result != COLLIDED_NONE) {
				collision = true;
				this->_vy = 0.0f;
				this->_vx = 0.0f;
				landed = true;
			}
			break;
		default:
			break;
		}
	}

	if (collision) 
	{
		this->_vy = 0.0f;
		this->_vx = 0.0f;
		landed = true;
	}
}

void ITEM::Draw()
{
	this->_sptrite->DrawRect(_x, _y, GetAnimateRect(item_type));
}

ITEM::~ITEM() {
	
}
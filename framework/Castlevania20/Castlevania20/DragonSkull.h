#ifndef __DragonSkull_H__
#define __DragonSkull_H__
#pragma once
#include "FireBall.h"
#include"BaseObject.h"

#define DRAGON_SPRITE		L"resource\\sprite\\enemy\\8.png"
#define DRAGON_WIDTH		32
#define DRAGON_HEIGHT		64
#define TIMEFIRE			1700
#define TIMEFIRE2			500
#define TYPE 4

enum SHOT {
	shot1, shot2
};

class DragonSkull :
	public BaseObject
{
private:
	ENEMY_STAGE state;
	SHOT shot;
public:
	DragonSkull();
	DragonSkull(int id, int x, int y);
	void MoveUpdate(int simon_x, int simon_y, float deltatime);//update event
	void Fire();
	void Draw();
	vector<BaseObject*> _listFireBall;
	~DragonSkull();
};
#endif

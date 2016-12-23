#ifndef _GHOST_H_
#define _GHOST_H_

#pragma once
#include "BaseObject.h"

#define GHOST_SPRITE		L"resource\\sprite\\enemy\\9.png"
#define GHOST_WIDTH			28
#define GHOST_HEIGHT		28
#define GHOST_SPEED			0.15f

#define TYPE 5


class Ghost :
	public BaseObject
{
private:
	ENEMY_STAGE stage;
	bool is_left;
public:
	Ghost();
	Ghost(int id, int x, int y);
	void MoveUpdate(int simon_x,int simon_y, float deltatime);
	void Draw();
	~Ghost();
};


#endif
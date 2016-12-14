#ifndef _GHOST_H_
#define _GHOST_H_

#pragma once
#include "BaseObject.h"

#define GHOST_SPRITE		L"resource\\sprite\\enemy\\1.png"
#define GHOST_WIDTH			32
#define GHOST_HEIGHT		64
#define GHOST_SPEED			0.18f

#define TYPE 5


class Ghost :
	public BaseObject
{
private:
	ENEMY_STAGE stage;
public:
	Ghost();
	Ghost(int id, int x, int y, RECT rect);
	void MoveUpdate(float deltatime);
	void Draw();
	~Ghost();
};


#endif
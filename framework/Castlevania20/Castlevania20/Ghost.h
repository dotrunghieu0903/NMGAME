#ifndef _GHOST_H_
#define _GHOST_H_

#pragma once
#include "BaseObject.h"

#define GHOST_SPRITE		L"resource\\sprite\\enemy\\1.png"
#define GHOST_WIDTH			32
#define GHOST_HEIGHT		64
#define GHOST_SPEED			0.18f

#define TYPE 5

enum STATEGHOST
{
	WAIT = 1, // đang chờ được load lên game
	LEFT = 2,// đang đi qua bên trái
	RIGHT = 3,//đang đi qua bên phải
	DIE = 4,//đang chết
	END = 5,//kết thúc, loại bỏ khỏi game
};

class Ghost :
	public BaseObject
{
private:
	STATEGHOST stage;
public:
	Ghost();
	Ghost(int x, int y, RECT rect);
	void MoveUpdate(float deltatime);
	void Draw();
	~Ghost();
};


#endif
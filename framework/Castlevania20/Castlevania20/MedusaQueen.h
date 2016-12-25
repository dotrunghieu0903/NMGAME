#pragma once
#include "BaseObject.h"
#include "Snake.h"

#define MEDUSA_SPRITE		L"resource\\sprite\\boss\\1.png"
#define MEDUSA_WIDTH			65
#define MEDUSA_HEIGHT			64
#define MEDUSA_SPEED			0.1f

#define TYPE 0

class MedusaQueen :
	public BaseObject
{
private:
	int tick;
	ENEMY_STAGE state;
	Snake *snake;
public:
	MedusaQueen();
	MedusaQueen(int id, int x, int y);
	void MoveUpdate(int simon_x, int simon_y, float deltatime);
	void Draw();
	Snake *getSnake();
	~MedusaQueen();
};


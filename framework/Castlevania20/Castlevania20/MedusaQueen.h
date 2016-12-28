#pragma once
#include "BaseObject.h"
#include "Snake.h"

#define MEDUSA_SPRITE		L"resource\\sprite\\boss\\1.png"
#define MEDUSA_WIDTH			65
#define MEDUSA_HEIGHT			64
#define MEDUSA_SPEED			0.1f

#define TYPE 0

#define DIE_SPRITE L"resource\\sprite\\boss\\die.bmp"

enum MEDUSA_ACCTION {
	M_ATTACK, M_REST
};

class MedusaQueen :
	public BaseObject
{
private:
	int timedie = 0;
	int tick;
	ENEMY_STAGE state;
	Snake *snake;
	MEDUSA_ACCTION action;
public:
	MedusaQueen();
	MedusaQueen(int id, int x, int y);
	void MoveUpdate(int simon_x, int simon_y, float deltatime);
	void Draw();
	void Die();
	Box getBox();
	Snake *getSnake();
	~MedusaQueen();
};


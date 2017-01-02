#pragma once
#include "Bandage.h"
#define MUMMYMAN_SPRITE		L"resource\\sprite\\boss\\MummyMan.png"
#define MUMMYMAN_WIDTH			32
#define MUMMYMAN_HEIGHT			80
#define MUMMYMAN_SPEED			0.1f

#define TYPE 1

#define DIE_SPRITE L"resource\\sprite\\boss\\die.bmp"
class MummyMan : public BaseObject
{
private:
	Bandage * band;
	int timedie = 0;
	int tick;
	ENEMY_STAGE state;
	//Snake *snake;
	int number;

public:
	MummyMan();
	MummyMan(int id, int x, int y,int var1);
	void MoveUpdate(int simon_x, int simon_y, float deltatime);
	void Draw();
	void Die();
	Box getBox();
	Bandage *getBandage();
	~MummyMan();
};


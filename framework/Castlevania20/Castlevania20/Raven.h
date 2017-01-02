#pragma once
#include "BaseObject.h"

#define RAVEN_SPRITE		L"resource\\sprite\\enemy\\raven.png"
#define RAVEN_WIDTH			32
#define RAVEN_HEIGHT		32
#define RAVEN_SPEED			0.2f

#define TYPE 7
class Raven :
	public BaseObject
{
private:
	ENEMY_STAGE state;
	bool is_left;
	bool attack;
public:
	Raven();
	Raven(int id, int x, int y);
	void MoveUpdate(int simon_x, int simon_y, float deltatime);
	void Draw();
	~Raven();
};


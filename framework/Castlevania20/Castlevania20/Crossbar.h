#pragma once
#include "BaseObject.h"

#define BAR_SPRITE			L"resource\\sprite\\ground\\9.png"
#define BAR_WIDTH			64
#define BAR_HEIGHT			16
#define BAR_SPEED			0.12f

#define TYPE 17

class Crossbar :
	public BaseObject
{
private:
	bool is_direction_right;
public:
	Crossbar();
	Crossbar(int id, int x, int y, RECT bound);
	void MoveUpdate(float deltatime);
	void Draw();
	~Crossbar();
};


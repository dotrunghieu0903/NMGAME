#pragma once
#include "BaseObject.h"


#define KNIGHT_SPRITE			L"resource\\sprite\\enemy\\5.png"
#define KNIGHT_WIDTH			32
#define KNIGHT_HEIGHT			64
#define KNIGHT_SPEED			0.14f

#define TYPE 9

class BlackKnight :
	public BaseObject
{
private:
	ENEMY_STAGE stage;
public:
	BlackKnight(int id, int x, int y, RECT rect);
	void MoveUpdate(float deltatime);
	void UpdateEvent(float deltatime);
	void Draw();
	BlackKnight();
	~BlackKnight();
};


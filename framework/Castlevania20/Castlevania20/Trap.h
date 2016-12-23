#pragma once
#include "BaseObject.h"

#define TRAP1 1
#define TRAP2 2
#define TRAP3 3
#define TYPE 22
#define TRAP_SPRITE L"resource\\sprite\\ground\\7.png"
#define PILLAR_SPRITE L"resource\\sprite\\ground\\7_3.png"



enum TRAP_STAGE {
	UP,DOWN,DELAY
};

class Trap :
	public BaseObject
{
private:
	TRAP_STAGE stage = DOWN;
	int order;
	int number = 0;
	Sprite *pillar;
public:
	Trap();
	Trap(int id, int x, int y, int number);
	void MoveUpdate(float deltatime);
	void Draw();
	~Trap();
};


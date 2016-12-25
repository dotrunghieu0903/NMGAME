#pragma once
#include "BaseObject.h"

#define SNAKE_SPRITE L"resource\\sprite\\boss\\snake.png"
#define SNAKE_WIDTH 32
#define SNAKE_HEIGHT 20
#define SNAKE_SPEED 0.35f
#define TYPE 39

class Snake :
	public BaseObject
{
private:
	bool is_left;
public:
	Snake();
	Snake(int x,int y, bool is_left);
	void MoveUpdate(float deltatime);
	void Draw();
	~Snake();
};


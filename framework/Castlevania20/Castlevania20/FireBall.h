#ifndef __FireBall_H__
#define __FireBall_H__
#include "BaseObject.h"
#define FIREBALL_SPRITE L"resource\\sprite\\fireball.png"
#define FIREBALL_WIDTH 14
#define FIREBALL_HEIGHT 12
#define FIREBALL_SPEED 0.35f


#pragma once
class FireBall : 
	public BaseObject
	
{

public:
	FireBall();
	FireBall(int x, int y, bool is_left);
	void MoveUpdate(float deltatime);
	void Draw();
	~FireBall();
};

#endif

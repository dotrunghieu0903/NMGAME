#pragma once
#include "BaseObject.h"

#define BAND_SPRITE L"resource\\sprite\\boss\\MummyManBandage.png"
#define BAND_WIDTH 32
#define BAND_HEIGHT 20
#define BAND_SPEED 0.35f
#define TYPE 39

class Bandage :
	public BaseObject
{
public:
	int timedie = 0;
	bool is_left;
	Bandage(int x,int y, bool is_left);
	void MoveUpdate(float deltatime);
	void Draw();
	~Bandage();
};


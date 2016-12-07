#pragma once
#include "BaseObject.h"

#define TYPE 11 //ground brick
#define GROUND_SPRITE L"resource\\sprite\\ground\\ground.png"
class Ground : public BaseObject {

public:
	Ground();
	Ground(int x, int y, int width, int height);
	void Draw();
	~Ground();
};


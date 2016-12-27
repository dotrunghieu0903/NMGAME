#pragma once
#include "BaseObject.h"

#define TYPE 11 //ground brick
#define GROUND_SPRITE L"resource\\sprite\\ground\\ground.png"
class Ground : public BaseObject {

public:
	Ground();
	Ground(int id, int x, int y, int width, int height);
	void UpdateEvent(float deltetime);
	bool collission_bot = false;
	~Ground();
};


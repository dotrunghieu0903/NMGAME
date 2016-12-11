#pragma once
#include "Sprite.h"
#include "Simon.h"

#define INTRO_SPRITE L"resource\\sprite\\intro.png"
#define HELICOPTER L"resource\\sprite\\helicopter.png"
class Intro
{
	Sprite *background;
	Sprite *helicopter;
	Simon *simonTemp;
	float heli_x;
	float heli_y;
	bool  end;
	float timeTemp = 0;
public:
	Intro();
	void Update(float deltatime);
	void Draw();
	bool isFinish();
	~Intro();
};


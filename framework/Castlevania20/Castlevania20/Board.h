#pragma once
#include "Sprite.h"
class Board
{
	Sprite *_sprite;
public:
	Board();
	void Draw(int x,int y);
	~Board();
};


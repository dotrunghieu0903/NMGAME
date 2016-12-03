#pragma once
#include "Rectangle.h"
class Tile
{
private:
	int _id;
	CRectangle* _srcRect;
public:
	Tile();
	Tile(int id, CRectangle* srcRect);
	Tile(int id, float x, float y, float width, float height);
	~Tile();
};
#ifndef _TILE_H
#define _TILE_H

#pragma once
#include "CRectangle.h"
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
#endif
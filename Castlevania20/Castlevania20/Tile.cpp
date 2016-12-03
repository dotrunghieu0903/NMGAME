#include "Tile.h"



Tile::Tile()
{
	_id = -1;
	_srcRect = new CRectangle();
}


Tile::~Tile()
{
}


Tile::Tile(int id, CRectangle* srcRect)
{
	_id = id;
	_srcRect = srcRect;
}

Tile::Tile(int id, float x, float y, float width, float height)
{
	_id = id;
	_srcRect = new CRectangle(x, y, width, height);
}
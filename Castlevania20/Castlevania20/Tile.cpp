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

Tile::Tile(int id, int x, int y, int width, int height)
{
	_id = id;
	_srcRect = new CRectangle(x, y, width, height);
}
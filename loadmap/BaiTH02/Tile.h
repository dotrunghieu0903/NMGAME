#define _CRT_SECURE_NO_DEPRECATE
#include <d3dx9.h>
#include "Rectangle.h"
class Tile
{
private:
	int _id;
	CRectangle* _srcRect;
public:
	Tile();
	Tile(int id, CRectangle* srcRect);
	Tile(int id, int x, int y, int width, int height);
	~Tile();
};
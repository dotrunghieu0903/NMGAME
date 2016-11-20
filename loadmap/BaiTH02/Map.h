#pragma once
#include "Tile.h"
#include "sprite.h"
class Map
{
private:
	int N;  //so luong tile
	int _w; //chieu rong tile
	int _h; //chieu cao tile
	int _rows; 
	int _cols;
	int** maxtrix;
	Tile *_listTiles; 
	CSprite * image;

	char* _txtPath;
	char* _imagePath;

	LPD3DXSPRITE _SpriteHandler; //bien tam
public:
	Map();
	Map(char* txtPath, char* imagePath);
	bool loadMap(LPD3DXSPRITE _SpriteHandler); // -> loadMap()
	void render (int x, int y, int vpx, int vpy);
	~Map();
};


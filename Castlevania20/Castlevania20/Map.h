#pragma once
#include "Tile.h"
#include <iostream>
#include <stdio.h>
#include "Sprite.h"
#include "Globals.h"

class Map
{
private:
	int N;  //so luong tile
	float _w; //chieu rong tile
	float _h; //chieu cao tile
	int _rows;
	int _cols;
	int** maxtrix;
	Tile *_listTiles;
	CSprite* image;

	char* _txtPath;
	char* _imagePath;

public:
	Map();
	Map(char* txtPath, char* imagePath);
	bool loadMap();
	void render(int x, int y);
	~Map();
};


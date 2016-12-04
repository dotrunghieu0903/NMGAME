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
	Sprite* image;

	char* _txtPath;
	char* _imagePath;

public:
	Map();
	Map(char* txtPath, char* imagePath);
	bool loadMap(int count);
	void render(int x, int y);
	~Map();
};


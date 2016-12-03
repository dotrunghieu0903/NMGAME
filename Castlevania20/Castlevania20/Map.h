#pragma once
#include "Tile.h"
#include <iostream>
#include <stdio.h>
#include "Sprite.h"
#include "Globals.h"

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

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
	Sprite* image;

	char* _txtPath;
	char* _imagePath;

public:
	Map();
	Map(char* txtPath, char* imagePath);
	bool loadMap(); // -> loadMap()
	void render(int x, int y, int vpx, int vpy);
	~Map();
};


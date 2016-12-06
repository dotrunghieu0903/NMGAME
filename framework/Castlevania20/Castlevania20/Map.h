#pragma once
#include <iostream>
#include <stdio.h>
#include "Sprite.h"
#include "Tile.h"

#define LEVEL1_PNG L"resource\\map\\stage1.png"
#define LEVEL1_TXT "resource\\map\\stage1.txt"
#define LEVEL2_PNG L"resource\\map\\stage2.png"
#define LEVEL2_TXT "resource\\map\\stage2.txt"

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
	LPCWSTR _imagePath;

public:
	Map();
	Map(char* txtPath, LPCWSTR imagePath);
	bool loadMap(int count);
	void render(int x, int y);
	~Map();
};


#ifndef _MAP_H
#define _MAP_H

#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Sprite.h"
#include "Tile.h"

#define LEVEL2_PNG L"resource\\map\\level2.png"
#define LEVEL2_TXT "resource\\map\\level2.txt"
#define LEVEL2_OBEJCT "resource\\map\\level2_object.txt"
#define LEVEL2_QUADTREE "resource\\map\\level2_object_Quad.txt"
#define LEVEL2_COUNT 171

#define LEVEL3_PNG L"resource\\map\\level3.png"
#define LEVEL3_TXT "resource\\map\\level3.txt"
#define LEVEL3_OBEJCT "resource\\map\\level3_object.txt"
#define LEVEL3_QUADTREE "resource\\map\\level3_object_Quad.txt"
#define LEVEL3_COUNT 83


using namespace std;

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
	int getHeight();
	~Map();
};


#endif
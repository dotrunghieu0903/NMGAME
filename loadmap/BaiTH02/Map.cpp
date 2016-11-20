#include "Map.h"
#include <iostream>
#include <stdio.h>

Map::Map()
{
}

Map::Map(char* txtPath, char* imagePath)
{
	N = 0;
	_txtPath = txtPath;
	_imagePath = imagePath;
}

bool Map::loadMap(LPD3DXSPRITE _SpriteHandler) { // -> loadMap()
	//doc file txt
	FILE *fp;
	try
	{
		fp = fopen(_txtPath, "r");
		fscanf(fp, "%d", &N);
		fscanf(fp, "%d", &_cols);
		fscanf(fp, "%d", &_rows);
		fscanf(fp, "%d", &_w);
		fscanf(fp, "%d", &_h);

		_listTiles = new Tile[N]();
		for (int i = 0; i < N; i++) {
			_listTiles = new Tile(i, i * _w, 0, _w, _h);
		}

		maxtrix = new int*[_rows];
		for (int i = 0; i < _rows; i++) {
			maxtrix[i] = new int[_cols];
		}
		for (int r = 0; r < _rows; r++) {
			for (int c = 0; c < _cols; c++) {
				fscanf(fp, "%d", &maxtrix[r][c]);
			}
		}
		fclose(fp);

		//doc file png
		//doc fie info truoc
		image = new CSprite(_SpriteHandler, L"stage1.png", 16, 16, 1, N);
	
	}
	catch (const std::exception&)
	{
		return false;
	}

	
	
	return true;
}

void Map::render(int x,int y, int vpx, int vpy) {
		for (int c = 0; c < _cols; c++) {
	for (int r = 0; r < _rows; r++) {
			image->Render(y + c * _h, x - r * _w, vpx, vpy, maxtrix[r][c]);
		}
	}
	/*image->Render(0, 0, vpx, vpy,1);
	image->Render(16, 0, vpx, vpy,2);
	image->Render(16, 0, vpx, vpy, 2);*/
}


Map::~Map()
{
	_listTiles ->~Tile();
}

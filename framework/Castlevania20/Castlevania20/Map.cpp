#include "Map.h"

Map::Map()
{
}

Map::Map(char* txtPath, LPCWSTR imagePath)
{
	N = 0;
	_txtPath = txtPath;
	_imagePath = imagePath;
}

bool Map::loadMap(int count) { // -> loadMap()
							   //doc file txt
	FILE *fp;
	try
	{
		fp = fopen(_txtPath, "r");
		fscanf(fp, "%d", &N);
		fscanf(fp, "%d", &_cols);
		fscanf(fp, "%d", &_rows);
		fscanf(fp, "%f", &_w);
		fscanf(fp, "%f", &_h);

		_listTiles = new Tile[N]();
		for (int i = 0; i < N; i++) {
			_listTiles = new Tile(i, (float)i * _w, 0, _w, _h);
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
		image = new Sprite(new Texture(_imagePath, count, 1, count), 0);


	}
	catch (const std::exception&)
	{
		return false;
	}



	return true;
}

void Map::render(int x, int y) {
	for (int r = 0; r < _rows; r++) {
		for (int c = 0; c < _cols; c++) {
	
			image->DrawIndex(x + (float)c * _h, (float)(y + r * _w), maxtrix[r][c]);
	
		}
	}
		/*image->DrawIndex(0,0,0);
		image->DrawIndex(32, 32, 2);
		image->DrawIndex(64, 64, 3);*/
}


Map::~Map()
{
	_listTiles ->~Tile();
}


int Map::getHeight() {
	return _rows*_h;
}
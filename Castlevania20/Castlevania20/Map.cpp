#include "Map.h"

Map::Map()
{
}

Map::Map(char* txtPath, char* imagePath)
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

		//doc file png
		//doc fie info truoc
//		Texture* text = new Texture();
		//text->LoadTextureFromFile(GL_graphic->GetDevice() , _imagePath, D3DCOLOR_ARGB(100, 255, 255, 255));
		image = new Sprite(_imagePath, TILE_WITHD, TILE_WITHD, count, count);

		
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
			image->Render(x + (float) c * _h, (float)(y - r * _w), maxtrix[r][c]);
		}
	}
	//image->Render(100, 100, 1);
	//image->Render(132, 100, 2);
	//image->Render(164, 100, 3);
	//image->Render(122, 122, 3);
	//image->Render(133, 133, 4);
}


Map::~Map()
{
	_listTiles ->~Tile();
}

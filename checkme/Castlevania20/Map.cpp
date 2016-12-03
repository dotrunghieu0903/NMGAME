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

bool Map::loadMap() { // -> loadMap()
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
		image = new CSprite(STAGE1_PNG, 16, 16, 126, 126);

		
	}
	catch (const std::exception&)
	{
		return false;
	}



	return true;
}

void Map::render(int x, int y) {
	for (int c = 0; c < _cols; c++) {
		for (int r = 0; r < _rows; r++) {
			image->Render(y + (float) c * _h, (float)(x - r * _w), maxtrix[r][c]);
			//image->Render(y + c * _h, x - r * _w, vpx, vpy, maxtrix[r][c]);
		}
	}
	image->Render(200, -100,0);
	//image->Render(16, 16, 1);

}


Map::~Map()
{
	_listTiles ->~Tile();
}

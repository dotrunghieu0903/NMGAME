#ifndef _BOARD_H_
#define _BOARD_H_

#include "Sprite.h"
#include "Camera.h"
#define BOARD_PATH L"resource\\images\\board.bmp"
class Board
{
protected:
	int _time;
	int _state;
	int _heart;
	int _life;
	int _simonHP;
	int _itemHP;

	Sprite *_sprite;
	RECT _temp;
	RECT _rect1;
	RECT _rect2;
	RECT _rect3;
	RECT _rect4;
	RECT _rect5;
	RECT _rect6;
	RECT _rect7;
	RECT _rect8;
	RECT _rect9;
	RECT _rect10;

public:
	int _score;
	Board();
	void Draw(int x, int y);
	void Update(int deltaTime);
	void DrawPoint(D3DXVECTOR3 point, int num);
	~Board();
};

#endif // !_BOARD_H_
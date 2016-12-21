#ifndef _BOARD_H_
#define _BOARD_H_

#include "Sprite.h"
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
public:
	int _score;
	Board();
	void Draw(int x, int y);
	void Update(int deltaTime);
	~Board();
};

#endif // !_BOARD_H_
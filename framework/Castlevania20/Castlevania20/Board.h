#ifndef __BOARD_H__
#define __BOARD_H__

#include "SubWeapon.h"
#include "Simon.h"

#define BOARD_IMAGE_PATH L"resource\\sprite\\board.png"
#define MISC_IMAGE_PATH L"resource\\sprite\\item\\misc.png"

class Board {
protected:
	int _State;
	int _Simon_HP;
	int _Enemy_HP;
	int _Heart;
	int _Life;
	int _Sub;
	int _Sub_Shot;
	Sprite* _spriteBoard;
	Sprite* _spriteMisc;
public:
	int _Time;
	int _Score;
	Board::Board();

	void LoadResource();
	void Update(Simon *simon, int deltatime);
	void Draw();
	void setTime();
	~Board();

	RECT rectByNum(int i)
	{
		RECT r = { 242, 376, 256, 390 };
		switch (i)
		{
		case 1:
			r = { 242, 396, 256, 410 };
			break;
		case 2:
			r = { 258, 376, 272, 390 };
			break;
		case 3:
			r = { 258, 396, 272, 410 };
			break;
		case 4:
			r = { 274, 376, 288, 390 };
			break;
		case 5:
			r = { 274, 396, 288, 410 };
			break;
		case 6:
			r = { 290, 376, 304, 390 };
			break;
		case 7:
			r = { 290, 396, 304, 410 };
			break;
		case 8:
			r = { 306, 376, 320, 390 };
			break;
		case 9:
			r = { 306, 396, 320, 410 };
			break;

		default:
			break;
		}
		return r;
	}

	RECT rectSubWeapon(int i)
	{
		RECT r = { 0, 0, 0, 0 };
		switch (i)
		{
		case SUBWEAPON_KNIFE:
			r = { 289, 4, 321, 25 };
			break;
		case SUBWEAPON_AXE:
			r = { 179, 0, 209, 30 };
			break;
		case SUBWEAPON_HOLY_WATER:
			r = { 70, 80, 102, 112 };
			break;
		case SUBWEAPON_STOP_WATCH:
			r = { 114, 82, 144, 112 };
			break;
		case SUBWEAPON_CROSS:
			r = { 105, 0, 135, 30 };
			break;
		default:
			break;
		}
		return r;
	}

	RECT rectSubWeaponNum(int i)
	{
		RECT r = { 0, 0, 0, 0 };
		switch (i)
		{
		case 2:
			r = { 152, 84, 180, 112 };
			break;
		case 3:
			r = { 184, 84, 212, 112 };
			break;
		default:
			break;
		}
		return r;
	}
};

#endif
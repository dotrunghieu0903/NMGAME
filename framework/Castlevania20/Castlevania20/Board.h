#ifndef _BOARD_H_
#define _BOARD_H_

#include "Sprite.h"
#include "Camera.h"
#include "Font.h"
#include "Simon.h"
#include "BaseObject.h"

#define SIMON_HP L"resource\\images\\heathplayer.png"
#define ENEMY_HP L"resource\\images\\heathenemy.png"
#define BOARD_PATH L"resource\\images\\board.bmp"
#define AXE_BANNER L"resource\sprite\item\\7.png"
#define BOOMERANG_BANNER L"resource\sprite\item\\8.png"
#define FIRE_BOMB_BANNER L"resource\sprite\item\\9.png"
#define CROSS_BANNER L"resource\sprite\item\\6.png"
#define WEAPON_DAGGER L"resource\sprite\weapon\\1.png"

class Board: public BaseObject
{
protected:
	int _state;
	int _simonHP;
	int _itemHP;
	int _point;
	int _countTime = 300;
	float _deepTime = 0;
	Sprite *_sprite1;
	Sprite *_sprite2;
	Sprite *_sprite3;
	D3DXVECTOR3 _heartPos;//HP Simon
	D3DXVECTOR3 _weaponPos;// vu khi
	D3DXVECTOR3 _pointPos;//diem
public:
	WEAPONNAME _typeWeapon;
	RECT* _rectPoint;
	RECT* _rectTime;
	RECT* _rectState;
	RECT getRECT();
	Font* _font;
	Board();
	void DrawBG();
	void DrawProperty();
	void Update(int deltaTime);
	~Board();
};

#endif // !_BOARD_H_
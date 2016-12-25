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
#define AXE_BANNER L"resource\\sprite\\item\\7.png"
#define BOOMERANG_BANNER L"resource\\sprite\\item\\8.png"
#define FIRE_BOMB_BANNER L"resource\\sprite\\item\\9.png"
#define CROSS_BANNER L"resource\\sprite\\item\\6.png"
#define WEAPON_DAGGER L"resource\\sprite\\weapon\\1.png"

class Board: public BaseObject
{
protected:
	int _state;
	int _simonHP;
	int _enemyHP;
	int _point;
	int _countTime = 300;
	float _deepTime = 0;
	int _countHeart;
	int _countLife;
	Sprite *_sprite1;
	Sprite *_sprite2;
	Sprite *_sprite3;
	Sprite *_sprite4;
	D3DXVECTOR3 _heartPos;//HP Simon
	D3DXVECTOR3 _weaponPos;// vu khi
	D3DXVECTOR3 _pointPos;//diem
	D3DXVECTOR3 _posHpEnemy;

public:
	WEAPONNAME _typeWeapon;
	RECT* _rectPoint;
	RECT* _rectTime;
	RECT* _rectState;
	RECT* _rectEnemyHP;
	RECT* _rectHeart;
	RECT* _rectLife;

	RECT getRECT();
	Font* _font;
	Board();
	/*void Draw(int x,int y);*/
	void DrawBG();
	void DrawProperty();
	void Update(int deltaTime);
	~Board();
};

#endif // !_BOARD_H_
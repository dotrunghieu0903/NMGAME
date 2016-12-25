#include "Board.h"

Board::Board()
{
	_sprite1 = new Sprite(new Texture(BOARD_PATH), 10);
	_sprite2 = new Sprite(new Texture(SIMON_HP),50);
	_sprite4 = new Sprite(new Texture(ENEMY_HP), 50);
	
	_simonHP=Simon::getCurrentSimon()->_hpSimon;
	_font = new Font();

	_point = 0;
	_state = 1;
	_countHeart = 5;
	_countLife = 2;
	_simonHP = 16;
	_enemyHP = 16;

	this->_heartPos = D3DXVECTOR3(122, 35, 0);
	this->_posHpEnemy = D3DXVECTOR3(122, 50, 0);
	this->_pointPos = D3DXVECTOR3(122, 30, 0);;
	this->_weaponPos = D3DXVECTOR3(288, 38, 0);

	//rect point
	_rectPoint = new RECT();
	_rectPoint->left = 122;
	_rectPoint->right = 192;
	_rectPoint->top = 5;
	_rectPoint->bottom = 60;

	//rect time
	_rectTime = new RECT();
	_rectTime->left = 300;
	_rectTime->right = 340;
	_rectTime->top = 5;
	_rectTime->bottom = 60;

	//rect state
	_rectState = new RECT();
	_rectState->left = 500;
	_rectState->right = 530;
	_rectState->top = 5;
	_rectState->bottom = 60;

	//rect enemy hp
	_rectEnemyHP = new RECT();
	_rectEnemyHP->left = 122;
	_rectEnemyHP->right = 192;
	_rectEnemyHP->top = 70;
	_rectEnemyHP->bottom = 100;

	//rect heart
	_rectHeart = new RECT();
	_rectHeart->left = 400;
	_rectHeart->right = 510;
	_rectHeart->top = 25;
	_rectHeart->bottom = 60;

	//rect life
	_rectLife = new RECT();
	_rectLife->left = 400;
	_rectLife->right = 510;
	_rectLife->top = 45;
	_rectLife->bottom = 90;
}

RECT Board::getRECT() {
	RECT  rec;
	rec.left = 0;
	rec.right = rec.left + _width;
	rec.top = 0;
	rec.bottom = rec.top + _height;
	return rec;
}

//void Board::Draw(int x,int y) {
//	_sprite1->Draw(x,y);
//}

void Board::DrawBG() {
	D3DXVECTOR3 pos = D3DXVECTOR3();
	RECT* rec = new RECT();
	rec->left = 0;
	rec->right = rec->left + _width;
	rec->top = 0;
	rec->bottom = rec->top + _height;
	pos.x = Camera::getCurrentCamera()->getViewPortX();
	pos.y = Camera::getCurrentCamera()->getViewPortY();
	//_sprite1->DrawRect(pos.x, pos.y, getRECT());
	_sprite1->Draw(pos.x, pos.y);
}

void Board::DrawProperty() {
	
	D3DXVECTOR3 posHpSimon = this->_heartPos;
	D3DXVECTOR3 posEnemyHp = this->_posHpEnemy;
	for (int i = 0; i < this->_simonHP; i++)
	{
		_sprite2->Draw(posHpSimon.x,posHpSimon.y);
		posHpSimon.x += 8;
	}

	for (int i = 0; i < this->_enemyHP; i++)
	{
		_sprite4->Draw(posEnemyHp.x, posEnemyHp.y);
			posEnemyHp.x += 8;
	}

	_sprite3->Draw(_weaponPos.x, _weaponPos.y);
	//score
	_font->DrawNumber(0, _rectPoint);
	//time
	_font->DrawNumber(_countTime, _rectTime);
	//state
	_font->DrawNumber(1, _rectState);
	//heart
	_font->DrawNumber(_countHeart, _rectHeart);
	//life
	_font->DrawNumber(_countLife,_rectLife);
}

void Board::Update(int deltaTime) {
	this->_deepTime -= deltaTime;
	this->_countTime = (int)_deepTime;
	this->_x = Camera::getCurrentCamera()->getViewPortX() + 240;
	//cap nhat mau cua simon
	this->_simonHP = Simon::getCurrentSimon()->_hpSimon;
	this->_typeWeapon = Simon::getCurrentSimon()->_currentWeapon;
	
	switch (this->_typeWeapon)
	{
	case WEAPONNAME::Axe:
		_sprite3 = new Sprite(new Texture(AXE_BANNER), 10);
		break;
	case WEAPONNAME::Boomerang:
		_sprite3 = new Sprite(new Texture(BOOMERANG_BANNER), 10);
		break;
	case WEAPONNAME::Dagger:
		_sprite3 = new Sprite(new Texture(WEAPON_DAGGER), 10);
		break;
	case WEAPONNAME::FireBomb:
		_sprite3 = new Sprite(new Texture(FIRE_BOMB_BANNER), 10);
		break;
	case WEAPONNAME::Watch:
		_sprite3 = new Sprite(new Texture(FIRE_BOMB_BANNER), 10);
		break;
	case WEAPONNAME::None:
		this->_sprite3 = NULL;
		break;
	}
}

Board::~Board()
{
}

#include "Board.h"

Board::Board()
{
	_sprite1 = new Sprite(new Texture(BOARD_PATH), 10);
	_sprite2 = new Sprite(new Texture(SIMON_HP),10);
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

	this->_heartPos = D3DXVECTOR3(122, 48, 0);
	this->_pointPos= D3DXVECTOR3(122, 30, 0);;
	this->_weaponPos = D3DXVECTOR3(300, 55, 0);
	_simonHP=Simon::getCurrentSimon()->_hpSimon;
	_font = new Font();

	_point = 0;
	_state = 1;
	_state = 1;
	_simonHP = 16;
	_itemHP = 16;

	//rect point
	_rectPoint = new RECT();
	_rectPoint->left = 122;
	_rectPoint->right = 192;
	_rectPoint->top = 14;
	_rectPoint->bottom = 60;

	//rect time
	_rectTime = new RECT();
	_rectTime->left = 300;
	_rectTime->right = 340;
	_rectTime->top = 14;
	_rectTime->bottom = 60;

	//rect state
	_rectState = new RECT();
	_rectState->left = 500;
	_rectState->right = 530;
	_rectState->top = 14;
	_rectState->bottom = 60;
}

RECT Board::getRECT() {
	RECT  rec;
	rec.left = 0;
	rec.right = rec.left + _width;
	rec.top = 0;
	rec.bottom = rec.top + _height;
	return rec;
}

void Board::DrawBG() {
	D3DXVECTOR3 pos = D3DXVECTOR3();
	RECT* rec = new RECT();
	rec->left = 0;
	rec->right = rec->left + _width;
	rec->top = 0;
	rec->bottom = rec->top + _height;
	pos.x = Camera::getCurrentCamera()->getViewPortX();
	pos.y = Camera::getCurrentCamera()->getViewPortY();
	_sprite1->DrawRect(pos.x, pos.y, getRECT());
}

void Board::DrawProperty() {
	D3DXVECTOR3 posHpSimon = this->_heartPos;
	for (int i = 0; i < this->_simonHP; i++)
	{
		_sprite2->Draw(posHpSimon.x,posHpSimon.y);
		posHpSimon.x += 8;
	}

	_sprite3->Draw(_weaponPos.x, _weaponPos.y);
	//score
	_font->DrawNumber(1000, _rectPoint);
	//time
	_font->DrawNumber(_countTime, _rectTime);
	//state
	_font->DrawNumber(1, _rectState);
}

void Board::Update(int deltaTime) {
	this->_deepTime += deltaTime;
	this->_countTime = (int)_deepTime;
	this->_x = Camera::getCurrentCamera()->getViewPortX() + 265;
	//cap nhat mau cua simon
	this->_simonHP = Simon::getCurrentSimon()->_hpSimon;
	this->_typeWeapon = Simon::getCurrentSimon()->_currentWeapon;
	
}

Board::~Board()
{
}

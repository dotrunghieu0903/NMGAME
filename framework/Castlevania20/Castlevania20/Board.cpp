#include "Board.h"

Board::Board()
{
	_sprite = new Sprite(new Texture(BOARD_PATH), 10);
	_score = 0;
	_time = 300;
	_state = 1;
	_life = 3;
	_heart = 5;
	_state = 1;
	_simonHP = 16;
	_itemHP = 16;

	_rect1.left = 2;
	_rect1.top = 4;
	_rect1.right = 18;
	_rect1.bottom = 20;
}

void Board::DrawPoint(D3DXVECTOR3 point, int num){
	float _cameraX = Camera::getCurrentCamera()->getViewPortX();
	float _cameraY = Camera::getCurrentCamera()->getViewPortY();
	point.x = _cameraX;
	point.y = _cameraY;
	switch (num)
	{
	case 1: 
		_temp = _rect1;
		break;
	case 2:
		_temp = _rect2;
		break;
	case 3:
		_temp = _rect3;
		break;
	case 4:
		_temp = _rect4;
		break;
	case 5:
		_temp = _rect5;
		break;
	case 6:
		_temp = _rect6;
		break;
	case 7:
		_temp = _rect7;
		break;
	case 8:
		_temp = _rect8;
		break;
	case 9:
		_temp = _rect9;
		break;
	case 10:
		_temp = _rect10;
		break;
	default:
		break;
	}
}

void Board::Draw(int x, int y) {
	_sprite->Draw(x,y);//render borad
	//render score
	_sprite->DrawRect(x,y,_temp);
}

void Board::DrawHeart() {

}

void Board::DrawLife() {

}

void Board::Update(int deltaT) {
	//Update score
	int c = _score;
	for (int i = 6; i > 0; i--) {
		int k = c % 10;

	}
}

Board::~Board()
{
}

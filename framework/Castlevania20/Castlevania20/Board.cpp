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
}

void Board::Draw(int x, int y) {
	_sprite->Draw(x,y);//render borad
	//render score
		
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

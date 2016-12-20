#include "Board.h"



Board::Board()
{
	_sprite = new Sprite(new Texture(L"resource\\images\\board.bmp"), 10);
}

void Board::Draw(int x, int y) {
	_sprite->Draw(x,y);
}

Board::~Board()
{
}

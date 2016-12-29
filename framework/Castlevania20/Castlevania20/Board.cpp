#include "Board.h"

Board::Board()
{
	_spriteBoard = new Sprite(new Texture(BOARD_IMAGE_PATH, 1, 1, 1), 200); 
	_spriteMisc = new Sprite(new Texture(MISC_IMAGE_PATH, 1, 1, 1), 10);
	_Score = 0;
	_Time = 400;
	_State = 1;
	_Simon_HP = 12;
	_Enemy_HP = 16;
	_Heart = 5;
	_Life = 3;
	_Sub = WEAPONNAME::None;
	_Sub_Shot = WEAPON::WEAPON1;

	LoadResource();
}

void Board::LoadResource()
{
	
}

void Board::setTime()
{
	if (_Time > 0)
	{
		_Time--;
	}
}

void Board::Update(Simon *simon, int deltatime)
{
	_Score = simon->_score;
	_State = simon->_currentStage;
	_Simon_HP = simon->heath;
	_Enemy_HP = simon->_enemyHP;
	_Heart = simon->_heartNum;
	_Life = simon->_life;
	_Sub = simon->_currentWeapon;
	_Sub_Shot = simon->_index_weapon;
}

void Board::Draw()
{
	int boardPosX = Camera::getCurrentCamera()->getViewPortX();
	int boardPosY = Camera::getCurrentCamera()->getViewPortY();

	// DRAW Board
	_spriteBoard->Draw(boardPosX, boardPosY);

	#pragma region DRAW SCORE
	int s = _Score;

	for (int i = 6; i > 0; i--)
	{
		int k = s % 10;
		s = s / 10;

		RECT rec = rectByNum(k);
		_spriteMisc->DrawRect(float(boardPosX + 90 + i * 16), float(boardPosY + 12), rec);
	}
	#pragma endregion

	#pragma region DRAW TIME
	s = _Time;
	for (int i = 4; i > 0; i--)
	{
		int k = s % 10;
		s = s / 10;

		RECT rec = rectByNum(k);
		_spriteMisc->DrawRect(float(boardPosX + 280 + i * 16), float(boardPosY + 12), rec);
	}
	#pragma endregion

	#pragma region DRAW STATE
	s = _State;
	for (int i = 2; i > 0; i--)
	{
		int k = s % 10;
		s = s / 10;

		RECT rec = rectByNum(k);
		_spriteMisc->DrawRect(float(boardPosX + 450 + i * 16), float(boardPosY + 12), rec);
	}
	#pragma endregion

	#pragma region DRAW HEART
		s = _Heart;
		for (int i = 2; i > 0; i--)
		{
			int k = s % 10;
			s = s / 10;

			RECT rec = rectByNum(k);
			_spriteMisc->DrawRect(float(boardPosX + 350 + i * 16), float(boardPosY + 40), rec);
		}
	#pragma endregion

	#pragma region DRAW LIFE
		s = _Life;
		for (int i = 2; i > 0; i--)
		{
			int k = s % 10;
			s = s / 10;

			RECT rec = rectByNum(k);
			_spriteMisc->DrawRect(float(boardPosX + 350 + i * 16), float(boardPosY + 56), rec);
		}
	#pragma endregion

	#pragma region DRAW SIMON HEALTH BAR
		for (int i = 0; i < 16; i++)
		{
			RECT rec = { 324, 378, 330, 390 };
			if (i >= _Simon_HP)
				rec = { 324, 398, 330, 410 };

			_spriteMisc->DrawRect(float(boardPosX + 110 + i * 9), float(boardPosY + 40), rec);
		}
	#pragma endregion

	#pragma region DRAW ENEMY HEALTH BAR
		for (int i = 0; i < 16; i++)
		{
			RECT rec = { 360, 378, 366, 390 };
			if (i >= _Enemy_HP)
				rec = { 324, 398, 330, 410 };

			_spriteMisc->DrawRect(float(boardPosX + 110 + i * 9), float(boardPosY + 60), rec);
		}
	#pragma endregion

	#pragma region DRAW SUB WEAPON
		RECT rec = rectSubWeapon(_Sub);
		_spriteMisc->DrawRect(float(boardPosX + 275 ), float(boardPosY + 40), rec);
	#pragma endregion

	#pragma region DRAW SUB WEAPON NUM
		RECT rec2 = rectSubWeaponNum(_Sub_Shot);
		_spriteMisc->DrawRect(float(boardPosX + 420), float(boardPosY + 40), rec2);
	#pragma endregion

}

Board::~Board()
{
	delete _spriteBoard;
	delete _spriteMisc;
}
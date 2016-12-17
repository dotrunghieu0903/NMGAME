#pragma once
#include "Sprite.h"
#include "Input.h"
#define MENU_SPRITE L"resource\\sprite\\menu.png"
class Menu
{
protected:
	DWORD last_ani;
	bool start;
	bool finish; 
	int _index; // Thoi gian
	int _frame; // Frame current of bat

	Sprite *_sprite;
	Sprite *_animation;
public:
	// kiem tra khi nao menu ket thuc
	bool isStarted() { return finish; } 

	Menu();
	void Update(float deltatime);
	void Draw();
	~Menu();

	RECT GetRect(int index)
	{
		RECT srect;
		switch (index)
		{
		case 2:
			srect = { 591, 0, 757, 129 };
			break;
		case 3:
			srect = { 757, 0, 923, 129 };
			break;
		case 4:
			srect = { 923, 0, 1089, 129 };
			break;
		case 5:
			srect = { 1089, 0, 1255, 129 };
			break;
		case 6:
			srect = { 591, 129, 757, 258 };
			break;
		case 7:
			srect = { 757, 129, 923, 258 };
			break;
		case 8:
			srect = { 923, 129, 1089, 258 };
			break;
		case 9:
			srect = { 1089, 129, 1255, 258 };
			break;
		case 10:
			srect = { 591, 258, 757, 387 };
			break;
		case 11:
			srect = { 757, 258, 923, 387 };
			break;
		case 12:
			srect = { 923, 258, 1089, 387 };
			break;
		case 13:
			srect = { 1089, 258, 1255, 387 };
			break;
		case 14:
			srect = { 591, 387, 757, 516 };
			break;
		case 15:
			srect = { 757, 387, 923, 516 };
			break;
		case 0:
			srect = { 923, 387, 1089, 516 };
			break;
		case 1:
			srect = { 1089, 387, 1255, 516 };
			break;
		default:
			srect = { 923, 387, 1089, 516 };
			break;
		}
		return srect;
	}
};


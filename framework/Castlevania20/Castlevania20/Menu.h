#pragma once
#include "Sprite.h"
#include "Input.h"
#define MENU_SPRITE L"resource\\sprite\\menu.png"
class Menu
{
protected:
	float timeTemp;
	bool start;
	bool finish;

	int _index;

	Sprite *_sprite;
public:
	Menu();
	void Update(float deltatime);
	bool is_Start();
	void Start();
	void Draw();
	~Menu();
};


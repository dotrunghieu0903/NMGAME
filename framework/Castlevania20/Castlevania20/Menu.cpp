#include "Menu.h"



Menu::Menu()
{
	_sprite = new Sprite(new Texture(MENU_SPRITE, 2, 1, 2), 50);
	start = false;
	finish = false;
	timeTemp = 0.0f;
	_sprite->_start = 0; 
	_sprite->_end = 1;
}

void Menu::Update(float Delta)
{
	if (timeTemp >= 1000) {
		finish = true;
		return;
	}
	if (start) {
		timeTemp += Delta;
		_sprite->Update(Delta);
	}
	else {
		if (Input::getCurrentInput()->IsKeyDown(DIK_RETURN)) {
			start = true;
		}
	}
	
}

void Menu::Start() {
	if (!start)
	{
		//play music start game
		start = true;
	}
}

void Menu::Draw() {
	_sprite->Draw(0, 0);
}

bool Menu::is_Start() {
	return finish;
}

Menu::~Menu()
{
}

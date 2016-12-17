#include "Menu.h"



Menu::Menu()
{
	_sprite = new Sprite(new Texture(L"resource\\images\\menu-bg.png", 2, 1, 2), 50);
	_sprite->_start = 0;
	_sprite->_end = 1;
	_animation = new Sprite(new Texture(L"resource\\images\\menu.png", 4, 4, 16), 50);
	_animation->_start = 0;
	_animation->_end = 15;
	start = false;
	finish = false;
	_frame = 0;
	last_ani = GetTickCount();
}

void Menu::Update(float Delta)
{
	// time delay before play new game 
	if (_index >= 1000) {
		finish = true; 
		return;
	}

	// animation menu & time delay
	if (GetTickCount() - last_ani > 100)
	{
		_frame++;
		last_ani = GetTickCount();
		if (_frame > 15)
		{
			_frame = 13;
		}
	}
	if (start) {
		_index += Delta;
		_sprite->Update(Delta);
		_animation->Update(Delta);
	}
	else {
		if ( Input::getCurrentInput()->IsKeyDown(DIK_RETURN) ) {
			// MUSIC - play music intro game
			start = true;
		}
	}
	
}

void Menu::Draw() {
	_sprite->Draw(0, 0);
	RECT srect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	srect = GetRect(_frame);
	_animation->DrawRect(388.0f, 206.0f, srect);
}

Menu::~Menu()
{
	delete _sprite;
	delete _animation;
}

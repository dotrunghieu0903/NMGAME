#include "World.h"



World::World()
{
	background = new Sprite(new Texture(WORLD_SPRITE), 10);
	//boss = new Sprite(new Texture(HELICOPTER), 10);
	simonTemp = new Simon(0, 450-100);
	isStop = false;
	start = false;
	bg_x = 515;
}

void World::Update(float deltatime)
{
	if (_index > 10000) {
		isStop = true;
	}

	if (isStop == true) {
		return;
	}
	// delay background success
	if (bg_x == 0 )
	{
		start = true;
	}

	if ( start )
	{
		background->Update(deltatime);
		if (simonTemp->_x <= 515) {
			simonTemp->_sptrite->SetFrame(0, 3);
			simonTemp->_vx = 0.15f;
			simonTemp->MoveUpdate(deltatime);
		}
		else
		{
			simonTemp->_vx = 0.0f;
			isStop = true;
		}
	}
	if (bg_x > 0)
		bg_x -= deltatime;
	else
		bg_x = 0;
	_index += deltatime;
}

void World::Draw()
{
	RECT srect = { 0, 0, 640, 250 };
	background->DrawRect(bg_x , 100, srect);
	if ( start )
	{
		simonTemp->Draw();
	}
}


World::~World()
{
	delete background;
	delete boss;
	delete simonTemp;
	start = false;
	isStop = false;
	_index = 0;
}

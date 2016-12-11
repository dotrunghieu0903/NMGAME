#include "Intro.h"



Intro::Intro()
{
	background = new Sprite(new Texture(INTRO_SPRITE), 10);
	helicopter = new Sprite(new Texture(HELICOPTER), 10);
	simonTemp = new Simon(515-30, 334);
	heli_x = 515 - helicopter->_texture->FrameWidth;
	heli_y = 150;
	end = false;
	simonTemp->_vx = -0.07f;
	//simonTemp->setStage(2);
	timeTemp = 0.0f;
}

void Intro::Update(float deltatime) {
	if (timeTemp > 1000) {
		end = true;
	}
	if (end == true) {
		return;
	}
	heli_y -= 0.15f;
	heli_x -= 0.4f;
	
	if (simonTemp->_x >= 515/2-30) {
		simonTemp->SetFrame(deltatime);
		simonTemp->MoveUpdate(deltatime);
		simonTemp->_sptrite->Update(deltatime);
	}
	else
	{
		simonTemp->_vx = 0.0f;
		timeTemp += deltatime;
	}
}
void Intro::Draw() {
	background->Draw(0,0);
	helicopter->Draw(heli_x, heli_y);
	simonTemp->Draw();
}

bool Intro::isFinish() {
	return end;
}

Intro::~Intro()
{
	delete background;
	delete helicopter;
	delete simonTemp;
}
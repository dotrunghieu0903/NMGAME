#include "Intro.h"

Intro::Intro()
{
	background = new Sprite(new Texture(INTRO_SPRITE), 10);
	helicopter = new Sprite(new Texture(HELICOPTER), 10);
	simonTemp = new Simon(SCREEN_WIDTH -30, 337);
	heli_x = SCREEN_WIDTH - helicopter->_texture->FrameWidth;
	heli_y = 150;
	end = false;
	simonTemp->_vx = -0.07f;
	simonTemp->UpdateState(FACE_LEFT, MOVE);
	simonTemp->_sptrite->SetFrame(1, 3);
	timeTemp = 0.0f;
	PlaySound(sound_intro);
}

void Intro::Update(float deltatime) {
	if (timeTemp > 1100) {
		end = true;
	}
	if (end == true) {
		return;
	}
	heli_y -= 0.15f;
	heli_x -= 0.4f;

	if (simonTemp->_x >= SCREEN_WIDTH/2-30) {
		simonTemp->SetFacing(FACE_LEFT);
		simonTemp->_sptrite->SetFrame(0, 3);
		if (simonTemp->_x >= SCREEN_WIDTH/2 - 30 && simonTemp->_x <= SCREEN_WIDTH/2 - 25)
			simonTemp->_sptrite->SetFrame(9, 9);
		simonTemp->MoveUpdate(deltatime);
		simonTemp->_sptrite->Update(deltatime);
	}
	else
	{
		simonTemp->_sptrite->Update(deltatime);
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

#include "OptionScreen.h"

OptionScreen::OptionScreen() :IGameState()
{
	m_stateType = EScreenType::SETTING_SCREEN;
	backgroud = new Sprite(Texture::create("resource\\Image\\BackGround\\OptionBG.png"));
	music = new Sprite(Texture::create("resource\\Image\\Button\\OnOff.png"), 2, 1, 2, 0, 0);
	sound = new Sprite(Texture::create("resource\\Image\\Button\\OnOff.png"), 2, 1, 2, 0, 0);
	quit = new Sprite(Texture::create("resource\\Image\\Button\\quit.png"), 2, 1, 2, 1, 1);
	//if (SoundManager::isBGM_On == false)
	//	music->SetIndex(1);
	//if (SoundManager::isSoundEffect_On == false)
	//	sound->SetIndex(1);
	lstButton.push_back(music);
	lstButton.push_back(sound);
	lstButton.push_back(quit);

	currentChoise = 0;
}

OptionScreen::~OptionScreen()
{
	Release();
}

void OptionScreen::Create()
{

}

void OptionScreen::Release()
{
	//if(backgroud!=NULL)
	//delete backgroud;
	//backgroud = NULL;
}

void OptionScreen::HandleInput(Input* input, float dt)
{
	if (input->IsKeyPress(DIK_RETURN))
	{
		if (currentChoise == 0)
		{
			if (music->_Index == 0)
			{
				music->SetIndex(1);
				/*SoundManager::isBGM_On = false;
				SoundManager::GetInst()->StopAllBGSound();*/
			}
			else
			{
				music->SetIndex(0);
				/*SoundManager::isBGM_On = true;
				SoundManager::GetInst()->ResumeBGM();*/
			}
		}
		else if (currentChoise == 1)
		{
			if (sound->_Index == 0)
			{
				sound->SetIndex(1);
				//SoundManager::isSoundEffect_On = false;
			}
			else
			{
				sound->SetIndex(0);
				//SoundManager::isSoundEffect_On = true;
			}
		}
		else if (currentChoise == 2) {
			ExitSceen();
		}
	}

	if (input->IsKeyPress(DIK_LEFT))
	{
		currentChoise = (currentChoise == 0) ? 1 : 0;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}
	if (input->IsKeyPress(DIK_RIGHT))
	{
		currentChoise = (currentChoise == 1) ? 0 : 1;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}


	if (input->IsKeyPress(DIK_DOWN))
	{
		//if (currentChoise<lstButton.size() - 1)
		//	currentChoise++;
		//else
			currentChoise = 2;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}
	if (input->IsKeyPress(DIK_UP))
	{
		if (currentChoise > 0)
			currentChoise--;
		else
			currentChoise = lstButton.size() - 1;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}

	if (input->IsKeyPress(DIK_F))
	{
		if (GL_graphic->GetIsFullScreen() == false)
		{
			GL_graphic->ChangeViewMode(true);
			ResourceManager::GetIns()->Init();
			ExitSceen();
			StateManager::GetInstance()->ClearAllScreen();
			StateManager::GetInstance()->AddScreen(new MenuScreen());
		}
	}


	if (input->IsKeyPress(DIK_BACKSPACE))
	{
		ExitSceen();
	}
}

void OptionScreen::Update(float dt)
{
	for (int i = 0; i<lstButton.size(); i++)
	{
		if (i == currentChoise)
		{
			if (lstButton[i]->m_fScale < 1.3f)
				lstButton[i]->m_fScale += 0.1f;
		}
		else
		{
			lstButton[i]->m_fScale = 1.0f;
		}
		lstButton[i]->Update(dt);
	}

}

void OptionScreen::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backgroud->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 1);
	music->Draw(D3DXVECTOR2(230, 380), SpriteEffect::Vertical, 0, 1);
	sound->Draw(D3DXVECTOR2(600, 380), SpriteEffect::Vertical, 0, 1);
	quit->Draw(D3DXVECTOR2(400, 500), SpriteEffect::Vertical, 0, 1);
}

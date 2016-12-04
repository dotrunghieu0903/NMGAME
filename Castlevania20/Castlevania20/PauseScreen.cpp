#include "PauseScreen.h"
#include "ResourceManager.h"
#include "StateManager.h"
#include "MainGameScreen.h"
#include "MenuScreen.h"
#include "OptionScreen.h"
//#include "CLoadSaveGame.h"
PauseScreen::PauseScreen() :IGameState()
{
	m_stateType = EScreenType::PAUSE_SCREEN;
	backgroud = new Sprite(Texture::create("resource\\Image\\BackGround\\PauseBackground.png"));
}

//PauseScreen::PauseScreen(SaveGameInfor data) :IGameState()
//{
//	m_stateType = EScreenType::PAUSE_SCREEN;
//	backgroud = new Sprite(Texture::create("resource\\Image\\BackGround\\PauseBackground.png"));
//	_data = data;
//}

PauseScreen::~PauseScreen()
{
	Release();
}

void PauseScreen::Create()
{

	Sprite* resume = new Sprite(Texture::create("resource\\Image\\Button\\resume.png"), 2, 1, 2, 1, 1);
	Sprite* loadGame = new Sprite(Texture::create("resource\\Image\\Button\\loadgame.png"), 2, 1, 2, 0, 1);
	Sprite* option = new Sprite(Texture::create("resource\\Image\\Button\\option.png"), 2, 1, 2, 0, 1);
	Sprite* savegame = new Sprite(Texture::create("resource\\Image\\Button\\savegame.png"), 2, 1, 2, 0, 1);
	Sprite* quit = new Sprite(Texture::create("resource\\Image\\Button\\quit.png"), 2, 1, 2, 0, 1);

	lstButton.push_back(resume);
	lstButton.push_back(loadGame);
	lstButton.push_back(savegame);
	lstButton.push_back(option);
	lstButton.push_back(quit);

	currentChoise = 0;
}

void PauseScreen::Release()
{
	//if(backgroud!=NULL)
	//delete backgroud;
	//backgroud = NULL;
}

void PauseScreen::HandleInput(Input* input, float dt)
{
	if (input->IsKeyPress(DIK_RETURN))
	{
		switch (currentChoise)
		{
		case 0:
			ExitSceen();
			break;
		case 1:
		{
			ExitSceen();
			StateManager::GetInstance()->ClearAllScreen();
			//LoadSaveGame *load = new LoadSaveGame("MapCastlevania\\saved\\objects.txt", "MapCastlevania\\saved\\infor.txt");
			//load->Load();
			//SaveGameInfor infor = load->GetInfor();
			//GameObject::_creatingAfterObjects.clear();
			//StateManager::GetInstance()->AddScreen(new MainGameScreen(infor));
		}
		break;
		case 2:
		{
			/*SaveGame *saveGame = new	SaveGame(_data,
				"MapCastlevania\\saved\\objects.txt",
				"MapCastlevania\\saved\\infor.txt");
			saveGame->Save();*/
			ExitSceen();
		}
		break;
		case 3:
			StateManager::GetInstance()->AddScreen(new OptionScreen());
			break;
		case 4:
			ExitSceen();
			StateManager::GetInstance()->ClearAllScreen();
			StateManager::GetInstance()->AddScreen(new MenuScreen());
			break;
		}
	}

	if (input->IsKeyPress(DIK_DOWN))
	{
		if (currentChoise<lstButton.size() - 1)
			currentChoise++;
		else
			currentChoise = 0;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}
	if (input->IsKeyPress(DIK_UP))
	{
		if (currentChoise>0)
			currentChoise--;
		else
			currentChoise = lstButton.size() - 1;
		//SoundManager::GetInst()->PlaySoundEffect(ES_Click);
	}
	if (input->IsKeyPress(DIK_BACKSPACE))
	{
		ExitSceen();
	}
}

void PauseScreen::Update(float dt)
{
	for (int i = 0; i<lstButton.size(); i++)
	{
		if (i == currentChoise)
		{
			if (lstButton[i]->m_fScale < 1.3f)
				lstButton[i]->m_fScale += 0.1f;
			lstButton[i]->SetIndex(1);
		}
		else
		{
			lstButton[i]->m_fScale = 1.0f;
			lstButton[i]->SetIndex(0);
		}
		lstButton[i]->Update(dt);
	}

}

void PauseScreen::Draw()
{
	StateManager::GetInstance()->GetPreviousScreen()->Draw();
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backgroud->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 1, 0);
	for (int i = 0; i < lstButton.size(); i++)
	{
		lstButton[i]->Draw(D3DXVECTOR2(400, 269 + i * 50), SpriteEffect::Vertical, 0, 1, 0);
	}
}

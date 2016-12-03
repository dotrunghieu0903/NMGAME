#include "GameState.h"
//#include "CLoadSaveGame.h"

MenuScreen::MenuScreen() :IGameState()
{
	m_stateType = EScreenType::MENU_SCREEN;
	backgroud = new Sprite(ResourceManager::GetIns()->GetBackGround(MenuBackGround));
	//SoundManager::GetInst()->RemoveAllBGM();
	//SoundManager::GetInst()->PlayBGSound(EBGSound::EMenuSound);
	Sprite* newGame = new Sprite(Texture::create("resource\\Image\\Button\\newgame.png"), 2, 1, 2, 1, 1);
	Sprite* loadGame = new Sprite(Texture::create("resource\\Image\\Button\\loadgame.png"), 2, 1, 2, 0, 1);
	Sprite* option = new Sprite(Texture::create("resource\\Image\\Button\\option.png"), 2, 1, 2, 0, 1);
	Sprite* help = new Sprite(Texture::create("resource\\Image\\Button\\help.png"), 2, 1, 2, 0, 1);
	Sprite* quit = new Sprite(Texture::create("resource\\Image\\Button\\quit.png"), 2, 1, 2, 0, 1);

	lstButton.push_back(newGame);
	lstButton.push_back(loadGame);
	lstButton.push_back(option);
	lstButton.push_back(help);
	lstButton.push_back(quit);

	currentChoise = 0;
}

MenuScreen::~MenuScreen()
{
	Release();
}

void MenuScreen::Create()
{

}

void MenuScreen::Release()
{
	if(backgroud!=NULL)
	delete backgroud;
	backgroud = NULL;
}

void MenuScreen::HandleInput(Input* input, float dt)
{
	if (input->IsKeyPress(DIK_RETURN))
	{
		switch (currentChoise)
		{
		case 0:
			ExitSceen();
			//StateManager::GetInstance()->AddScreen(new MainGameScreen());
			break;
		case 1:
		{
			ExitSceen();
			//LoadSaveGame *load=new LoadSaveGame("MapMario\\saved\\objects.txt","MapMario\\saved\\infor.txt");
			//load->Load();
			//SaveGameInfor infor=load->GetInfor();
			//GameObject::_creatingAfterObjects.clear();
			//StateManager::GetInstance()->AddScreen(new MainGameScreen(infor));		
		}
		break;
		case 2:
			//StateManager::GetInstance()->AddScreen(new OptionScreen());
			break;
		case 3:
			//StateManager::GetInstance()->AddScreen(new HelpScreen());
			break;
		case 4:
			PostQuitMessage(0);
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

	if (input->IsKeyPress(DIK_P))
	{
		ExitSceen();
	}
}

void MenuScreen::Update(float dt)
{
	/*for (int i = 0; i<lstButton.size(); i++)
	{
		if (i == currentChoise)
		{
			lstButton[i]->SetIndex(1);
			if (lstButton[i]->m_fScale < 1.3f)
				lstButton[i]->m_fScale += 0.1f;
		}
		else
		{
			lstButton[i]->SetIndex(0);
			lstButton[i]->m_fScale = 1.0f;
		}
		lstButton[i]->Update(dt);
	}*/

}

void MenuScreen::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backgroud->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 1);
	for (int i = 0; i < lstButton.size(); i++)
	{
		lstButton[i]->Draw(D3DXVECTOR2(690, 269 + i * 50), SpriteEffect::Vertical, 0, 1);
	}
}

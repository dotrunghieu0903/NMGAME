#include "GameState.h"

HelpScreen::HelpScreen() :IGameState()
{
	m_stateType = EScreenType::MENU_SCREEN;
	backgroud = new Sprite(ResourceManager::GetIns()->GetBackGround(Help));
	Sprite* quit = new Sprite(Texture::create("resource\\Image\\Button\\quit.png"), 2, 1, 2, 1, 1);
	lstButton.push_back(quit);

}

HelpScreen::~HelpScreen()
{
	Release();
}

void HelpScreen::Create()
{

}

void HelpScreen::Release()
{
}

void HelpScreen::HandleInput(Input* input, float dt)
{
	if (input->IsKeyPress(DIK_BACKSPACE) || input->IsKeyPress(DIK_RETURN))
	{
		ExitSceen();
	}
}

void HelpScreen::Update(float dt)
{
	for (int i = 0; i<lstButton.size(); i++)
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
	}
}

void HelpScreen::Draw()
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	GL_graphic->m_pSpriteHandler->SetTransform(&matrix);
	backgroud->Draw(D3DXVECTOR2(400, 300), SpriteEffect::Vertical, 0, 1);
	for (int i = 0; i < lstButton.size(); i++)
	{
		lstButton[i]->Draw(D3DXVECTOR2(400, 450 + i * 50), SpriteEffect::Vertical, 0, 1);
	}
}

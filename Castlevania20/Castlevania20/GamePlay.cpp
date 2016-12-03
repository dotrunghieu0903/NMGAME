#include "GamePlay.h"



GamePlay::GamePlay(HINSTANCE hInstance, int _mode, bool _Isfullscreen, int _frameRate) :
	IGame(hInstance, _mode, _Isfullscreen, _frameRate)
{

};

GamePlay::GamePlay()
{

};

GamePlay::~GamePlay()
{
	IGame::~IGame();
};

void GamePlay::Init()
{
	/*ResourceManager::GetIns()->Init();
	StateManager::GetInstance()->AddScreen(new MenuScreen());*/
	GL_graphic = new Graphic(m_hWindow, m_hInstance, GL_scrWidth, GL_scrWidth, GL_windowMode);
	GL_graphic->Init();
}
void GamePlay::Update(float dt)
{
	/*StateManager::GetInstance()->Update(dt);
	StateManager::GetInstance()->UpdateInput(m_Input, dt);*/

};

void GamePlay::Render()
{
	GL_graphic->BeginRender();
//	GL_graphic->m_pSpriteHandler->SetTransform(&camera->GetTransform());
	GL_graphic->m_pSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	loadMap::getCurrentMap()->load();
	//StateManager::GetInstance()->Draw();

	GL_graphic->m_pSpriteHandler->End();
	GL_graphic->EndRender();
	GL_graphic->GetDevice()->Present(0, 0, 0, 0);
};

void GamePlay::Destroy()
{
	delete GL_graphic;
};
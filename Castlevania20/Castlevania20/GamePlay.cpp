#include "GamePlay.h"
#include "Simon.h"


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
	ResourceManager::GetIns()->Init();
	StateManager::GetInstance()->AddScreen(new MenuScreen());
}
void GamePlay::Update(float dt)
{
	StateManager::GetInstance()->Update(dt);
	StateManager::GetInstance()->UpdateInput(m_Input, dt);
};

void GamePlay::Render()
{
	GL_graphic->BeginRender();
	GL_graphic->m_pSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	//loadMap::getCurrentMap()->setMap(2);
	StateManager::GetInstance()->Draw();

	GL_graphic->m_pSpriteHandler->End();
	GL_graphic->EndRender();
	GL_graphic->GetDevice()->Present(0, 0, 0, 0);
};

void GamePlay::Destroy()
{
	delete GL_graphic;
};
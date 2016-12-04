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
	//ResourceManager::GetIns()->Init();
	//StateManager::GetInstance()->AddScreen(new MenuScreen());
	
	//Simon::getCurrentSimon()->_sprite = new Sprite(SIMON_SPRITE, 60, 66, 24, 8);
	//Simon::getCurrentSimon()->SetFrame();
}
void GamePlay::Update(float dt)
{
	/*StateManager::GetInstance()->Update(dt);
	StateManager::GetInstance()->UpdateInput(m_Input, dt);*/

};

void GamePlay::Render()
{
	GL_graphic->BeginRender();
	GL_graphic->m_pSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	loadMap::getCurrentMap()->load();
	//StateManager::GetInstance()->Draw();
	//Simon::getCurrentSimon()->m_Sprite->Render(100, -100, 22);
	//Simon::getCurrentSimon()->_sprite->Render(0, 66, 0);

	GL_graphic->m_pSpriteHandler->End();
	GL_graphic->EndRender();
	GL_graphic->GetDevice()->Present(0, 0, 0, 0);
};

void GamePlay::Destroy()
{
	delete GL_graphic;
};
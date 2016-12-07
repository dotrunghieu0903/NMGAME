#include "Game.h"



//#define BACKGROUND_FILE L"191_173110_5a4c1.jpg"
Game* Game::_game = 0;
Game * Game::getCurGame()
{
	if (_game == 0)
		_game = new Game();
	return _game;
}

void Game::GameInit()
{
	// cấu hình game
	Windows::getCurrentWindows()->initWindows();
	//Camera::getCurCamera(CAMERAX, CAMERAY, CAMERAWIDTH, CAMERAHEIGHT);
	Graphics::getCurGraphics()->initDirectX3D();
	Graphics::getCurGraphics()->initDirect3DDevice();
	Input::getCurrentInput()->InputInput();
	//swepyAABB = new CSweptAABB();

}

void Game::GameLoad()
{
	//GTexture* backgroundTT = new GTexture(BACKGROUND_FILE, 1, 1, 1);
	//GSprite tamp(backgroundTT,10);
	//_mybackground = new GSprite(backgroundTT, 10);
	/*map = new Map(L"Image\\Map.png");*/
	//GTexture* simonTT = ;
	//GSprite tamp(backgroundTT,10);
	Simon::getCurrentSimon()->_sptrite = new Sprite(new Texture(SIMON_SPRITE, 8, 3, 24), 50);

	//_bricks = new Bricks(0, 300, 2000, 32);
	//Quadtree::getCurrentQuadtree()->load();
	//Camera::getCurrentCamera()->Follow();
	//Input::getCurrentInput()->InputInput();
	/*_mghost = new Ghost(0, 302, 300, 302);
	_mspearguard = new Spearguard(100, 302, 300, 302);
	_mbat = new Bat(50, 280, 400, 280);*/

	map1 = new Map(LEVEL2_TXT, LEVEL2_PNG);
	map1->loadMap(85);
}
void Game::Collision()
{

}


void Game::GameRun(float deltatime)
{
	Input::getCurrentInput()->UpdateKeyboard();
	Simon::getCurrentSimon()->Update(deltatime);
	/*if (Simon::getCurrentSimon()->_x > 250) Camera::getCurrentCamera()->Follow();
	else
	{
		Camera::getCurrentCamera()->Unfollow();
	}*/
	Camera::getCurrentCamera()->Update(Simon::getCurrentSimon()->_x, Simon::getCurrentSimon()->_y);
	//Collision();

	////map->run();
	
	///*_mghost->Update(deltatime);
	//_mspearguard->Update(deltatime);
	//_mbat->Update(deltatime);*/
}

void Game::GameDraw()
{
	//map->draw();
	//GameDrawParameter();
	Camera::getCurrentCamera()->SetTransform();
	//_mybackground->Draw(0, 0);

	//State::getCurrentState()->draw();
	map1->render(0, 0);
	Simon::getCurrentSimon()->Draw();
	//Simon::getCurrentSimon()->_sptrite->DrawIndex(50,50,2);
	//listObject.clear();
	//Quadtree::getCurrentQuadtree()->_root->Retrieve(listObject);
	/*for each(BaseObject* tamp in listObject) {
		tamp->Draw();
	}*/
	/*_mghost->Draw();
	_mspearguard->Draw();
	_mbat->Draw();*/
}


void Game::GameDrawParameter()
{
	/*string str = "( X=" + std::to_string(Camera::getCurCamera()->getLocation().GetX()) + ", Y=" +
	std::to_string(Camera::getCurCamera()->getLocation().GetY()) + ")";
	Graphics::getCurGraphics()->PrintText(str.c_str(), 20, 10, 10, D3DCOLOR_XRGB(255, 255, 255));*/
}

Game::Game(int screen_width, int screen_height)
{
	Windows::getCurrentWindows()->_width = screen_width;
	Windows::getCurrentWindows()->_height = screen_height;
}

Game::Game()
{
}


Game::~Game()
{
	delete this;
}

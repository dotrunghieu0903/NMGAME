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

}

void Game::GameLoad()
{
	simon = new Simon(100, 50);
	map = new MapManager();
<<<<<<< HEAD
	menu = new Menu();
=======

	RECT rect;
	rect.top = 0;
	rect.bottom = 0;
	rect.left = 0;
	rect.right = 0;
	ghost = new Ghost(100, 100, rect);
	stair = new StairOn(0, 2759, 386, 50);
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
}
void Game::Collision()
{
	Simon::getCurrentSimon()->ReturnCheckCollision(map->getListObject());
	
}


void Game::GameRun(float deltatime)
{
	game_state = PLAYING;
	//update world
	if (game_state == MENUING && menu->is_Start())
	{
		delete menu;
		game_state = INTROING;
		intro = new Intro();
	}

	if (game_state == INTROING && intro->isFinish())
	{
		delete intro;
		//map = new MAP();
		//map->SetLevel(Play_State);
		//game_state = MAPING;
		game_state = PLAYING;
	}

	//if (game_state == MAPING && map->isFinish())
	//{
	//	delete map;
	//	StartGame(Play_State);
	//	game_state = PLAYING;
	//}

	/*if (game_state == PLAYING && game_ending)
	{
		level_clear = false;
		end = new END();
		game_state = ENDING;
	}*/

	switch (game_state)
	{
	case MENUING:
		menu->Update(deltatime);
		break;
	case MAPING:
		//simon->Update(t);
		//map->Update(t);
		break;
	case INTROING:
		intro->Update(deltatime);
		break;
	case PLAYING:
		GamePlayUpdate(deltatime);
		break;
	case PAUSING:
		break;
	case ENDING:
		//end->Update(t);
		break;
	default:
		break;
	}
	

}

void Game::GamePlayUpdate(float deltatime) {
	
	Input::getCurrentInput()->UpdateKeyboard();
	simon->Update(deltatime);
	if (Input::getCurrentInput()->IsKeyDown(DIK_M)) {
	map->NextMap();
	}
	/*for (int i = 0; i < map->getListObject().size(); i++) {
		if (map->getListObject()[i]->_type == 11) {
			map->getListObject()[i]->Update(deltatime);
		}
	}*/

	Camera::getCurrentCamera()->Update(simon->_x, simon->_y);
	Collision();
}

void Game::GameDraw()
{
	switch (game_state)
	{
	case MENUING:
		menu->Draw();
		break;
	case MAPING:
		//map->Render();
		//simon->Render();
		break;
	case INTROING:
		intro->Draw();
		break;
	case PLAYING:
		GamePlayRender();
		break;
	case PAUSING:
		GamePlayRender();
		break;
	case ENDING:
		//end->Render();
		break;
	default:
		break;
	}
}

void Game::GamePlayRender() {
	Camera::getCurrentCamera()->SetTransform();
<<<<<<< HEAD
	//render map
	map->Draw();
	//render simon
	simon->Draw();
	//object
	//board
=======
	//_mybackground->Draw(0, 0);

	//State::getCurrentState()->draw();
	Simon::getCurrentSimon()->Draw();
	//Simon::getCurrentSimon()->_sptrite->DrawIndex(50,50,5);
	//listObject.clear();
	//Quadtree::getCurrentQuadtree()->_root->Retrieve(listObject);
	/*for each(BaseObject* tamp in listObject) {
		tamp->Draw();
	}*/
	/*_mghost->Draw();
	_mspearguard->Draw();
	_mbat->Draw();*/
	ghost->Draw();
	stair->Draw();
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
}


void Game::GameDrawParameter()
{

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

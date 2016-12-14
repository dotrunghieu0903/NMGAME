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
	simon = new Simon(3680, 1504);
	map = new MapManager();
	menu = new Menu();

}
void Game::Collision(float dt)
{
	simon->ReturnCheckCollision(map->getListObject(), dt);
	
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
	//update input
	Input::getCurrentInput()->UpdateKeyboard();
	//update object
	for (int i = 0; i < map->getListObject().size(); i++) {
		if (map->getListObject()[i]->_type == TypeGame::Enemy_Knight) {
			map->getListObject()[i]->Update(deltatime);
		}
	}
	//update viewport
	Camera::getCurrentCamera()->Update(simon->_x, simon->_y);
	//update simon
	simon->Update(deltatime);
	Collision(deltatime);
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

	//render map
	map->Draw();
	//render simon
	simon->Draw();
	//object
	//board

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

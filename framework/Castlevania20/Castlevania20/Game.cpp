#include "Game.h"
#include "Resources.h"
#include "Item.h"


//#define BACKGROUND_FILE L"191_173110_5a4c1.jpg"
Game* Game::_game = 0;
vector<ITEM *> listItem;
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
	bool b = DirectSound_Init(Windows::getCurrentWindows()->_hWindows);
	GameLoad();
}

void Game::Run() {

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	DWORD frame_start = GetTickCount();
	DWORD count_per_frame = 1000 / FRAME_RATE;

	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			DWORD now = GetTickCount();
			float deltaTime = now - frame_start;
			if (now - frame_start >= count_per_frame)

				if (deltaTime >= count_per_frame)
				{
					frame_start = now;
					float delta_time = (float)deltaTime / 1000;
					if (deltaTime > count_per_frame)
						deltaTime = count_per_frame;

					GameRun(deltaTime);
					Graphics::getCurGraphics()->BeginGraphics();
					GameDraw();
					Graphics::getCurGraphics()->EndGraphics();
					Sleep(GAME_SPEED);
				}
			Input::getCurrentInput()->PollKeyboard();
		}
	}

}

void Game::GameLoad()
{
	//simon = new Simon(3680, 1504);
	initSound();
	simon = new Simon(580, 190);
	menu = new Menu();
	board = new Board();
	listItem.push_back(new ITEM(23, 500, 190));
	listItem.push_back(new ITEM(24, 520, 190));
	listItem.push_back(new ITEM(25, 540, 190));
	listItem.push_back(new ITEM(26, 560, 190));
	listItem.push_back(new ITEM(27, 600, 190));
	listItem.push_back(new ITEM(28, 620, 190));
	listItem.push_back(new ITEM(29, 640, 190));
	listItem.push_back(new ITEM(30, 660, 190));
	listItem.push_back(new ITEM(31, 680, 190));
	listItem.push_back(new ITEM(32, 700, 190));
	listItem.push_back(new ITEM(33, 720, 190));
	listItem.push_back(new ITEM(34, 740, 190));
	listItem.push_back(new ITEM(35, 760, 190));
}



void Game::GameRun(float deltatime)
{

	if (game_state == MENU && menu->isStarted())
	{
		delete menu;
		game_state = INTROING;
		intro = new Intro();
	}

	if (game_state == INTROING && intro->isFinish())
	{
		delete intro;
		map = new MapManager();
		map->stage = 6;
		game_state = PLAYING;
	}

	/*if (game_state == MAPING && world->isStop)
	{
		delete world;
		map = new MapManager(2);
		game_state = PLAYING;
	}*/

	/*if (game_state == PLAYING && game_ending)
	{
		level_clear = false;
		end = new END();
		game_state = ENDING;
	}*/

	switch (game_state)
	{
	case MENU:
		menu->Update(deltatime);
		break;
	case INTROING:
		intro->Update(deltatime);
		break;
	case MAPING:
		world->Update(deltatime);
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

void Game::StartGame(int mapLevel)
{

}

void Game::Collision(float dt)
{
	simon->ReturnCheckCollision(map->getCurrentObject(), dt);
}

void Game::GamePlayUpdate(float deltatime) {

	if (map->is_newStage) {
		map->updateCurrentObject();
		if (map->getCurrentObject().size() != 0) {
			map->is_newStage = false;
		}
	}
	Camera::getCurrentCamera()->Update(simon->_x, simon->_y, map->stage);
	if (this->staging) { 
		
		for (int i = 0; i < map->getCurrentObject().size(); i++) {
			if (map->getCurrentObject()[i]->_type == TypeGame::Ground_Lockdoor) {
				map->getCurrentObject()[i]->Update(deltatime);
			}
		}
		tickcount += deltatime;
		if (tickcount > 2000) {
			simon->Update(deltatime);
			map->stage++;
			staging = false;
		}
		return; 
	}
	Input::getCurrentInput()->UpdateKeyboard();

	//update object
	for (int i = 0; i < map->getCurrentObject().size(); i++) {
		if (map->getCurrentObject()[i]->_type != TypeGame::Ground_Brick) {
			if (map->getCurrentObject()[i]->_type == TypeGame::Enemy_Ghost ||
				map->getCurrentObject()[i]->_type == TypeGame::Enemy_Bat||
				map->getCurrentObject()[i]->_type == TypeGame::Enemy_DragonSkull||
				map->getCurrentObject()[i]->_type == TypeGame::Boss_Medusa) {
				map->getCurrentObject()[i]->Update(simon->_x,simon->_y,deltatime);
			}
			else {
				map->getCurrentObject()[i]->Update(deltatime);
			}
			
		}
	}
	//update viewport
	
	//update simon
	simon->Update(deltatime);
	Collision(deltatime);

	//update stage
	int count = 0;
	for (int i = 0; i < map->getCurrentObject().size(); i++) {
		if (map->getCurrentObject()[i]->_type != TypeGame::Ground_Brick) {
			count++;
		}
	}

	switch (map->stage)
	{
	case 1:
		if(simon->_y <= 1200 && simon->_x >=3830){
			simon->goStage(2);
			map->stage++;
			map->is_newStage = true;
		}
		break;
	case 2:
		if (simon->staging) {
			simon->goStage(3);
			//Camera::getCurrentCamera()->change = true;
			staging = true;
			//map->stage++;
			//map->is_newStage = true;
		}
		break;
	case 3:
		if (simon->_y == 818 && simon->_x == 1656) {
			simon->goStage(4);
			map->stage++;
			map->is_newStage = true;
		}
		break;
	case 4:
		if (simon->staging) {
			simon->goStage(5);
			//Camera::getCurrentCamera()->change = true;
			staging = true;
			//map->stage++;
			//map->is_newStage = true;
		}
		break;
	default:
		break;
	}
	//update board
	board->Update(deltatime);
	#pragma region ITEM
	for each (ITEM * item in listItem)
	{
		item->Update(deltatime);
		item->ReturnCheckCollision(map->getCurrentObject(), deltatime);
		if ( simon->CheckCollision(item,deltatime) != COLLIDED_NONE && item->item_state == ALIVE)
		{
			simon->PickUpItem(item);
			item->Die();
			item->item_state = DYING;
		}

	}
	#pragma endregion
	
}

void Game::GameDraw()
{
	switch (game_state)
	{
	case MENU:
		menu->Draw();
		break;
	case MAPING:
		world->Draw();
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
	//board->Draw(Camera::getCurrentCamera()->getViewPortX(), Camera::getCurrentCamera()->getViewPortY());
	board->DrawBG();
	board->DrawProperty();
	for each (ITEM * item in listItem)
		item->Draw();

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
	deleteSound();
	for each (ITEM * itm in listItem)
		delete itm;
	listItem.clear();
}

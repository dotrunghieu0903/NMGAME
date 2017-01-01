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
	simon = new Simon(3680, 1504);
	//simon = new Simon(1176, 203);
	initSound();

	over = new Sprite(new Texture(L"resource\\sprite\\game_over.png", 2, 1,2), 100);
	menu = new Menu();
	last_time_count = 0;
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
		//map->stage = 6;
		game_state = PLAYING;
		board = new Board();
	}

	

	/*if (game_state == MAPING && world->isStop)
	{
		delete world;
		map = new MapManager(2);
		game_state = PLAYING;
	}*/

	if (game_state == PLAYING && nextLevel)
	{
		delete map;
		map = new MapManager(3);
		simon->goStage(7);
		nextLevel = false;
		Camera::getCurrentCamera()->lock = false;
	}

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
	case GAME_OVER:
		over->Update(deltatime);
		if (Input::getCurrentInput()->IsKeyDown(DIK_RETURN)) {
			game_state = MENU;
			delete map;
			menu = new Menu();
		}
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
	Camera::getCurrentCamera()->Update(simon->_x, simon->_y, map->stage);
	if (nextLevel) {
		return;
	}
	if (simon->_life == -1) {
		game_state = GAME_OVER;
	}

	if (map->is_newStage) {
		map->updateCurrentObject();
		if (map->getCurrentObject().size() != 0) {
			map->is_newStage = false;
		}
	}
	//
	if (map->is_boss_death()) {
		nextLevel = true;
	}
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
	
		if (map->getCurrentObject()[i]->_type == TypeGame::Enemy_Ghost ||
			map->getCurrentObject()[i]->_type == TypeGame::Enemy_Bat||
			map->getCurrentObject()[i]->_type == TypeGame::Enemy_DragonSkull||
			map->getCurrentObject()[i]->_type == TypeGame::Boss_Medusa ||
			map->getCurrentObject()[i]->_type == TypeGame::Enemy_Medusahead) {
			map->getCurrentObject()[i]->Update(simon->_x,simon->_y,deltatime);
		}
		else {
			map->getCurrentObject()[i]->Update(deltatime);
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
	case 5:
		if (simon->_x == 1334 && simon->_y == 431) {
			simon->goStage(6);
			map->stage++;
			map->is_newStage = true;
		}
		break;
	default:
		break;
	}
	//update board
	#pragma region BOARD
	if (GetTickCount() - last_time_count > 1000 && board->_Time > 0)
	{
		board->setTime();
		last_time_count = GetTickCount();
	}
	board->Update(simon, deltatime);
	#pragma endregion

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
	case GAME_OVER:
	over->Draw(170, 200);
		break;
	case ENDING:
		//end->Render();
		break;
	default:
		break;
	}
}

void Game::GamePlayRender() {
	if (nextLevel) {
		return;
	}
	Camera::getCurrentCamera()->SetTransform();


	//render map
	map->Draw();
	//render simon
	simon->Draw();
	//object
	//board
	//board->Draw(Camera::getCurrentCamera()->getViewPortX(), Camera::getCurrentCamera()->getViewPortY());
	//board->DrawBG();
	board->Draw();
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

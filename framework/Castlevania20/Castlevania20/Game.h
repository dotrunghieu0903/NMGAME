#ifndef _GAME_H_
#define _GAME_H_

#pragma once
#include "Graphics.h"
#include "Texture.h"
#include "Sprite.h"
#include "Camera.h"
#include "MapManager.h"
#include <string>
#include "BaseObject.h"
#include "Ground.h"

#include "Board.h"
#include "Menu.h"
#include "Intro.h"
#include "World.h"


enum GAMESTATE { MENU, INTROING, MAPING, PLAYING, PAUSING, GAME_OVER, ENDING };



class Game
{
	Simon *simon;
	GAMESTATE game_state;
	static Game* _game;
	Intro *intro;
	World *world;
	Menu *menu;
	Board *board;
	bool staging = false;
	int tickcount = 0;
	Sprite *over;
	bool nextLevel = false;
public:
	DWORD last_time_count;
	static Game* getCurGame();

	vector<BaseObject*> listObject;
	void GameInit();
	void GameLoad();
	void GameRun(float deltatime);
	void GameDraw();
	void GamePlayRender();
	void GamePlayUpdate(float);
	void Collision(float dt);
	MapManager *map;
	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();

	void Run();
	void StartGame(int mapLevel);
};

#endif
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

#include "Menu.h"
#include "Intro.h"


enum GAMESTATE { MENUING, INTROING, MAPING, PLAYING, PAUSING, ENDING };



class Game
{
	GAMESTATE game_state;
	static Game* _game;
	Simon *simon;
	Intro *intro;
	Menu *menu;

public:
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
};

#endif
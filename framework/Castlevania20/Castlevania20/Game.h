#ifndef _GAME_H_
#define _GAME_H_

#pragma once
#include "Graphics.h"
#include "Texture.h"
#include "Sprite.h"
#include "Simon.h"
#include "Camera.h"
#include "MapManager.h"
#include <string>
#include "BaseObject.h"
#include "Ground.h"
#include <vector>
using namespace std;


class Game
{
	static Game* _game;

public:
	static Game* getCurGame();

	vector<BaseObject*> listObject;
	void GameInit();
	void GameLoad();
	void GameRun(float deltatime);
	void GameDraw();
	void Collision();

	Ground *demoGround;
	
	MapManager *map;
	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();
};

#endif
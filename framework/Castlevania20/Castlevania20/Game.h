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
<<<<<<< HEAD
#include "Menu.h"
#include "Intro.h"


enum GAMESTATE { MENUING, INTROING, MAPING, PLAYING, PAUSING, ENDING };
=======
//#include "StairOn.h"
//test
#include "Ghost.h"
#include "StairOn.h"
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167


class Game
{
	GAMESTATE game_state;
	static Game* _game;
<<<<<<< HEAD
	Simon *simon;
	Intro *intro;
	Menu *menu;
=======
	Ghost *ghost;
	StairOn *stair;
>>>>>>> 874e7b5b9c5a841ac0562551d31a4e8b9be8c167
public:
	static Game* getCurGame();

	vector<BaseObject*> listObject;
	void GameInit();
	void GameLoad();
	void GameRun(float deltatime);
	void GameDraw();
	void GamePlayRender();
	void GamePlayUpdate(float);
	void Collision();
	MapManager *map;
	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();
};

#endif
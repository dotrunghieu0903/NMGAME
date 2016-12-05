#pragma once
#include "Graphics.h"
#include "Texture.h"
#include "Sprite.h"
#include "Simon.h"
#include "Camera.h"
#include <string>
#include "BaseObject.h"
#include <vector>
using namespace std;

#define SIMON_SPRITE L"simon.png"

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

	void GameDrawParameter();
	Game(int screen_width, int screen_height);
	Game();
	~Game();
};


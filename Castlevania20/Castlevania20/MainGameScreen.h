#ifndef _MAINGAMESCREEN_H_
#define _MAINGAMESCREEN_H_
#include "IGameState.h"
#include "StateManager.h"
//#include "GameObj.h"
#include "Simon.h"
#include "FrameWork.h"
#include "loadMap.h"
//#include "CQuadtree.h"

class MainGameScreen : public IGameState
{
private:
	Simon* simon;
	CCamera *camera;
	Sprite* backGround;
	CText* m_text;
	int mapWidth;
	byte level;
	float timeWait;
	bool changeToBonusMap;
public:
	MainGameScreen();
	MainGameScreen(Simon*, __int8); // Simon & level
	~MainGameScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();

	void DrawString();
	static int score;
	static int coin;
	static int life;
	static float time;
	static bool hasBonus;
};

#endif // _MAINGAMESCREEN_H_

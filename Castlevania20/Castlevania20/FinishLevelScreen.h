#ifndef _FINISHLEVEL_H
#define _FINISHLEVEL_H
#include "IGameState.h"
#include "Sprite.h"
#include "Text.h"
//#include "Simon.h"

class FinishLevelScreen : public IGameState
{
private:
	Sprite* backgroud;
	CText* m_text;
	//Simon* simon;
	Sprite *simonLife;
	Sprite *coinCount;
	D3DXVECTOR2 simonPos;
	D3DXVECTOR2 coinPos;
	int level;
	int time;
	int score;
	int life;
	int coin;

	float timeCountCoin;
	float timeCountTimes;
	float timeWaitToNextLv;
public:
	//FinishLevelScreen(Simon*, int);
	virtual ~FinishLevelScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();
};

#endif

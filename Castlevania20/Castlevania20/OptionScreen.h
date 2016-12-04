#ifndef _OPTIONSCREEN_H
#define _OPTIONSCREEN_H
#include "GameState.h"
#include "IGameState.h"
#include "Sprite.h"
#include <vector>
using namespace std;

class OptionScreen : public IGameState
{
private:
	Sprite* backgroud;
	vector<Sprite*> lstButton;
	int currentChoise;
	Sprite* music;
	Sprite* sound;
	Sprite* quit;
public:
	OptionScreen();
	virtual ~OptionScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();
};

#endif

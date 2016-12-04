#ifndef _HELPSCREEN_H
#define _HELPSCREEN_H
#include "IGameState.h"
#include "Sprite.h"
#include <vector>
using namespace std;

class HelpScreen : public IGameState
{
private:
	Sprite* backgroud;
	vector<Sprite*> lstButton;
	int currentChoise;
	Sprite* music;
	Sprite* sound;
public:
	HelpScreen();
	virtual ~HelpScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();
};

#endif

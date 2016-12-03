#ifndef _MENUSCREEN_H
#define _MENUSCREEN_H
#include "IGameState.h"
#include "Sprite.h"
#include <vector>
#include "Text.h"
using namespace std;

class MenuScreen : public IGameState
{
private:
	Sprite* backgroud;
	vector<Sprite*> lstButton;
	int currentChoise;
public:
	MenuScreen();
	virtual ~MenuScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();
};

#endif // _MENUSCREEN_H

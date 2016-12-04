#ifndef _PAUSESCREEN_H
#define _PAUSESCREEN_H
#include "IGameState.h"
#include "Sprite.h"
#include <vector>
//#include "SaveGame.h"

using namespace std;

class PauseScreen : public IGameState
{
private:
	Sprite* backgroud;
	vector<Sprite*> lstButton;
	int currentChoise;
	//SaveGameInfor _data;
public:
	PauseScreen();
	//PauseScreen(SaveGameInfor data);
	virtual ~PauseScreen();

	virtual void Create();
	virtual void Release();
	virtual void HandleInput(Input*, float);
	virtual void Update(float dt);
	virtual void Draw();
};

#endif // _PAUSESCREEN_H

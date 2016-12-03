#ifndef _IGAMESTATE_
#define _IGAMESTATE_
#include "Input.h"
enum EScreenType
{
	MENU_SCREEN,
	SETTING_SCREEN,
	PLAY_SCREEN,
	PAUSE_SCREEN,
	WIN_SCREEN,
	LOSE_SCREEN,
	LOADING_SCREEN
};

class IGameState
{
protected:
	EScreenType m_stateType;
public:
	IGameState();
	virtual ~IGameState();
	virtual void Create();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw();
	virtual void HandleInput(Input*, float);
	virtual void ExitSceen();
};

#endif
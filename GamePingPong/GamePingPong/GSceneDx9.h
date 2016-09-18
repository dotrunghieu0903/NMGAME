#ifndef __SCENE_H__
#define __SCENE_H__
#include "DefineMacro.h"
#include "d3d9.h"
#include "d3dx9.h"

class GSceneDx9
{
protected:
	ESceneGameID eSceneGameID;
public:
	GSceneDx9(ESceneGameID ID) { eSceneGameID = ID; }
	virtual void HandleInput() = 0;
	virtual void InitializeState(LPDIRECT3DDEVICE9 _lpDirectDevice) = 0;
	virtual void Pause() = 0;
	virtual void Release() = 0;
	virtual void Render(LPD3DXSPRITE _lpDSpriteHandle) = 0;
	virtual void Resume() = 0;
	virtual void Update() = 0;
	virtual ~GSceneDx9() {}
};

#endif
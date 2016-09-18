#ifndef __GMENU_SCENE_H__
#define __GMENU_SCENE_H__

#include "GSceneDx9.h"
#include "GSpriteDx9.h"

class GMenuScene : public GSceneDx9
{
private:
	// add more game element here
	GSpriteDx9* spriteDemo;
public:
	GMenuScene(ESceneGameID ID) : GSceneDx9(ID) { }
	~GMenuScene() {}
	void InitializeState(LPDIRECT3DDEVICE9 _lpDirectDevice);
	void HandleInput();
	void Update();
	void Render(LPD3DXSPRITE _lpDSpriteHandle);
	void Pause();
	void Resume();
	void Release();
};


#endif
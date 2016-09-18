#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
#include "GSceneDx9.h"
#include "DefineMacro.h"
#include <vector>
using namespace std;

class GSceneManagerDx9
{
private:

	GSceneManagerDx9() {}
	~GSceneManagerDx9() {}
	vector<GSceneDx9*> m_ListGameScene;
	static GSceneManagerDx9* s_Instance;
	LPDIRECT3DDEVICE9		m_lpDirectDevice;
public:
	static GSceneManagerDx9* getInstance();
	void setDirectDevice(const LPDIRECT3DDEVICE9& lpDirectDevice);
	void Initialize();
	void HandleInput();
	void Update();
	void Render(LPD3DXSPRITE _lpDSpriteHandle);
	void AddElement(GSceneDx9* gameScene);
	void ExitState();
	void ReplaceBy(GSceneDx9* gameScene);
	void ClearAll();
};

#endif
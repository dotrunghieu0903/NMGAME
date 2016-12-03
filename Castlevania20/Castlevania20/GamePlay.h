
#ifndef	_GAMEPLAY_H
#define _GAMEPLAY_H

#include "IGame.h"
#include "Globals.h"
#include "FrameWork.h"
//#include "GameObj.h"
#include "StateManager.h"
#include "MenuScreen.h"
//#include "CLoadMap.h"
//#include "CQuadtree.h"

#include <vector>
class GamePlay : public IGame
{
public:
	//Constructor and Destructor
	GamePlay(void);
	GamePlay(HINSTANCE hInstance, int _mode, bool _Isfullscreen, int _framRate);
	~GamePlay();

	//Public method
	void	Init();
	void	Update(float dt);
	void	Render();
	void	Destroy();
	

private:
	//private variables
	// 	Mario *mario;
	// 	CCamera *camera;
	// 	list<GameObject*> _listObjectsInViewport;
	// 	CLoadMap *loadMap;
	// 	CQuadtree *quadtree;
};





#endif
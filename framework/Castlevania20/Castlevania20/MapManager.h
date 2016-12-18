#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_
#include "Map.h"
#include "BaseObject.h"
#include "Ground.h"
#include "Ghost.h"
#include "BlackKnight.h"
#include "MedusaHead.h"
#include "FireCandle.h"
#include "Quadtree.h"
#include "Camera.h"
#include <vector>
#include "StairOn.h"
using namespace std;

#pragma once
class MapManager
{
	int level;
	int stage;
	Map* currentMap; //map de ve
	vector<BaseObject*> _listObject; //danh sach cac object co trong map nay
	vector<BaseObject*> _currentObjects;//danh sach cac object dang du dung
	int countObject;
	Quadtree *currentQuadtree;
public:
	MapManager();
	MapManager(int state);
	bool is_stageClear = true;
	void reset();
	void Draw();
	void setMap(int index);
	void NextMap();
	void Update();
	void LoadObject(char * objectPath);
	vector<BaseObject*> getCurrentObject();
	vector<BaseObject*> getListObject();
	void updateCurrentObject();
	~MapManager();
};
#endif

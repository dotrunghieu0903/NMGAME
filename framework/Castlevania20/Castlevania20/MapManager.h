#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_
#include "Map.h"
#include "BaseObject.h"
#include "Ground.h"
#include "Ghost.h"
#include "BlackKnight.h"
#include "Quadtree.h"
#include "Camera.h"
#include <vector>
#include "StairOn.h"
using namespace std;

#pragma once
class MapManager
{
	int mapIndex;
	Map* currentMap; //map de ve
	vector<BaseObject*> _listObject; //danh sach cac object co trong map nay
	int countObject;
	Quadtree *currentQuadtree;
public:
	MapManager();
	MapManager(int state);
	void reset();
	void Draw();
	void setMap(int index);
	void NextMap();
	void Update();
	void LoadObject(char * objectPath);
	vector<int> getCurrentIDObject();
	vector<BaseObject*> getListObject();

	~MapManager();
};
#endif

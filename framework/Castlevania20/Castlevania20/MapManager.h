#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_
#include "Map.h"
#include "BaseObject.h"
#include "Ground.h"
#include "Quadtree.h"
#include "Camera.h"
#include <vector>
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
	void reset();
	void Draw(int x, int y);
	void setMap(int index);
	void NextMap();
	void Update();
	void LoadObject(char * objectPath);
	~MapManager();
};
#endif

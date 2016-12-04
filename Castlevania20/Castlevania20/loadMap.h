#pragma once
#include "Map.h"
class loadMap
{
	int mapIndex = 2;
	//Map** _listMap;
	Map * map1;
	Map * map2;
public:
	loadMap();
	void setMap(int index);
	~loadMap();
	void load();
	static loadMap* _loadMap;
	static loadMap* getCurrentMap();
};


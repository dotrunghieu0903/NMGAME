#pragma once
#include "Map.h"
class loadMap
{
	int mapIndex;
	Map* currentMap;
public:
	loadMap();
	void setMap(int index);
	~loadMap();
	void load();
	static loadMap* _loadMap;
	static loadMap* getCurrentMap();
};


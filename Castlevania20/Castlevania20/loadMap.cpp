#include "loadMap.h"



loadMap::loadMap()
{

	//stage1
	currentMap = new Map(STAGE1_TXT, STAGE1_PNG);
	currentMap->loadMap();

}

void loadMap::load() {
	currentMap->render(200,200);
}

void loadMap::setMap(int index) {
	index = mapIndex;
}


loadMap::~loadMap()
{
	delete currentMap;
	delete _loadMap;
	delete getCurrentMap();
}


loadMap* loadMap::_loadMap = 0;
loadMap* loadMap::getCurrentMap() {
	if (!_loadMap)
		_loadMap = new loadMap();
	return _loadMap;
}
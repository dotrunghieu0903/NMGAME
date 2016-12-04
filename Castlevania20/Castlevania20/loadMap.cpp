#include "loadMap.h"



loadMap::loadMap()
{
	//stage1
	/*_listMap = new Map*[3];
	_listMap[0] = new Map(STAGE1_TXT, STAGE1_PNG);
	_listMap[0]->loadMap(149);
	_listMap[1] = new Map(STAGE2_TXT, STAGE2_PNG);
	_listMap[1]->loadMap(85);*/
	map1 = new Map(STAGE1_TXT, STAGE1_PNG);
	map1->loadMap(149);
	map2 = new Map(STAGE2_TXT, STAGE2_PNG);
	map2->loadMap(85);

}

void loadMap::load() {
	map2->render(0,352);//map height	
}

void loadMap::setMap(int index) {
	index = mapIndex;
}


loadMap::~loadMap()
{
	delete _loadMap;
	delete getCurrentMap();
}


loadMap* loadMap::_loadMap = 0;
loadMap* loadMap::getCurrentMap() {
	if (!_loadMap)
		_loadMap = new loadMap();
	return _loadMap;
}
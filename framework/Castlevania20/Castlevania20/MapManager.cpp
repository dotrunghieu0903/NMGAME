#include "MapManager.h"



MapManager::MapManager()
{
	mapIndex = 1;
	currentMap = new Map(LEVEL1_TXT, LEVEL1_PNG);
	currentMap->loadMap(149);
	this->LoadObject(LEVEL1_OBEJCT);
	
}


void MapManager::reset() {
	delete currentMap;
	_listObject.clear();
	//delete _listObject;
}

void MapManager::Draw(int x, int y) {
	currentMap->render(x, y);

	//draw all object
	for (int i = 0; i < countObject; i++) {
		_listObject[i]->Draw();
	}
}

void MapManager::setMap(int index) {
	this->mapIndex = index;
}	

void MapManager::NextMap() {
	this->mapIndex++;
	this->Update();
}

void MapManager::Update() {
	this->reset();
	switch (mapIndex)
	{
	case 1:
		currentMap = new Map(LEVEL1_TXT, LEVEL1_PNG);
		currentMap->loadMap(149);
		this->LoadObject(LEVEL1_OBEJCT);
		break;
	case 2:
		currentMap = new Map(LEVEL2_TXT, LEVEL2_PNG);
		currentMap->loadMap(85);
		this->LoadObject(LEVEL2_OBEJCT);
		break;
	default:
		break;
	}
}

void MapManager::LoadObject(char* _objectPath) {
	FILE *fp;
	try
	{
		int N;
		fp = fopen(_objectPath, "r");
		fscanf(fp, "%d", &countObject);

		for (int i = 0; i < countObject; i++) {
			int id, type, x, y, width, height;
			fscanf(fp, "%d", &id);
			fscanf(fp, "%d", &type);
			fscanf(fp, "%d", &x);
			fscanf(fp, "%d", &y);
			fscanf(fp, "%d", &width);
			fscanf(fp, "%d", &height);
			switch (type)
			{
			case 5://fix to -> TypeGame::Ground_Brick
				_listObject.push_back(new Ground(x, y,width, height));
				break;
			default:
				break;
			}
		}
	}
	catch (const std::exception&)
	{
	}
}

MapManager::~MapManager()
{
}

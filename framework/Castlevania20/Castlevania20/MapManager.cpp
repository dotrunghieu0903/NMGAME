#include "MapManager.h"



MapManager::MapManager()
{
	mapIndex = 1;
	currentMap = new Map(LEVEL1_TXT, LEVEL1_PNG);
	currentMap->loadMap(149);
	this->LoadObject(LEVEL1_OBEJCT);
	currentQuadtree = new Quadtree();
	currentQuadtree->load(LEVEL1_QUADTREE);
	
}


void MapManager::reset() {
	delete currentMap;
	_listObject.clear();
	//delete _listObject;
}

void MapManager::Draw(int x, int y) {
	currentMap->render(x, y);
	
	vector<int>  currentObjectid = this->getCurrentIDObject();
	//draw all object
	int size;
	for (int i = 0; i < currentObjectid.size(); i++) {
		_listObject[currentObjectid[i]]->Draw();
	}
}

vector<int> MapManager::getCurrentIDObject() {
	vector<int> currentObject = this->currentQuadtree->Retrieve(Camera::getCurrentCamera()->getViewPort());
	return currentObject;
}

vector<BaseObject*> MapManager::getListObject() {
	return _listObject;
}

void MapManager::setMap(int index) {
	this->mapIndex = index;
}	

void MapManager::NextMap() {
	if (mapIndex == 2) {
		mapIndex = 0;
	}
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

	ifstream myfile(_objectPath);
	myfile >> countObject;
	int id = 0, type = 0, x = 0, y = 0, width = 0, height = 0;
	while (!myfile.eof())
	{
		myfile >> id;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;

		switch (type)
		{
		case 5://fix to -> TypeGame::Ground_Brick
			_listObject.push_back(new Ground(id, x, y, width, height));
			break;
		default:
			break;
		}
	}
}

MapManager::~MapManager()
{
}

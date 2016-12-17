#include "MapManager.h"



MapManager::MapManager()
{
	mapIndex = 2;
	currentMap = new Map(LEVEL2_TXT, LEVEL2_PNG);
	currentMap->loadMap(LEVEL2_COUNT);
	this->LoadObject(LEVEL2_OBEJCT);
	//currentQuadtree = new Quadtree();
	//currentQuadtree->load(LEVEL2_QUADTREE);
	
}
MapManager::MapManager(int state)
{
	mapIndex = state;
	switch (mapIndex)
	{
	//case 1:
	//	currentMap = new Map(STATE1_TXT, STATE1_PNG);
	//	currentMap->loadMap(STATE1_COUNT);
	//	this->LoadObject(STATE1_OBEJCT);
	//	break;
	case 2:
		currentMap = new Map(LEVEL2_TXT, LEVEL2_PNG);
		currentMap->loadMap(LEVEL2_COUNT);
		this->LoadObject(LEVEL2_OBEJCT);
		break;
	case 3:
		currentMap = new Map(LEVEL3_TXT, LEVEL2_PNG);
		currentMap->loadMap(LEVEL3_COUNT);
		this->LoadObject(LEVEL3_OBEJCT);
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
	//currentQuadtree = new Quadtree();
	//currentQuadtree->load(LEVEL2_QUADTREE);

}


void MapManager::reset() {
	delete currentMap;
	_listObject.clear();
	//delete _listObject;
}

void MapManager::Draw() {
	currentMap->render(0,0);
	
	//vector<int>  currentObjectid = this->getCurrentIDObject();

	int size;
	/*for (int i = 0; i < currentObjectid.size(); i++) {
		_listObject[currentObjectid[i]]->Draw();
	}*/
	//draw all
	for (int i = 0; i < _listObject.size(); i++) {
		_listObject[i]->Draw();
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
	//case 1:
	//	currentMap = new Map(LEVEL1_TXT, LEVEL1_PNG);
	//	currentMap->loadMap(149);
	//	this->LoadObject(LEVEL1_OBEJCT);
	//	break;
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
	int id = 0, type = 0, x = 0, y = 0, width = 0, height = 0, bound_x, bound_y, bound_width, bound_height;
	for(int i = 0; i< countObject; i++)
	{
		myfile >> id;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		myfile >> bound_x;
		myfile >> bound_y;
		myfile >> bound_width;
		myfile >> bound_height;
		RECT bound = { bound_x, bound_y,   bound_x + bound_width,  bound_y + bound_height };
		

		switch (type)
		{
		case TypeGame::Ground_Brick:
			_listObject.push_back(new Ground(id, bound_x, bound_y, bound_width, bound_height));
			break;
		case TypeGame::Enemy_Ghost:
			_listObject.push_back(new Ghost(id, x, y, bound));
			break;
		case TypeGame::Ground_Stair_Up:
			_listObject.push_back(new Ground(id, bound_x, bound_y, bound_width, bound_height));
			break;
		case TypeGame::Enemy_Knight:
			_listObject.push_back(new BlackKnight(id, x, y, bound));
			break;
		default:
			break;
		}
	}
}

MapManager::~MapManager()
{
}

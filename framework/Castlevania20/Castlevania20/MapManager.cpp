#include "MapManager.h"



MapManager::MapManager()
{
	level = 2;
	currentMap = new Map(LEVEL2_TXT, LEVEL2_PNG);
	currentMap->loadMap(LEVEL2_COUNT);
	this->LoadObject(LEVEL2_OBEJCT);
	currentQuadtree = new Quadtree();
	currentQuadtree->load(LEVEL2_QUADTREE);	
}
MapManager::MapManager(int _level)
{
	level = _level;
	switch (level)
	{
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
	default:
		break;
	}
}


void MapManager::reset() {
	delete currentMap;
	_listObject.clear();
	//delete _listObject;
}

void MapManager::Draw() {
	updateCurrentObject();
	currentMap->render(0,0);
	//draw all
	for (int i = 0; i < getCurrentObject().size(); i++) {
		_currentObjects[i]->Draw();
	}
}

void MapManager::updateCurrentObject() {
	_currentObjects.clear();
	vector<int> listID = this->currentQuadtree->Retrieve(Camera::getCurrentCamera()->getCenter());
	for each (int id in listID) {
		_currentObjects.push_back(this->_listObject[id]);
	}
}

vector<BaseObject*> MapManager::getCurrentObject() {
	for (int i = 0; i < _currentObjects.size(); i++) {
		if (_currentObjects[i]->is_remove){
			_currentObjects.erase(_currentObjects.begin() + i);
			i--;
		}
	}
	return _currentObjects;
}

vector<BaseObject*> MapManager::getListObject() {
	return _listObject;
}

void MapManager::setMap(int index) {
	this->level = index;
}	

void MapManager::NextMap() {
	if (level == 2) {
		level = 0;
	}
	this->level++;
	this->Update();
}

void MapManager::Update() {
	this->reset();
	switch (level)
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
		case TypeGame::Enemy_Medusahead:
			_listObject.push_back(new MedusaHead(id, x, y, bound));
			break;
		case TypeGame::Ground_Firecandle:
			_listObject.push_back(new FireCandle(id, x, y));
			break;
		default:
			break;
		}
	}
}

MapManager::~MapManager()
{
}

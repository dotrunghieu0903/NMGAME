#include "MapManager.h"



MapManager::MapManager()
{
	level = 2;
	currentMap = new Map(LEVEL2_TXT, LEVEL2_PNG);
	currentMap->loadMap(LEVEL2_COUNT);
	this->LoadObject(LEVEL2_OBEJCT);
	currentQuadtree = new Quadtree();
	currentQuadtree->load(LEVEL2_QUADTREE);	
	stage = 1;
}
MapManager::MapManager(int _level)
{
	stage = 1;
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
	BaseObject *temp = nullptr;
	for each (int id in listID) {
		for each(BaseObject* b in _listObject) {
			if (id == b->_id) {
				temp = b;
			}
		}
		if(temp != nullptr)
		_currentObjects.push_back(temp);
	}
}

vector<BaseObject*> MapManager::getCurrentObject() {
	for (int i = 0; i < _currentObjects.size(); i++) {
		if (_currentObjects[i]->is_remove && _currentObjects[i]->_type != TypeGame::Enemy_Medusahead){
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
	int id = 0, type = 0, x = 0, y = 0, width = 0, height = 0, var1, var2, var3, var4, item;
	for(int i = 0; i< countObject; i++)
	{
		myfile >> id;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		myfile >> var1;
		myfile >> var2;
		myfile >> var3;
		myfile >> var4;
		myfile >> item;
		RECT bound = { var1, var2,   var1 + var3,  var2 + var4 };
		if (id == 41) {
			int a = 0;
		}

		switch (type)
		{
		case TypeGame::Ground_Brick:
			_listObject.push_back(new Ground(id, var1, var2, var3, var4));
			break;
		case TypeGame::Enemy_Ghost:
			_listObject.push_back(new Ghost(id, x, y));
			break;
		case TypeGame::Enemy_Knight:
			_listObject.push_back(new BlackKnight(id, x, y, bound));
			break;
		case TypeGame::Enemy_Medusahead:
			_listObject.push_back(new MedusaHead(id, x, y, var1));
			break;
		case TypeGame::Ground_Firecandle:
			_listObject.push_back(new FireCandle(id, x, y, item));
			break;
		case TypeGame::Ground_Moving_Brick:
			_listObject.push_back(new Crossbar(id, x, y, bound));
			break;
		case TypeGame::Ground_Lockdoor:
			_listObject.push_back(new BlockDoor(id, x, y));
			break;
		case TypeGame::Ground_Trap:
			_listObject.push_back(new Trap(id, x, y, var1));
			break;
		case TypeGame::Enemy_DragonSkull:
			_listObject.push_back(new DragonSkull(id, x, y));
			break;
		case TypeGame::Boss_Medusa:
			_listObject.push_back(new MedusaQueen(id, x, y));
			break;
		case TypeGame::Enemy_Bat:
			_listObject.push_back(new Bat(id, x, y));
			break;
		default:
			break;
		}
	}
}

MapManager::~MapManager()
{
}

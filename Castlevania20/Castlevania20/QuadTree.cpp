#include "Quadtree.h"
Quadtree::Quadtree() {}
Quadtree::~Quadtree() {}
Quadtree* Quadtree::_currentQuadtree = 0;
void Quadtree::load() {
	loadObject();
	ifstream myfile(STAGE1_QUADTREE);
	vector<QNode*> list;
	while (!myfile.eof())
	{
		QNode* tamp = new QNode();
		myfile >> tamp->id;
		myfile >> tamp->bound->left;
		myfile >> tamp->bound->top;
		myfile >> tamp->bound->right;
		myfile >> tamp->bound->bottom;
		int count = 0;
		myfile >> count;
		for (int i = 0; i < count; i++) {
			int id;
			myfile >> id;
			tamp->listObject.push_back(_listObject[id]);
		}
		list.push_back(tamp);
	}
	for each (QNode * b in list) {
		if (b->id == 1) {
			_root = b;
			continue;
		}
		int rootId = b->id / 10;
		for each(QNode* tamp in list) {
			if (tamp->id == rootId) {
				switch (b->id % 10)
				{
				case 1:
					tamp->_nodeTL = b;
					break;
				case 2:
					tamp->_nodeTR = b;
					break;
				case 3:
					tamp->_nodeBL = b;
					break;
				case 4:
					tamp->_nodeBR = b;
					break;
				}
				break;
			}
		}
	}
}
void Quadtree::loadObject() {

	ifstream myfile(STAGE1_OBJECT);
	int count = 0;
	myfile >> count;
	_listObject = new BaseObject*[count];
	for (int i = 0; i < count; i++) {

		int x, y, width, height, type, id = 0;
		myfile >> id;
		myfile >> type;
		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		if (type>10 && type<23)
			_listObject[i] = getObject(type, x, y, width, height);



		myfile >> x;
		myfile >> y;
		myfile >> width;
		myfile >> height;
		if (type <= 10 || type >= 23) {
			_listObject[i] = getObject(type, x, y, width, height);
		}
		_listObject[i]->id = id;
	}
}
Quadtree* Quadtree::getCurrentQuadtree() {
	if (_currentQuadtree == 0) {
		_currentQuadtree = new Quadtree();
		_currentQuadtree->load();
	}
	return _currentQuadtree;
}
BaseObject* Quadtree::getObject(int type, int x, int y, int width, int height)
{
	BaseObject* tamp = 0;
	switch (type) {
	//case ObjectName::GROUND: tamp = new Ground(x, y, width, height); break;

	default: tamp = new BaseObject( x, y); break;
	}
	return tamp;
}



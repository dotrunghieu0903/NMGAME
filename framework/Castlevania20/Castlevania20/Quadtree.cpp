#include "Quadtree.h"
Quadtree::Quadtree() {}
Quadtree::~Quadtree() {}
void Quadtree::load(char* file) {
	ifstream myfile(file);
	while (!myfile.eof())
	{
		QuadNode* tamp = new QuadNode();
		myfile >> tamp->id;
		myfile >> tamp->bound->X;
		myfile >> tamp->bound->Y;
		myfile >> tamp->bound->Width;
		myfile >> tamp->bound->Height;
		int count = 0;
		myfile >> count;
		for (int i = 0; i < count; i++) {
			int id;
			myfile >> id;
			tamp->listIdObject.push_back(id);
		}
		//list.push_back(tamp);
		if (count > 0) {
			listNode.push_back(tamp);
		}
	}
	for each (QuadNode * b in listNode) {
		if (b->id == 1) {
			_root = b;
			continue;
		}
		int rootId = b->id / 10;
		for each(QuadNode* tamp in listNode) {
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


BaseObject* Quadtree::getObject(int type, int x, int y, int width, int height)
{
	BaseObject* tamp = 0;
	switch (type) {

	default: tamp = new BaseObject(1, x, y, width, height); break;
	}
	return tamp;
}


vector<int> Quadtree::Retrieve(CRectangle *rec) {
	vector<int> result;
	for (int i = 0; i < listNode.size(); i++) {
		//if rec colistion with listNode
		//->add item
		if (check(rec, listNode[i]->bound)) {
			for (int j = 0; j < listNode[i]->listIdObject.size(); j++) {
				result.push_back(listNode[i]->listIdObject[j]);
			}
		}
	}
	return result;

}

bool Quadtree::check(CRectangle *rec1, CRectangle *rec2) {
	if ((rec1->X + rec1->Width > rec2->X) && (rec1->X < rec2->X + rec2->Width) ||
		(rec1->Y + rec1->Height > rec2->Y) && (rec1->Y < rec2->Y + rec2->Height)) {
		return true;
	} 
	return false;
}
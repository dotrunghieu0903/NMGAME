#include"Quadnode.h"
QuadNode::QuadNode() {
	bound = new CRectangle();
}
QuadNode::~QuadNode() {}
bool QuadNode::IsContain() {

	return false;
}
void QuadNode::Retrieve(vector<int>& listGObject) {
	/*if (this->IsContain()) {
		for each(int i in listIdObject) {
			int count = 0;
			for each(BaseObject* object in listGObject) {
				if (object->_id == tamp->_id) count++;
			}
			if (count == 0)
				listGObject.push_back(tamp);
		}
	}*/
}

void QuadNode::CreateNode(QuadNode *parent, ifstream& file) {

	file >> parent->id;
	file >> parent->bound->X;
	file >> parent->bound->Y;
	file >> parent->bound->Width;
	file >> parent->bound->Height;

	int count = 0;
	file >> count;
	if (count == 0) {
		parent->_nodeTL = new QuadNode();
		parent->CreateNode(parent->_nodeTL, file);
		parent->_nodeTR = new QuadNode();
		parent->CreateNode(parent->_nodeTR, file);
		parent->_nodeBL = new QuadNode();
		parent->CreateNode(parent->_nodeBL, file);
		parent->_nodeBR = new QuadNode();
		parent->CreateNode(parent->_nodeBR, file);
	}
}
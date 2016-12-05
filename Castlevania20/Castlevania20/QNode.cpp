#include"QNode.h"
QNode::QNode() {
	bound = new RECT();
}
QNode::~QNode() {}
bool QNode::IsContain() {

	return !(Simon::getCurrentSimon()->_x + SIMON_WIDTH < bound->left ||
		Simon::getCurrentSimon()->_y - SIMON_HEIGHT < bound->top ||
		Simon::getCurrentSimon()->_x > bound->right ||
		Simon::getCurrentSimon()->_y > bound->bottom);
}
void QNode::Retrieve(vector<BaseObject*>& listGObject) {
	if (_nodeTL) {
		if (_nodeTL->IsContain())
			_nodeTL->Retrieve(listGObject);
		if (_nodeTR->IsContain())
			_nodeTR->Retrieve(listGObject);
		if (_nodeBL->IsContain())
			_nodeBL->Retrieve(listGObject);
		if (_nodeBR->IsContain())
			_nodeBR->Retrieve(listGObject);
	}
	if (this->IsContain()) {
		for each(BaseObject* tamp in listObject) {
			int count = 0;
			for each(BaseObject* object in listGObject) {
				if (object->id == tamp->id) count++;
			}
			if (count == 0)
				listGObject.push_back(tamp);
		}
	}
}
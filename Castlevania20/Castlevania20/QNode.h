#ifndef _QNODE_H
#define _QNODE_H

#include"Rect.h"
#include "BaseObject.h"
#include"Simon.h"
#include <vector>
#include "Rectangle.h"
using namespace std;
class QNode {
private:

public:
	QNode* _nodeTL;
	QNode* _nodeTR;
	QNode* _nodeBL;
	QNode* _nodeBR;

	vector<BaseObject*> listObject;
	int id;
	RECT* bound;
	bool IsContain();
	void Retrieve(vector<BaseObject*>& listGObject);
	QNode();
	~QNode();
};

#endif
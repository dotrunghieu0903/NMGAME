#include "BaseObject.h"
#include "CRectangle.h"
#include <iostream>
#include <fstream>
class QuadNode {
private:

public:
	QuadNode* _nodeTL;
	QuadNode* _nodeTR;
	QuadNode* _nodeBL;
	QuadNode* _nodeBR;

	vector<int> listIdObject;
	int id;
	CRectangle* bound;
	bool IsContain();
	void Retrieve(vector<int>& listGObject);
	void CreateNode(QuadNode *parent, ifstream& file);
	QuadNode();
	~QuadNode();
};
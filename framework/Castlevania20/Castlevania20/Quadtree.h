
#define QUADTREE_REF "quad.txt"
#define OBJECT_REF "object.txt"

#include "QuadNode.h"
#include <string>
class Quadtree {
private:
	BaseObject** _listObject;
	vector<QuadNode*> listNode;
public:
	Quadtree();
	~Quadtree();
	QuadNode* _root;
	void load(char* file);
	vector<int> Retrieve(CRectangle *rec);
	BaseObject* getObject(int type, int x, int y, int width, int height);
	bool check(CRectangle *rec1, CRectangle *rec2);
};
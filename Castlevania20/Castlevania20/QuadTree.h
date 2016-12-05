#ifndef _QUADTREE_H_
#define _QUADTREE_H_
#include "BaseObject.h"
#include "QNode.h"
//#include "Ground.h"
#include <fstream>
using namespace std;
class Quadtree {
private:
	BaseObject** _listObject;
	static Quadtree* _currentQuadtree;
public:
	Quadtree();
	~Quadtree();
	QNode* _root;
	static Quadtree* getCurrentQuadtree();
	void load();
	void loadObject();
	BaseObject* getObject(int type, int x, int y, int width, int height);
};
#endif
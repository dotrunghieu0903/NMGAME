#pragma once
#include "BaseObject.h"

enum TYPE_DOOR{
	GO_LEFT,GO_RIGHT
};
class BlockDoor :
	public BaseObject
{
private:
	bool opening = false;
	bool closing = false;
public:
	BlockDoor();
	BlockDoor(int id, int x, int y);
	TYPE_DOOR getType();
	void SetFrame(float deltatime);
	void Open();
	void Draw();
	~BlockDoor();
};


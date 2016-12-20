#pragma once
#include "BaseObject.h"


#define MEDUSAHEAD_SPRITE			L"resource\\sprite\\enemy\\6.png"
#define MEDUSAHEAD_WIDTH			32
#define MEDUSAHEAD_HEIGHT			32
#define MEDUSAHEAD_SPEED			0.19f

#define TYPE 6

class MedusaHead :
	public BaseObject
{
private:
	int count = 0;
	ENEMY_STAGE stage;
public:
	MedusaHead();
	MedusaHead(int id, int x, int y, RECT rect);
	void MoveUpdate(float deltatime);
	void UpdateEvent(float deltatime);
	void Draw();
	~MedusaHead();
};


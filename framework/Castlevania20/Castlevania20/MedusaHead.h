#pragma once
#include "BaseObject.h"


#define MEDUSAHEAD_SPRITE			L"resource\\sprite\\enemy\\6.png"
#define MEDUSAHEAD_WIDTH			32
#define MEDUSAHEAD_HEIGHT			32
#define MEDUSAHEAD_SPEED			0.16f

#define TYPE 6

class MedusaHead :
	public BaseObject
{
private:
	int count = 230;
	int timedie = 0;
	ENEMY_STAGE state;
	int p_x;
	int p_y;
	bool is_left;
	int lasttime = 0;
public:
	MedusaHead();
	MedusaHead(int id, int x, int y, bool is_left);
	void MoveUpdate(int simon_x,int simon_y,float deltatime);
	void Draw();
	void reborn(bool);
	~MedusaHead();
};


#ifndef __ITEM_H__
#define __ITEM_H__

#include <d3d9.h>
#include <d3dx9.h>
#include <stdlib.h>
#include <vector>
#include "BaseObject.h"

#define ITEM_PATH		L"resource\\sprite\\item\\misc.png"
#define ITEM_WIDTH		32
#define ITEM_HEIGHT		32

//#define ITEM_AXE			Item_axe
//#define ITEM_CROSS			Item_cross
//#define ITEM_KNIFE			Item_knife
//#define ITEM_HOLY_WATER		Item_holy_water
//#define ITEM_STOP_WATCH		Item_stop_watch
#define ITEM_MORNING_STAR	Item_morning_star
#define ITEM_DOUBLE_SHOT	Item_double_shot
#define ITEM_SMALL_HEART	Item_small_heart
#define ITEM_BIG_HEART		Item_big_heart
#define ITEM_MONEY_BAG		Item_money_bag
#define ITEM_ROAST			Item_roast
#define ITEM_ROSARY			Item_rosary
#define ITEM_SPIRIT_BALL	Item_spirit_ball
#define ITEM_NONE			Item_none

enum ITEM_STATE { ALIVE, DYING, DESTROYED };

using namespace std;
class ITEM : public BaseObject {
protected:
	int item_type;
	int last_time;
	DWORD appear_time = 0;
	int count;
	bool landed;

public:
	ITEM_STATE item_state;
	ITEM();
	~ITEM();
	ITEM(int Item_Type, int X, int Y);
	void Update(int deltatime);
	void UpdateEvent(int deltatime);
	void Draw();
	int GetItemType() { return item_type; }
	void ReturnCheckCollision(vector<BaseObject*> listobject, float dt);

	RECT GetAnimateRect(int _Index)
	{
		RECT srect;
		switch (_Index)
		{
		case 1:
			if (item_type == ITEM_SPIRIT_BALL)
				srect = { 258, 44, 286, 76 };
			break;
		default:
			if (item_type == ITEM_BIG_HEART) // 20
				srect = { 220, 174, 244, 194 };
			else if (item_type == ITEM_MONEY_BAG) //30
				srect = { 86, 168, 116, 198 };
			else if (item_type == Item_axe) //30
				srect = { 179, 0, 209, 30 };
			else if (item_type == Item_cross) //30
				srect = { 105, 0, 135, 30 };
			else if (item_type == Item_knife)//21
				srect = { 289, 4, 321, 25 };
			else if (item_type == Item_holy_water)//32
				srect = { 70, 80, 102, 112 };
			else if (item_type == Item_stop_watch)//30
				srect = { 114, 82, 144, 112 };
			else if (item_type == ITEM_MORNING_STAR)//32
				srect = { 148, 44, 180, 76 };
			else if (item_type == ITEM_DOUBLE_SHOT)//28
				srect = { 152, 84, 180, 112 };
			else if (item_type == ITEM_ROAST)//26
				srect = { 184, 48, 216, 74 };
			else if (item_type == ITEM_ROSARY)//34
				srect = { 214, 80, 246, 114 };
			else if (item_type == ITEM_SPIRIT_BALL)//32
				srect = { 222, 44, 250, 76 };
			else srect = { 200, 176, 216, 192 };
			break;
		}
		return srect;
	}
};

#endif
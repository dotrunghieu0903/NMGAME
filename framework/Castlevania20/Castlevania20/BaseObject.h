#ifndef __BASEOBJECT_H__
#define __BASEOBJECT_H__



#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"
#include "Box.h"
#include "SweptAABB.h"
using namespace std;
#define GRAVITY			0.2f

enum TypeGame {
	Boss_Bat = 0,
	Boss_Medusa = 1,
	Boss_Simon = 2,
	Enemy_Bat = 3,
	Enemy_Bonepilla = 4,
	Enemy_Ghost = 5,
	Enemy_Medusahead = 6,
	Enemy_Merman = 7,
	Enemy_Panther = 8,
	Enemy_Spearguard = 9,
	Enemy_Zombie = 10,
	Ground_Brick = 11,
	Ground_Fireandle = 12,
	Ground_Firetower = 13,
	Ground_Go_In_Castle = 14,
	Ground_Hidden = 15,
	Ground_Lockdoor = 16,
	Ground_Moving_Brick = 17,
	Ground_Next = 18,
	Ground_Opendoor = 19,
	Ground_Stair_Down = 20,
	Ground_Stair_Up = 21,
	Ground_Trap = 22,
	Item_axe = 23,
	Item_cross = 24,
	Item_knife = 25,
	Item_holy_water = 26,
	Item_stop_watch = 27,
	Item_morning_star = 28,
	Item_double_shot = 29,
	Item_small_heart = 30,
	Item_big_heart = 31,
	Item_money_bag = 32,
	Item_roast = 33,
	Item_rosary = 34,
	Item_spirit_ball = 35,
	Item_none = 36,


	Other_kill = 37
};

class BaseObject {
private:

Swept *sweptAB;

protected:

public:
	int _x;
	int _y;
	int _width;
	int _height;
	int _id;

	float _vx;
	float _vy;
	float _gravity;

	int _type;

	RECT _bound;

	Box _box;

	Sprite* _sptrite;

	BaseObject::BaseObject(int type, int x, int y, int width, int height);
	virtual void Update(float deltatime) {}
	virtual void Draw() {}
	virtual void ChangeState(int state) {}

	/*virtual void LoadResource();
	virtual void Update(int Delta);
	virtual void Render();
	virtual void Damaged(int damage, int x, int y);*/

	bool CheckCollision(BaseObject *object2);

	BaseObject();

	void UpdatePosition(int time);
	//void FixPositionCollid(G_OBJECT * o, int CollidPos);



	~BaseObject();
};

#endif
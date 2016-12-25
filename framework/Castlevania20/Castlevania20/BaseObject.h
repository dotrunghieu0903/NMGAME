#ifndef __BASEOBJECT_H__
#define __BASEOBJECT_H__



#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"
#include "SweptAABB.h"
#include <vector>
using namespace std;

#define COLLIDED_NONE	0
#define COLLIDED_LEFT	1
#define COLLIDED_RIGHT	2
#define COLLIDED_TOP	3
#define COLLIDED_BOT	4
#define COLLIDED_IN	4

#define GRAVITY			0.2f

#define FIRE_SPRITE L"resource\\sprite\\other\\0.png"

enum ENEMY_STAGE
{
	WAIT = 1, // đang chờ được load lên game
	LEFT = 2,// đang đi qua bên trái
	RIGHT = 3,//đang đi qua bên phải
	DAMAGED = 4, //dang bi dinh don
	DIE = 5,//đang chết (nhấp nháy)
	END = 6,//kết thúc, loại bỏ khỏi game
};


enum TypeGame {
	Boss_Medusa = 0,
	Boss_MummyMan = 1,
	Boss_Simon = 2,
	Enemy_Bat = 3,
	Enemy_DragonSkull = 4,
	Enemy_Ghost = 5,
	Enemy_Medusahead = 6,
	Enemy_Merman = 7,
	Enemy_Panther = 8,
	Enemy_Knight = 9,
	Enemy_Zombie = 10,
	Ground_Brick = 11,
	Ground_Firecandle = 12,
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
	Other_kill = 37, 
	Other_FireBall = 38,
	Other_Snake = 39,
	Other_Bandage = 40
};

class BaseObject {
private:

//Swept *sweptAB;

protected:

	int heath  = 100;
	float tickcount = 0;
	bool damaged = false;
	bool tamp = false;

public:
	int _x;
	int _y;
	int last_x;
	int last_y;
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
	BaseObject::BaseObject(int type, int x, int y, int width, int height, RECT rect);
	virtual void Update(float deltatime);
	virtual void Update(int simon_x, int simon_y, float deltatime);
	virtual void InputUpdate(float deltatime) {}
	virtual void SetFrame(float deltatime) {}
	virtual void MoveUpdate(float deltatime) {}
	virtual void MoveUpdate(int simon_x, int simon_y, float deltatime){}
	virtual void UpdateEvent(float deltatime) {}
	virtual void Draw() {}
	virtual void ChangeState(int state) {}

	int CheckCollision(BaseObject *object2,float deltatime);
	virtual Box getBox();
	virtual Box getBox(BaseObject *object2);
	virtual void ReturnCollisionTop(BaseObject *object) {}
	virtual void ReturnCollisionBot(BaseObject *object) {}
	virtual void ReturnCollisionLeft(BaseObject *object) {}
	virtual void ReturnCollisionRight(BaseObject *object) {}

	BaseObject();

	void UpdatePosition(int time);
	void Die();
	bool is_remove = false;

	virtual void Damaged(int, float dt);
	virtual bool stop(float time, float deltatime);

	~BaseObject();
};

#endif
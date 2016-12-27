#ifndef __SIMON_H__
#define __SIMON_H__


#include "BaseObject.h"
#include "Input.h"
#include "Stair.h"
#include "BlockDoor.h"
#include "Resources.h"
#include "DragonSkull.h"
#include "Item.h"


#define SIMON_SPRITE		L"resource\\sprite\\simon.png"
#define SIMON_WIDTH			60
#define SIMON_HEIGHT		66
#define SIMON_SPEED			0.2f

#define FACE_LEFT 0
#define FACE_RIGHT 1
#define SIMON_JUMP_SPEED	0.55f
#define SIMON_ANIMATE_RATE	7
#define SIMON_ATTACK_RATE	10
#define TYPE 2
//#define SIMON_JUMPMAX 64
#define SIMON_VX_STAIR 0.7f

enum MOVE_STATE { STAND, SIT, JUMP, MOVE, TAIR, DINHCHUONG, FALL };
enum ACTION_STATE { REST, ATTACK };

enum WEAPON {
	WEAPON1 = 0,
	WEAPON2 = 3,
	WEAPON3 = 6,
};

enum WEAPONNAME {
	Axe ,
	Boomerang ,
	Dagger ,
	FireBomb ,
	Watch ,
	FireBomb2 ,
	None ,
};
class Simon : public BaseObject {
private:
	int _Facing;
	static Simon* _simon;
	bool is_control;

	MOVE_STATE Move_State;
	ACTION_STATE Action_State;

	Sprite *weapon;
	WEAPON _index_weapon;
	
	Stair *stairOn;
	BaseObject *standOn = nullptr;
	bool onCrossBar = false;
	
	bool is_wounded = false;
	int tickcountW = GetTickCount();
	bool atkend = false;
public:
	int _currentStage;
	int _hpSimon;
	int heart_num;
	WEAPONNAME _currentWeapon;
	static Simon* getCurrentSimon();
	Simon();
	Simon(int x, int y);
	Box getBox(BaseObject *object2);
	Box getBoxWeapon();
	void InputUpdate(float deltatime);
	void Update(float delta);
	void ReturnCheckCollision(vector<BaseObject*> lisobject, float dt);
	bool CheckAttack(BaseObject* object2);
	void MoveUpdate(float);
	void Draw();
	void Jump();
	void Move();
	void Sit();
	void ReturnCollisionTop(BaseObject *object);
	void ReturnCollisionLeft(BaseObject *object);
	void ReturnCollisionRight(BaseObject *object);
	void ReturnCollisionBot(BaseObject *object);
	void UpdateState(int, MOVE_STATE);
	void goStage(int stage);
	bool staging = false;
	float tickcountat = 0.0f; //tickcount attack

	void SetFacing(int facing) { _Facing = facing; };
	void PickUpItem(ITEM * item);
	~Simon();
};

#endif
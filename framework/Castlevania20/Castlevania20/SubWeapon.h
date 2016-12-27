#ifndef _SUBWEAPON_H
#define _SUBWEAPON_H

#define SUBWEAPON_NONE			0
#define SUBWEAPON_AXE			1
#define SUBWEAPON_KNIFE			2
#define SUBWEAPON_HOLY_WATER	3
#define SUBWEAPON_STOP_WATCH	4
#define SUBWEAPON_CROSS			5

#include "BaseObject.h"
class SubWeapon: public BaseObject
{
protected:
	int _SubWeapon_Type;
	int _Damage;
	int _Heart_Cost;
public:
	void Update(int Delta);
	void Render();
	void Trigger(int SubWeapon_Type);
	void CheckHit(BaseObject * obj);

	int GetHeartCost() { return _Heart_Cost; }
	SubWeapon();
	~SubWeapon();
};

#endif // !1
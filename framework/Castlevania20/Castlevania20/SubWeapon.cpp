#include "SubWeapon.h"

SubWeapon::SubWeapon(): BaseObject()
{
	_SubWeapon_Type = SUBWEAPON_NONE;
	_Heart_Cost = 1;
	_Damage = 2;
	/*destroy_time = 0;
	trigger_time = 0;

	Live_State = DESTROYED;*/

}

SubWeapon::~SubWeapon()
{
}

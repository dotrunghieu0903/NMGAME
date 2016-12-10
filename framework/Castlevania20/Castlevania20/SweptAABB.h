#ifndef _SWEPT_H_
#define _SWEPT_H_
#include <cmath>
#include <algorithm>
#include <limits>
#include "Box.h"
class Swept {
	int box1;
	int box2;
public:
	// returns true if the boxes are colliding (velocities are not used)
	bool AABBCheck(Box b1, Box b2);

	// returns true if the boxes are colliding (velocities are not used)
	// moveX and moveY will return the movement the b1 must move to avoid the collision
	bool AABB(Box b1, Box b2, float& moveX, float& moveY);

	// returns a box the spans both a current box and the destination box
	Box GetSweptBroadphaseBox(Box b);

	// performs collision detection on moving box b1 and static box b2
	// returns the time that the collision occured (where 0 is the start of the movement and 1 is the destination)
	// getting the new position can be retrieved by box.x = box.x + box.vx * collisiontime
	// normalx and normaly return the normal of the collided surface (this can be used to do a response)
	float SweptAABB(Box b1, Box b2, float& normalx, float& normaly);

	
	Swept();
	~Swept();
};

#endif
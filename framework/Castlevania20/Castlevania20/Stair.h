#ifndef __STAIR_H__
#define __STAIR_H__

#include <d3d9.h>
#include <d3dx9.h>

#define STAIR_UP	  1
#define STAIR_DOWN	 -1

#include "BaseObject.h"

#define STAIR_STEP_SIZE	16

#define STAR1 3774
#define STAR2 3900

class Stair {
public:
	int _x, _y;
	int _Stair_Type;
	int _Lenght;
	int inStep;

	Stair(int X, int Y, int StairType, int Lenght);
	int GetStairType() { return _Stair_Type; }
	static Stair* getTair(int x, int y, bool is_up);
};

#endif
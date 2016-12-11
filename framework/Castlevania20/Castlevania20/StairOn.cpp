#include "StairOn.h"


StairOn::StairOn(int StairType, int X, int Y,  int Lenght) :
	BaseObject(Ground_Stair_Up, X, Y, Lenght * STAIR_STEP_SIZE, Lenght * STAIR_STEP_SIZE)
{
	_Stair_Type = StairType;
	_Lenght = Lenght;

	int x1, y1;
	int x2, y2;
	if (_Stair_Type == STAIR_UP)
	{
		_type = Ground_Stair_Up;
		x1 = _x - STAIR_STEP_SIZE;
		y1 = _y;
		x2 = _x + (Lenght - 1) * STAIR_STEP_SIZE;
		y2 = _y + (Lenght)* STAIR_STEP_SIZE;
	}
	else if (_Stair_Type == STAIR_DOWN)
	{
		_type = Ground_Stair_Down;
		x1 = _x - STAIR_STEP_SIZE;
		y1 = _y + (Lenght)* STAIR_STEP_SIZE;
		x2 = _x + (Lenght - 1)* STAIR_STEP_SIZE;
		y2 = _y;
	}

	_StairIn = new BaseObject(_type, x1, y1, STAIR_STEP_SIZE * 2, STAIR_STEP_SIZE * 2);
	_StairOut = new BaseObject(_type, x2, y2, STAIR_STEP_SIZE * 2, STAIR_STEP_SIZE * 2);
}

void StairOn::Render()
{

}
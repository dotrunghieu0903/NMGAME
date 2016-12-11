//#ifndef _STAIRON_H_
//#define _STAIRON_H_
//#include "BaseObject.h"
//#define TYPE 21
//#define STAIR_SPITE L"resource\\sprite\\ground\\ground.png"
//class StairOn : public BaseObject
//{
//public:
//	StairOn();
//	StairOn(int id, int x, int y, int width, int height);
//	void Draw();
//	~StairOn();
//};
//#endif // !1

#ifndef _STAIRON_H_
#define _STAIRON_H_

//#include <d3d9.h>
//#include <d3dx9.h>
#include "BaseObject.h"

#define STAIR_UP	  1
#define STAIR_DOWN	 -1

#define STAIR_STEP_SIZE	16

class StairOn : public BaseObject {
protected:
	int _Stair_Type;
	int _Lenght;
	BaseObject * _StairIn;
	BaseObject * _StairOut;

public:
	StairOn::StairOn(int X, int Y, int StairType, int Lenght);
	void Render();

	BaseObject * StairIn() { return _StairIn; }
	BaseObject * StairOut() { return _StairOut; }

	int GetStairType() { return _Stair_Type; }

	RECT GetStairRect(int _Stair_Type)
	{
		RECT srect;
		switch (_Stair_Type)
		{
		case Ground_Stair_Down:
			srect = { 2, 80, 18, 96 };
			break;
		default:
			srect = { 2, 96, 18, 112 };
			break;
		}
		return srect;
	}
};

#endif
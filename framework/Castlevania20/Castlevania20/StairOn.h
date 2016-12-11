#ifndef _STAIRON_H_
#define _STAIRON_H_
#include "BaseObject.h"
#define TYPE 21
#define STAIR_SPITE L"resource\\sprite\\ground\\ground.png"
class StairOn : public BaseObject
{
public:
	StairOn();
	StairOn(int id, int x, int y, int width, int height);
	void Draw();
	~StairOn();
};
#endif // !1

#ifndef _BAT_H_
#define _BAT_H_

#include "BaseObject.h"
#define BAT_SPRITE L"resource\sprite\bat.png"
#define TYPE TypeGame::Enemy_Bat
#define _batWIDTH	32
#define _batHEIGHT	32

enum BATSTATE
{
	isSleep = 1,
	isAwake = 2,
};

class Bat: public BaseObject
{
private: 
	Box _awakeBox;
	bool _isSleep;// đang trên tường
public:
	Bat();
	Bat(int id, int x,int y);
	void Moveupdate();
	void Update();
	~Bat();
};
#endif
#ifndef _BAT_H_
#define _BAT_H_

#include "BaseObject.h"
#include "Box.h"
#define BAT_SPRITE L"resource\\sprite\\bat.png"
#define TYPE TypeGame::Enemy_Bat
#define _batWIDTH	32
#define _batHEIGHT	32
#define HP 1
#define DAMAGE 2
#define BAT_SPEED	0.4f
//#define _SPEEDY 0.3f

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
	float _temp;
public:
	Bat();
	Bat(int id, int x,int y);
	void MoveUpdate(float deltaTime);
	void Update(float deltaTime);
	void Collistion(float deltaTime);
	void ChangeState(int state);
	void Draw();
	~Bat();
};
#endif
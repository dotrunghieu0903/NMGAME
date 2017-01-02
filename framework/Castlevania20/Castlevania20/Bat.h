#ifndef _BAT_H_
#define _BAT_H_

#include "BaseObject.h"
#include "Box.h"
#define BAT_SPRITE L"resource\\sprite\\enemy\\0.png"
#define TYPE TypeGame::Enemy_Bat
#define _batWIDTH	32
#define _batHEIGHT	32
#define HP 1
#define DAMAGE 2
#define BAT_SPEED	0.27f
class Bat: public BaseObject
{
private: 
	ENEMY_STAGE state;
	int _temp;
public:
	Bat();
	Bat(int id, int x,int y, RECT bound);
	void MoveUpdate(int simon_x, int simon_y,float deltaTime);
	void Draw();
	~Bat();
};
#endif
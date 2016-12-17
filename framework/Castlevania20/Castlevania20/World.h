#ifndef _WORLD_H_
#define _WORLD_H_

#include "mainDefine.h"
#include "Sprite.h"
#include "Simon.h"

#define WORLD_SPRITE L"resource\\images\\finish.png"

class World
{
protected:
	Sprite *background;
	Sprite *boss;
	Simon *simonTemp;
	bool start; // check time draw simon
	int _index;
	int bg_x;
public:
	bool isStop; // stop intro finish level
	void Update(float deltatime);
	void Draw();
	World();
	~World();
};

#endif
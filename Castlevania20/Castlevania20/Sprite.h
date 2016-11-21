#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Texture.h"
#include "Animation.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
private: 
	Animation* animationAction;
	Texture* myTexture;
	int col;
	int row;
	int total;
	float scale;
	float rotate;
};

#endif
#include "Sprite.h"

Sprite::Sprite()
{
	myTexture = 0;
	animationAction = 0;
	scale = 0.0f;
	rotate = 0.0f;
}
Sprite::Sprite(const Sprite &sprite)
{
	//myTexture = new Texture();
}
Sprite::~Sprite()
{
}

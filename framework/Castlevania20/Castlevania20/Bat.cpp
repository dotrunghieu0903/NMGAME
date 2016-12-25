#include "Bat.h"

Bat::Bat()
{
}

Bat::Bat(int id,int x,int y): BaseObject(TYPE,x,y,_batWIDTH,_batHEIGHT)
{
	this->_id = id;
	this->_sptrite = new Sprite(new Texture(BAT_SPRITE,1,1,1),50);
}

Bat::~Bat()
{
}

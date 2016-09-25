#ifndef Bat_H
#define Bat_H
#include "ObjectDirectX.h"
class Bat :
	public ObjectDirectX
{
public:

	Bat();

	Bat(LPDIRECT3DDEVICE9 device, LPCSTR path); //ke thua

	void render(LPD3DXSPRITE sprireHanlde); //override

	~Bat();
};

#endif
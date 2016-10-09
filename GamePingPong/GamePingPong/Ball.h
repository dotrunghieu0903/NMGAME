#ifndef Ball_H
#define Ball_H
#include "ObjectDirectX.h"
class Ball :
	public ObjectDirectX
{
public:

	Ball();

	Ball(LPDIRECT3DDEVICE9 device, LPCSTR path); //ke thua

	void render(LPD3DXSPRITE sprireHanlde); //override

	void setXY(int x, int y);

	~Ball();
};

#endif
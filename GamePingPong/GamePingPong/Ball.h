#pragma once
#include "ObjectDirectX.h"
class Ball :
	public ObjectDirectX
{
public:

	Ball();
	Ball::Ball(LPDIRECT3DDEVICE9 device, LPCSTR path);

	void init(float x, float y, float w, float h, float v);
	void render(LPD3DXSPRITE sprireHanlde);
	void move();

	~Ball();
};


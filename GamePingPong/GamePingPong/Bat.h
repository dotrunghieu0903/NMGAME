#pragma once
#include "ObjectDirectX.h"
class Bat :
	public ObjectDirectX
{
public:

	Bat();
	Bat::Bat(LPDIRECT3DDEVICE9 device, LPCSTR path);

	void init(float x, float y, float w, float h, float v);
	void render(LPD3DXSPRITE sprireHanlde);
	void move();

	~Bat();
};


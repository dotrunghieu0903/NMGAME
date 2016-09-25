#ifndef ObjectDirectX_H
#define ObjectDirectX_H
#include "d3d9.h"
#include "GTextureDx9.h"
#include "stdio.h"
#include "conio.h"
class ObjectDirectX
{
protected:
	float _width;
	float _height;
	float _velocX;
	float _velocY;
	GTextureDx9* _texture = new GTextureDx9();
	D3DXVECTOR2 position;
public:
	void init(float x, float y, float w, float h, float vX, float vY);
	virtual void render(LPD3DXSPRITE sprireHanlde);
	void move();


	ObjectDirectX();

	ObjectDirectX(LPDIRECT3DDEVICE9 device, LPCSTR path);

	float get_width();
	float get_height();

	float getX();
	float getY();
	void setY(float y);

	void setVeloc(float x,float y);

	float get_velocX();
	float get_velocY();

	virtual ~ObjectDirectX();
};
#endif


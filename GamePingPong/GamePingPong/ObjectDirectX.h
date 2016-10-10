#ifndef ObjectDirectX_H
#define ObjectDirectX_H
#include "d3d9.h"
#include "GTextureDx9.h"
#include "stdio.h"
#include "conio.h"
#include "Box.h"

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

	//swept aabb
	Box getBox();
	float normalx, normaly;
	float sweptAABB(Box b1, Box b2, float& normalx, float& normaly);
	bool checkCollisionWith(Box box2);
	float moveX, moveY;
	bool AABB(Box b1, Box b2, float& moveX, float& moveY);

	float getX();
	float getY();
	void setY(float y);

	void setVeloc(float x,float y);

	float get_velocX();
	float get_velocY();

	virtual ~ObjectDirectX();
};
#endif


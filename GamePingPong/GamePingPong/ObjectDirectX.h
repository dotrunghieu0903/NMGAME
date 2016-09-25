#include "d3d9.h"
#include "GTextureDx9.h"
#include "stdio.h"
#include "conio.h"
class ObjectDirectX
{
protected:
	float _width;
	float _height;
	float _veloc;
	GTextureDx9* _texture = new GTextureDx9();
	D3DXVECTOR2 position;
public:
	
	virtual void init(float x, float y, float w, float h, float v);
	virtual void render(LPD3DXSPRITE sprireHanlde);
	virtual void move();

	ObjectDirectX();

	ObjectDirectX(LPDIRECT3DDEVICE9 device, LPCSTR path);

	virtual ~ObjectDirectX();
};


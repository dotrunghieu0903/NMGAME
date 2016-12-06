#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "Windows.h"
#include "Input.h"
class Graphics
{
	static Graphics* _graphics;



public:

	LPDIRECT3D9			_Direct3D;
	LPDIRECT3DDEVICE9 	_Direct3DDevice;
	LPD3DXSPRITE _sprite;
	LPDIRECT3DSURFACE9 _backBuffer;


	static Graphics* getCurGraphics();

	bool initDirectX3D();
	bool initDirect3DDevice();

	void BeginGraphics();
	void EndGraphics();
	void PrintText(const char* str, int size, int x, int y, DWORD color);


	Graphics();
	~Graphics();
};
#endif
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <d3dx9.h>

#include "game.h"
#include "sprite.h"
#include "trace.h"
#include "Map.h"

class CCamera : public CGame
{
public:
	CCamera(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate);
	~CCamera();

	LPD3DXSPRITE _SpriteHandler;

	int camera_x;			
	int camera_y;

	float camera_vx;			
	float camera_vy;

	float camera_vx_last;	
	float camera_vy_last;
	DWORD last_time;		
	Map * map;
	CSprite * map2;

protected:
	LPDIRECT3DSURFACE9 _Background;

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

};
#endif
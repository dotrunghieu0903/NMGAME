#include "camera.h"
#include <time.h>
#include <d3dx9.h>
#include "utils.h"

#define CAMERA_SPEED 1.4f
#define GROUND_Y 61


#define BACKGROUND_FILE L"bg.jpg"

#define ANIMATE_RATE 30

CCamera::CCamera(HINSTANCE hInstance, LPWSTR Name, int Mode, int IsFullScreen, int FrameRate) :
	CGame(hInstance, Name, Mode, IsFullScreen, FrameRate)
{
}

CCamera::~CCamera()
{
}

void CCamera::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));

	// TO-DO: not a very good place to initial sprite handler
	D3DXCreateSprite(d3ddv, &_SpriteHandler);

	HRESULT res = D3DXCreateSprite(_d3ddv, &_SpriteHandler);

	
	map2 = new CSprite(_SpriteHandler, BACKGROUND_FILE, 1024, 762, 1, 1);
	map = new Map("stage1.txt", "stage1.png");

	map->loadMap(_SpriteHandler);
}


void CCamera::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{

	camera_x += camera_vx * t;
	camera_y += camera_vy * t;
	trace(L"camera: %d - %d", &camera_vx, &camera_vy);
	
	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		last_time = now;
	}

	_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	int vpx = camera_x - 400;
	int vpy = camera_y + 300;
	map2->Render(1024 / 2, 762 / 2, vpx, vpy);
	map->render(0 , 0 , vpx, vpy);
	

	_SpriteHandler->End();
}

void CCamera::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	if (IsKeyDown(DIK_RIGHT))
	{
		camera_vx = CAMERA_SPEED;
		camera_vx_last = camera_vx;
	}
	else
		if (IsKeyDown(DIK_LEFT))
		{
			camera_vx = -CAMERA_SPEED;
			camera_vx_last = camera_vx;
		}
		else
		{
			camera_vx = 0;
		}
	if (IsKeyDown(DIK_UP)) {
		camera_vy = CAMERA_SPEED;
		camera_vy_last = camera_vy;
	}
	else {
		if (IsKeyDown(DIK_DOWN))
		{
			camera_vy = -CAMERA_SPEED;
			camera_vy_last = camera_vy;
		}
		else
		{
			camera_vy = 0;
		}
	}

}
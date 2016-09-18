#pragma comment(lib, "Ws2_32.lib")
#ifndef __GAME_H__
#define __GAME_H__
#include "d3d9.h"
#include "GSurfaceDx9.h"
#include "GTextureDx9.h"
#define WIDTH 800
#define HEIGHT 600
class Game
{
private:
	int			m_Width;
	int			m_Height;
	bool		m_IsWindow; 
	HINSTANCE	m_HandleInstance;
	HWND		m_HandleWindow;
	float m_fps;
	char fps[10];
	LPDIRECT3D9	m_lpDirect3D;
	LPDIRECT3DDEVICE9 m_lpDirect3DDevice;
	LPD3DXSPRITE		m_lpSpriteDirect3DHandle;
	static LRESULT CALLBACK WndProceduce
		(HWND hWnd, 
		UINT  message, 
		WPARAM wParam, 
		LPARAM lParam);
	// Game Element
	GSurfaceDx9* m_surface;
	int xPosition;
	int yPosition;
	int widthImage;
	int heightImage;
	int xPosition1;
	int yPosition1;

	float velocX;
	float velocY;
	float offset;





	GTextureDx9* m_txtthanhdo;
	GTextureDx9* m_texture;
	float scale;
	bool isScaleUp;
	float rotate;
	bool isGoUp;
	float _HEIGHTMAX;

	//Toc do thanh do
	int speed;
	bool isRightOut;
	bool isLeftOut;
public:
	Game(int scr_Width, int scr_Height, bool isWindow);
	bool initHandleWindow();

	bool initDirectX3DEnviroment();
	bool initDirect3DDevice();
	bool initSpriteHandle();

	void GameInit();
	void GameRun();
	void GameExit();
};
#endif
#ifndef _GRAPHIC_H
#define _GRAPHIC_H

#include "d3d9.h"
#include "d3dx9.h"
#include "d3dx9tex.h"
#include "windows.h"
#include "string"

class __declspec(dllexport) Graphic
{
private:
	LPDIRECT3DDEVICE9		m_pD3dDevice;
	LPDIRECT3D9				m_pD3d;
	HWND					m_hwnd;
	HINSTANCE				m_hInstance;
	D3DPRESENT_PARAMETERS	m_PresentPara;
	int						m_ScreenWidth;
	int						m_ScreenHeight;
	bool					m_IsFullScreen;
	D3DFORMAT	FindDepthStencilFormat(ULONG AdapterOrdinal, D3DDISPLAYMODE Mode, D3DDEVTYPE DevType);
public:
	Graphic();
	Graphic(HWND hwnd, HINSTANCE hInstance, int _width, int _height, bool _isFull);
	~Graphic();
	bool Init();
	LPDIRECT3DDEVICE9	GetDevice();
	LPDIRECT3DSURFACE9	GetBackBuffer();
	HWND				GethWindow();
	void				BeginRender();
	void				EndRender();
	void				ClearScreen();
	LPD3DXSPRITE		m_pSpriteHandler;
	void				ResetSprite();

	void				ChangeViewMode(bool isFullScreen);
	bool				GetIsFullScreen() { return !m_PresentPara.Windowed; }
};


#endif _GRAPHIC_H

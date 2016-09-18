#ifndef __GSURFACEDX9_H__
#define __GSURFACEDX9_H__
#include "d3dx9.h"
class GSurfaceDx9 
{
private:
	LPDIRECT3DSURFACE9		m_lpSurface;
	LPDIRECT3DSURFACE9		m_lpBackBuffer;
public:
	GSurfaceDx9();
	GSurfaceDx9(const GSurfaceDx9& surface);
	~GSurfaceDx9();
	void LoadSurfaceFromFile(LPDIRECT3DDEVICE9 _lpDirectDevice, D3DCOLOR ColorKey, LPCSTR fileName);
	void RenderSurface(LPDIRECT3DDEVICE9 _lpDirectDevice, RECT* SourceRect, RECT* DesRect);
	void UnLoadSurface();
};

#endif
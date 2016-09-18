#include "GSurfaceDx9.h"

GSurfaceDx9::GSurfaceDx9()
{
	m_lpSurface = 0;
	m_lpBackBuffer = 0;
}

GSurfaceDx9::GSurfaceDx9(const GSurfaceDx9 & surface)
{
	m_lpSurface = LPDIRECT3DSURFACE9(surface.m_lpSurface);
	m_lpBackBuffer = LPDIRECT3DSURFACE9(surface.m_lpSurface);
}

GSurfaceDx9::~GSurfaceDx9()
{
}

void GSurfaceDx9::LoadSurfaceFromFile(LPDIRECT3DDEVICE9 _lpDirectDevice, D3DCOLOR ColorKey, LPCSTR fileName)
{
	D3DXIMAGE_INFO _infoImage;
	HRESULT hr;

	hr = D3DXGetImageInfoFromFile(fileName, &_infoImage);
	if (FAILED(hr))
	{
		return;
	}
	hr = _lpDirectDevice->CreateOffscreenPlainSurface(_infoImage.Width, 
													_infoImage.Height, 
													D3DFMT_A8R8G8B8,
													D3DPOOL_DEFAULT, 
													&m_lpSurface, 
													0);
	if (FAILED(hr))
	{
		return;
	}

	hr = D3DXLoadSurfaceFromFile(
		m_lpSurface,
		0,
		0,
		fileName,
		0,
		D3DX_DEFAULT,
		ColorKey,
		0);
	if (FAILED(hr))
	{
		return;
	}

	hr = _lpDirectDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &m_lpBackBuffer);
	if (FAILED(hr))
	{
		return;
	}
}

void GSurfaceDx9::RenderSurface(LPDIRECT3DDEVICE9 _lpDirectDevice, RECT * SourceRect, RECT * DesRect)
{
	_lpDirectDevice->StretchRect(
		m_lpSurface,
		SourceRect,
		m_lpBackBuffer,
		DesRect,
		D3DTEXF_NONE);
}

void GSurfaceDx9::UnLoadSurface()
{

}
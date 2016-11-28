#include "Graphics.h"

Graphic::Graphic()
{

};

Graphic::Graphic(HWND hwnd, HINSTANCE hInstance, int _width, int _height, bool _isFull)
{
	m_hwnd = hwnd;
	m_hInstance = hInstance;
	m_ScreenWidth = _width;
	m_ScreenHeight = _height;
	m_IsFullScreen = _isFull;
	m_pD3dDevice = NULL;
	m_pD3d = NULL;
}

Graphic::~Graphic()
{
	if (m_pD3dDevice != NULL)
	{
		m_pD3dDevice->Release();
		m_pD3dDevice = NULL;
	}
	if (m_pD3d != NULL)
	{
		m_pD3d->Release();
		m_pD3d = NULL;
	}
}

bool Graphic::Init()
{
	D3DPRESENT_PARAMETERS	pPresent;
	D3DCAPS9				caps;
	D3DDISPLAYMODE			currentMode;
	if (NULL == (m_pD3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return false;
	}
	ZeroMemory(&pPresent, sizeof(pPresent));
	m_pD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &currentMode);
	pPresent.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pPresent.Windowed = !m_IsFullScreen;
	pPresent.AutoDepthStencilFormat = FindDepthStencilFormat(D3DADAPTER_DEFAULT, currentMode, D3DDEVTYPE_HAL);
	pPresent.EnableAutoDepthStencil = true;
	pPresent.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	pPresent.BackBufferFormat = D3DFMT_X8R8G8B8;
	pPresent.BackBufferCount = 1;
	pPresent.BackBufferHeight = m_ScreenHeight;
	pPresent.BackBufferWidth = m_ScreenWidth;
	pPresent.hDeviceWindow = m_hwnd;

	unsigned long ulFlag = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	ZeroMemory(&caps, sizeof(D3DCAPS9));
	m_pD3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		ulFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;

	if (FAILED(m_pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hwnd, ulFlag, &pPresent, &m_pD3dDevice)))
	{

		// Check if Hardware T&L is available
		m_pD3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, &caps);
		if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
			ulFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;

		// Attempt to Create a REF Device
		if (FAILED(m_pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, m_hwnd, ulFlag, &pPresent, &m_pD3dDevice)))
		{
			return false;
		}
	}

	m_PresentPara = pPresent;

	D3DXCreateSprite(m_pD3dDevice, &m_pSpriteHandler);

	if (m_pSpriteHandler == NULL)
	{
		return false;
	}
	return true;
}

D3DFORMAT Graphic::FindDepthStencilFormat(ULONG AdapterOrdinal, D3DDISPLAYMODE Mode, D3DDEVTYPE DevType)
{
	// Check 32bit depth buffer available
	if (SUCCEEDED(m_pD3d->CheckDeviceFormat(AdapterOrdinal, DevType, Mode.Format, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D32)))
	{
		if (SUCCEEDED(m_pD3d->CheckDepthStencilMatch(AdapterOrdinal, DevType, Mode.Format, Mode.Format, D3DFMT_D32))) return D3DFMT_D32;
	}

	// Check 24bit depth buffer available
	if (SUCCEEDED(m_pD3d->CheckDeviceFormat(AdapterOrdinal, DevType, Mode.Format, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D24X8)))
	{
		if (SUCCEEDED(m_pD3d->CheckDepthStencilMatch(AdapterOrdinal, DevType, Mode.Format, Mode.Format, D3DFMT_D24X8))) return D3DFMT_D24X8;
	}

	// Check 24bit depth buffer available
	if (SUCCEEDED(m_pD3d->CheckDeviceFormat(AdapterOrdinal, DevType, Mode.Format, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, D3DFMT_D16)))
	{
		if (SUCCEEDED(m_pD3d->CheckDepthStencilMatch(AdapterOrdinal, DevType, Mode.Format, Mode.Format, D3DFMT_D16))) return D3DFMT_D16;
	}
	// No depth buffer supported

	return D3DFMT_UNKNOWN;
}

LPDIRECT3DSURFACE9 Graphic::GetBackBuffer()
{
	LPDIRECT3DSURFACE9	backbuffer;
	HRESULT hr;
	if (m_pD3dDevice == NULL)
		return NULL;
	hr = m_pD3dDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	if (FAILED(hr))
		return NULL;
	else
		return backbuffer;
}


void Graphic::BeginRender()
{
	if (m_pD3dDevice == NULL)
		return;
	m_pD3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	m_pD3dDevice->BeginScene();
}

void Graphic::EndRender()
{
	m_pD3dDevice->EndScene();
}

void Graphic::ClearScreen()
{
	//m_pD3dDevice->Clear(0,NULL,D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(200,0,0),1.0f,0);
}


LPDIRECT3DDEVICE9	Graphic::GetDevice()
{
	return m_pD3dDevice;
}

HWND Graphic::GethWindow()
{
	return m_hwnd;
}

void Graphic::ResetSprite()
{
	m_pSpriteHandler->Release();
	D3DXCreateSprite(m_pD3dDevice, &m_pSpriteHandler);
}

void Graphic::ChangeViewMode(bool isFullScreen)
{
	D3DPRESENT_PARAMETERS	pPresent;
	D3DCAPS9				caps;
	D3DDISPLAYMODE			currentMode;
	if (NULL == (m_pD3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
	}
	ZeroMemory(&pPresent, sizeof(pPresent));
	m_pD3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &currentMode);
	pPresent.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pPresent.Windowed = !isFullScreen;
	pPresent.AutoDepthStencilFormat = FindDepthStencilFormat(D3DADAPTER_DEFAULT, currentMode, D3DDEVTYPE_HAL);
	pPresent.EnableAutoDepthStencil = true;
	pPresent.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	pPresent.BackBufferFormat = D3DFMT_X8R8G8B8;
	pPresent.BackBufferCount = 1;
	pPresent.BackBufferHeight = m_ScreenHeight;
	pPresent.BackBufferWidth = m_ScreenWidth;

	unsigned long ulFlag = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	ZeroMemory(&caps, sizeof(D3DCAPS9));
	m_pD3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		ulFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;

	if (FAILED(m_pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hwnd, ulFlag, &pPresent, &m_pD3dDevice)))
	{

		// Check if Hardware T&L is available
		m_pD3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, &caps);
		if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
			ulFlag = D3DCREATE_HARDWARE_VERTEXPROCESSING;

		// Attempt to Create a REF Device
		if (FAILED(m_pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, m_hwnd, ulFlag, &pPresent, &m_pD3dDevice)))
		{
		}
	}

	m_PresentPara = pPresent;

	D3DXCreateSprite(m_pD3dDevice, &m_pSpriteHandler);
	HRESULT result = m_pD3dDevice->Reset(&m_PresentPara);
}
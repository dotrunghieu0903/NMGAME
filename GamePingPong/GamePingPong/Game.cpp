#include "Game.h"
#include "CGameTimeDx9.h"
#include "GInputDx9.h"
#include <iostream>
using namespace std;


Game::Game(int scr_Width, int scr_Height, bool isWindow){
	this->m_Width = scr_Width;
	this->m_Height = scr_Height;
	this->m_IsWindow = isWindow;
	this->m_HandleInstance = 0;
	this->m_HandleWindow = 0;
	this->m_lpDirect3D = 0;
	this->m_lpDirect3DDevice = 0;
	this->m_lpSpriteDirect3DHandle = 0;

	m_surface = new GSurfaceDx9();
	xPosition = 300;
	yPosition = 50;
	xPosition1 = 400;
	yPosition1 = 625;
	widthImage = 100;
	heightImage = 100;
	velocX = 500.0f;
	velocY = 500.0f;
	offset = 20.0f;


	m_texture = new GTextureDx9();
	m_txtthanhdo = new GTextureDx9();
	scale = 0;
	rotate = 0;
	isScaleUp = true;
	isGoUp = false;
	_HEIGHTMAX = 50;

	speed = 5;
	
}

bool Game::initHandleWindow()
{
	WNDCLASSEX WndcEx;
	ZeroMemory(&WndcEx, sizeof(WndcEx));
	WndcEx.cbSize = sizeof(WNDCLASSEX);
	WndcEx.hInstance = this->m_HandleInstance;
	WndcEx.lpfnWndProc = (WNDPROC) WndProceduce;
	WndcEx.lpszClassName = "Game";
	if (!RegisterClassEx(&WndcEx))
	{
		return false;
	}
	this->m_HandleWindow = CreateWindow(
		"Game", //  WndcEx.lpszClassName
		"GamePingPong", // TITLE cua cua so #define TITLE "GAMEPINGPONG"
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, // style cua cua so
		100, // toa do x khi cua so xuat hien
		100, // toa do y khi cua so xuat hien
		this->m_Width, // chieu rong cua so
		this->m_Height, // chieu cao cua so
		0, // handle window parent cua cua so hien tai
		0, // handle 
		this->m_HandleInstance, // Handle Instance c?a ?ng d?ng
		0); // giu nguyen theo default la 0
	if (!this->m_HandleWindow) // Kiem tra tao thanh cong.
	{
		return false;
	}
	ShowWindow(m_HandleWindow, SW_SHOW); // show cua so len man hinh
	UpdateWindow(m_HandleWindow); // Update cua so theo thoi gian
	return true;
}

bool Game::initDirectX3DEnviroment()
{
	this->m_lpDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_lpDirect3D)
	{
		return true;
	}
	return false;
}

bool Game::initDirect3DDevice()
{
	D3DPRESENT_PARAMETERS d3dpp; // khai bao bien
	ZeroMemory(&d3dpp, sizeof(d3dpp)); 
	d3dpp.BackBufferCount = 1; // So luong Back buffer
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN; 
	d3dpp.BackBufferHeight = HEIGHT; // chieu cao cua BackBuffer
	d3dpp.BackBufferWidth = WIDTH; // Chieu dai cua BackBuffer
	d3dpp.Windowed = true; 
	d3dpp.hDeviceWindow = this->m_HandleWindow; 
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD; // Phuong thuc Swap cua Buffer
	m_lpDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT, // Chon DEFAULT ADAPTER
		D3DDEVTYPE_HAL, // 
		m_HandleWindow, // Handle Window cua cua so
		D3DCREATE_HARDWARE_VERTEXPROCESSING, // Hard ware vertex processing
		&d3dpp,
		&m_lpDirect3DDevice); 
	if(FAILED(m_lpDirect3DDevice))
	{
		return false;
	}
	return true;
}

bool Game::initSpriteHandle() 
{
	D3DXCreateSprite(m_lpDirect3DDevice, &m_lpSpriteDirect3DHandle);
	HRESULT hr;
	hr = !FAILED(m_lpSpriteDirect3DHandle);
	if (!hr)
	{
		return false;
	}
	return true;
}

void Game::GameInit()
{
	initHandleWindow();
	initDirectX3DEnviroment();
	initDirect3DDevice();
	initSpriteHandle();

	//Input
	GInputDx9::getInstance()->InitializeInput();
	GInputDx9::getInstance()->InitializeKeyBoardDevice(m_HandleWindow);


	//m_surface->LoadSurfaceFromFile(m_lpDirect3DDevice, D3DCOLOR_ARGB(0, 0, 0, 0), "Capture.PNG");
	ball = new Ball(m_lpDirect3DDevice, "quabong.png");
	ball->init(100.0f, 100.0f, 65.0f, 65.0f, 1.0f);

	/*batLeft = new Bat(m_lpDirect3DDevice, "thanhdo.png");
	batRight = new Bat(m_lpDirect3DDevice, "thanhdo.png");
	
	batLeft->init(100.0f, 100.0f, 22.0f, 163.0f, 0.0f);
	batRight->init(300.0f, 100.0f, 22.0f, 163.0f, 0.0f);*/
	m_fps = 0;
	CGameTimeDx9::getInstance()->InitGameTime();
}
void Game::GameRun()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg)); // T?o m?t Mesage ?? l?ng nghe c�c s? ki?n c?a c?a s?
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) // L?y message v� truy?n v�o bi?n msg ?� khai b�o
		{
			if (msg.message == WM_QUIT) // Ki?m tra n?u msg y�u c?u QUIT ?ng d?ng th� ?ng d?ng s? tho�t
				break;
			TranslateMessage(&msg); // x? l� input v� chuy?n v�o msg
			DispatchMessage(&msg); // g?i message ??n h�m WndProceduce ?? x? l�
		}
		else
		{
			CGameTimeDx9::getInstance()->UpdateGameTime();
			GInputDx9::getInstance()->UpdateKeyBoard();

			m_fps += CGameTimeDx9::getInstance()->getElapsedGameTime().getMilliseconds();
			if (m_fps >= 1000 / 60.0) 
			{
				m_lpDirect3DDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(96, 100, 196), 1.0f, 0); // Clear c?a s? 1 l?n tr??c khi v? l�n
				if (m_lpDirect3DDevice->BeginScene())
				{		
					m_lpSpriteDirect3DHandle->Begin(D3DXSPRITE_ALPHABLEND);

					ball->render(m_lpSpriteDirect3DHandle);
					ball->move();
					
					m_lpSpriteDirect3DHandle->End();
					m_lpDirect3DDevice->EndScene();
				}
				m_lpDirect3DDevice->Present(0, 0, 0, 0); // Th? hi?n t?t c? nh?ng g� ?� v? l�n m�n h�nh
				m_fps = 0;
			}
			
		}
	}
}

void Game::GameExit()
{
	if (this->m_lpDirect3D) {
		this->m_lpDirect3D->Release();
		this->m_lpDirect3D = NULL;
	}
	if (this->m_lpDirect3DDevice) {
		this->m_lpDirect3DDevice->Release();
		this->m_lpDirect3DDevice = NULL;
	}
}

LRESULT CALLBACK Game::WndProceduce(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
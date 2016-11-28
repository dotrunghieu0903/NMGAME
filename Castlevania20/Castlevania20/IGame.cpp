#include "IGame.h"

IGame::IGame(HINSTANCE hInstance, int _mode, bool _Isfullscreen, int _frameRate)
{
	m_hInstance = hInstance;
	m_hWindow = NULL;
	m_Mode = _mode;
	SetScreenDimension();
	GL_windowMode = _Isfullscreen;
	GL_FPS = _frameRate;
	//m_Input = NULL;
}

IGame::~IGame()
{

}

void IGame::SetScreenDimension()
{
	switch (m_Mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		GL_scrWidth = 640;
		GL_scrHeight = 480;
		break;

	case GAME_SCREEN_RESOLUTION_800_600_24:
		GL_scrWidth = 800;
		GL_scrHeight = 600;
		break;

	case GAME_SCREEN_RESOLUTION_1024_768_24:
		GL_scrWidth = 1024;
		GL_scrHeight = 768;
		break;

	default:
		GL_scrWidth = 800;
		GL_scrHeight = 600;
		break;
	}
}

LRESULT CALLBACK IGame::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

bool IGame::InitWindow()
{
	// Register to windows
	WNDCLASS wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wndclass.hIcon = LoadIcon(NULL, IDC_ARROW);
	wndclass.hInstance = m_hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = GL_AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}
	DWORD Style;
	Style = GL_windowMode ? WS_EX_TOPMOST | WS_POPUP | WS_VISIBLE : WS_OVERLAPPEDWINDOW;
	if (GL_windowMode == true)
	{
		Style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	}
	else
	{
		Style = WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_DLGFRAME; //WS_OVERLAPPEDWINDOW;
	}
	m_hWindow = CreateWindow(GL_AppName,
		GL_AppName,
		Style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		GL_scrWidth,
		GL_scrHeight,
		NULL,
		NULL,
		m_hInstance,
		this
	);
	if (!m_hWindow)
	{
		MessageBox(0, "[FAILED]-Can not create window", 0, 0);
		return false;
	}

	ShowWindow(m_hWindow, SW_SHOW);
	UpdateWindow(m_hWindow);
	return true;
}

bool IGame::GameInit()
{
	if (!InitWindow())
		return false;
	//GL_graphic = new CGraphic(m_hWindow, m_hInstance, GL_scrWidth, GL_scrHeight, GL_windowMode);
	//GL_timer = new	CTimer();
	/*if (!GL_graphic->Init())
	return false;
	m_Input = new CInput();*/
	/*if (!m_Input->CreateInput())
	return false;
	if (!m_Input->InitKeyboard(m_hWindow))
	return false;
	if (!m_Input->InitMouse(m_hWindow))
	return false;*/
	Init();
	return true;
}

void IGame::GameRun()
{
	MSG	msg;
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Render();
			//GL_DeltaTime = GL_timer->Tick();
			//if (GL_DeltaTime>1.0f / (float)GL_FPS)
			//{
			//	GL_timer->FreshTime();
			//	m_Input->ProcessKey(m_hWindow);
			//	//m_Input->GetMouse();
			//	Update(GL_DeltaTime);
			//	Render();
			//	//char c[100];
			//	//sprintf(c,"GAME FPS= %f ,%d , %f",GL_timer->GetFrameRate(),GL_FPS,GL_DeltaTime);
			//	//SetWindowText( m_hWindow, c );
			//}
		}
	}
}

void IGame::GameEnd()
{
	Destroy();
	//GL_graphic->~CGraphic();
	//m_Input->~CInput();
	if (m_hWindow)
	{
		DestroyWindow(m_hWindow);
		m_hWindow = NULL;
	}
}

void IGame::Update(float dt)
{

}

void IGame::Render()
{

}

void IGame::Destroy()
{

}

void IGame::Init()
{

}
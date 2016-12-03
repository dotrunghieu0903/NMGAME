#include "IGame.h"

IGame::IGame(HINSTANCE hInstance, int _mode, bool _Isfullscreen, int _frameRate)
{
	m_hInstance = hInstance;
	m_hWindow = NULL;
	m_Mode = _mode;
	SetScreenDimension();
	GL_windowMode = _Isfullscreen;
	GL_FPS = _frameRate;
	m_Input = NULL;
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
	// Kiểm tra xem có thông điệp nào được gửi tới hàng đợi cửa ứng dụng không 
	switch (msg)				//lọc các thông điệp 
	{
	case WM_DESTROY:			//bắt thông điệp yêu cầu kết thúc ứng dụng 
		PostQuitMessage(0);		//gọi hàm xử lý 
		break;
	}
	// Thông điệp trả về cho quá trình
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

bool IGame::InitWindow()
{
	// Register to windows
	WNDCLASS wndclass;
	//wndclass.cbSize = sizeof(WNDCLASSEX);							// hàm sizeof() trả về kích thước của một đối tượng kiểu dữ liệu đầu vào – đơn vị tính là byte   
	//wndclass.hIconSm = 0;											// con trỏ tới dữ liệu biểu tượng cửa sổ ứng dụng 
	wndclass.cbClsExtra = 0;										// xác lập số byte cấp phát thêm cho Class   
	wndclass.cbWndExtra = 0;										// xác lập số byte cấp phát thêm cho mỗi instance của Class 
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);	// màu nền của cửa sổ   
	wndclass.hCursor = LoadCursor(NULL, IDI_APPLICATION);			// xác lập kiểu con trỏ chuột mặc định   
	wndclass.hIcon = LoadIcon(NULL, IDC_ARROW);						// loại biểu tượng chương trình   
	wndclass.hInstance = m_hInstance;								// con trỏ (handle) trỏ tới instance của ứng dụng   
	wndclass.lpfnWndProc = WndProc;									// xác lập tên hàm gọi lại callback procedure  
	wndclass.lpszClassName = GL_AppName;							// tên lớp đăng ký với hệ thống   
	wndclass.lpszMenuName = NULL;									// con trỏ trỏ tới object dữ liệu thực đơn ứng dụng   
	wndclass.style = CS_HREDRAW | CS_VREDRAW;						// xác lập kiểu lớp   

	if (!RegisterClass(&wndclass))
	{
		MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}
	DWORD Style;
	//Style = GL_windowMode ? WS_EX_TOPMOST | WS_POPUP | WS_VISIBLE : WS_OVERLAPPEDWINDOW;
	Style = GL_windowMode ? WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP : WS_VISIBLE | WS_SYSMENU | WS_MINIMIZEBOX | WS_DLGFRAME;
	m_hWindow = CreateWindow(
		GL_AppName,			// tên lớp sử dụng đã khai báo và đăng ký
		GL_AppName,			// tiêu đề của cửa sổ chương trình
		Style,				// loại cửa sổ chương trình
		CW_USEDEFAULT,		// toạ độ X của của sổ khi xuất hiện
		CW_USEDEFAULT,		// toạ độ Y của của sổ khi xuất hiện 
		GL_scrWidth,		// kích thước bề ngang của cửa sổ - đơn vị là pixel
		GL_scrHeight,		// kích thước chiều cao của cửa sổ 
		NULL,				// con trỏ trỏ tới đối tượng cha ;  NULL = đối tượng quản lý là desktop của Windows 
		NULL,				// con trỏ đối tượng menu của chương trình; NULL = không sử dụng   
		m_hInstance,		// con trỏ instance của ứng dụng 
		this				// giá trị được truyền cho cửa sổ 
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
	GL_graphic = new Graphic(m_hWindow, m_hInstance, GL_scrWidth, GL_scrHeight, GL_windowMode);
	//GL_timer = new	CTimer();
	if (!GL_graphic->Init())
	return false;
	//m_Input = new CInput();
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
	GL_graphic->~Graphic();
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
#pragma comment(lib, "Ws2_32.lib")
#ifndef __GINPUT_H__
#define __GINPUT_H__

/*
	Class dùng cho viec thao tac voi Input trong Game.
	Day là 1 class Singleton nên có the truy cap moi noi.
*/

#include <dinput.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "DefineMacro.h"

class GInputDx9 
{
//Management Input of Game
	bool					m_PressKey[256];
	char					m_currentBuffer[256];
	char					m_previousBuffer[256];
	GInputDx9();
	D3DXVECTOR2				m_cursorLocation;
	DIDEVICEOBJECTDATA		m_KeyEvents[1024];
	DIMOUSESTATE2			m_mouseState;
	DIMOUSESTATE2			m_previousMouseState;
	LPDIRECTINPUT8			m_lpDirectInput;
	LPDIRECTINPUTDEVICE8	m_lpKeyBoardDevice;
	LPDIRECTINPUTDEVICE8	m_lpMouseDevice;
	static GInputDx9*		s_Instance;
public:
	bool					IsKeyDown(int keyCode);
	bool					IsKeyPress(int keyCode);
	bool					IsKeyRelease(int keyCode);
	bool					IsKeyUp(int keyCode);
	
	bool					IsKeyLeftDownAndKeyRightDown();
	bool					IsKeyLeftDownAndKeyRightUp();
	bool					IsKeyLeftUpAndKeyRightDown();
	bool					IsKeyLeftUpAndKeyRightUp();
	bool					IsMouseLeftDown();
	bool					IsMouseLeftPress();
	bool					IsMouseRightDown();
	bool					IsMouseRightPress();

	bool					IsKeyUpUpAndKeyDownUp();
	bool					IsKeyUpDownAndKeyDownDown();
	bool					IsKeyUpDownAndKeyDownUp();
	bool					IsKeyUpUpAndKeyDownDown();

	D3DXVECTOR2				GetCursorLocation();
	static GInputDx9*		getInstance();
	void					InitializeInput();
	void					InitializeKeyBoardDevice(HWND handleWindow);
	void					InitializeMouseDevice(HWND handleWindow);
	void					Release();
	void					SetKeyDown(int keyCode);
	void					SetKeyUp(int keyCode);
	void					UpdateKeyBoard();
	void					UpdateMouse();
	~GInputDx9();
};

#endif
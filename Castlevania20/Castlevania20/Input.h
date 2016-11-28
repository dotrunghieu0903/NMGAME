#ifndef _INPUT_
#define _INPUT_
#include "Globals.h"
//Class dùng cho việc thao tác các input: mouse, keyboard... trong game
class Input
{
private:
	bool					m_PressKey[256];
	char					m_currentBuffer[256];
	char					m_previousBuffer[256];
	D3DXVECTOR2				m_cursorLocation;
	DIDEVICEOBJECTDATA		m_KeyEvents[1024];
	DIMOUSESTATE2			m_mouseState;
	DIMOUSESTATE2			m_previousMouseState;
	LPDIRECTINPUT8			m_lpDirectInput;
	LPDIRECTINPUTDEVICE8	m_lpKeyBoardDevice;
	LPDIRECTINPUTDEVICE8	m_lpMouseDevice;
	static Input*			m_Instance;
public:
	Input();
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

	static Input*		getInstance();
	D3DXVECTOR2				GetCursorLocation();
	void					InitializeInput();
	void					InitializeKeyBoardDevice(HWND handleWindow);
	void					InitializeMouseDevice(HWND handleWindow);
	void					Release();
	void					SetKeyDown(int keyCode);
	void					SetKeyUp(int keyCode);
	void					UpdateKeyBoard();
	void					UpdateMouse();
	~Input();
};

#endif // !_INPUT_
#ifndef _INPUT_H_
#define _INPUT_H_
//#include "Globals.h"

#include <dinput.h>
#include <d3d9.h>
#include <d3dx9.h>

class Input
{
private:
	IDirectInput8		*m_pInput;
	IDirectInputDevice8 *m_pKeyboardDevice;
	IDirectInputDevice8 *m_pMouseDevice;
	char				keys[256];
	int					keyPressState[256];
	DIMOUSESTATE2       m_MouseState;
public:
	Input();
	~Input();
	//KeyBoard
	bool CreateInput();
	bool InitKeyboard(HWND);
	void ProcessKey(HWND);
	bool IsKeyDown(int keycode);
	bool IsKeyUp(int keycode);
	bool IsKeyPress(int keycode);
	//Mouse
	bool InitMouse(HWND);
	void GetMouse();
	bool IsMouseDown(int button);
	long mouseDX();
	long mouseDY();
	long mouseDZ();
};
#endif
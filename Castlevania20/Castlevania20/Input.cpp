#include "Input.h"

Input::Input()
{
	m_pInput = NULL;
	m_pKeyboardDevice = NULL;
	m_pMouseDevice = NULL;
}

Input::~Input()
{
	//Release Keyboard
	m_pKeyboardDevice->Unacquire();
	m_pKeyboardDevice->Release();
	m_pKeyboardDevice = NULL;
	//Release Mouse
	m_pMouseDevice->Unacquire();
	m_pMouseDevice->Release();
	m_pMouseDevice = NULL;
	//Release Direct input object
	m_pInput->Release();
	m_pInput = NULL;
}

bool Input::CreateInput()
{
	HRESULT hresult;
	hresult = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&m_pInput,
		NULL);
	if (FAILED(hresult))
	{
		MessageBox(0, "Error on Create input object ", 0, 0);
		return false;
	}
	//init keyboard
	hresult = m_pInput->CreateDevice(GUID_SysKeyboard, &m_pKeyboardDevice, NULL);
	if (FAILED(hresult))
		return false;
	//init Mouse
	hresult = m_pInput->CreateDevice(GUID_SysMouse, &m_pMouseDevice, NULL);
	if (FAILED(hresult))
		return false;
	return true;
}

bool Input::InitMouse(HWND hwnd)
{
	HRESULT hResult;
	hResult = m_pMouseDevice->SetDataFormat(&c_dfDIMouse2);
	if (hResult != DI_OK)
		return false;
	hResult = m_pMouseDevice->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (hResult != DI_OK)
	{
		MessageBox(0, 0, 0, 0);
		return false;
	}
	hResult = m_pMouseDevice->Acquire();
	if (FAILED(hResult))
		return false;
	return true;
}

bool Input::InitKeyboard(HWND hwnd)
{
	HRESULT hresult;
	hresult = m_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hresult))
		return false;
	hresult = m_pKeyboardDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if (FAILED(hresult))
		return false;
	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 256; // Arbitary buffer size
	hresult = m_pKeyboardDevice->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (hresult != DI_OK) return false;
	hresult = m_pKeyboardDevice->Acquire();
	if (FAILED(hresult))
		return false;
	return true;
}

bool Input::IsKeyDown(int keycode)
{
	return (keys[keycode] & 0x80) > 0;
}

bool Input::IsKeyUp(int keycode)
{
	if (keys[keycode] & 0x80)
		return false;
	return true;
}

bool Input::IsKeyPress(int keycode)
{
	if (IsKeyUp(keycode))
	{
		keyPressState[keycode] = 1;
	}

	if (keyPressState[keycode] == 1)
	{
		if (IsKeyDown(keycode))
		{
			keyPressState[keycode] = 2;
		}
	}

	if (keyPressState[keycode] == 2)
	{
		keyPressState[keycode] = 0;
		return true;
	}

	return false;
}

void Input::ProcessKey(HWND hwnd)
{
	HRESULT hr = m_pKeyboardDevice->GetDeviceState(sizeof(keys), (LPVOID)&keys);
	if (FAILED(hr))
	{
		m_pKeyboardDevice->Acquire();
	}
	if (IsKeyDown(DIK_ESCAPE))
	{
		PostMessage(hwnd, WM_QUIT, 0, 0);
	}
}

void Input::GetMouse()
{
	HRESULT hr = m_pMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE2), (void**)&m_MouseState);
	if (FAILED(hr))
	{
		// Mouse lost, zero out mouse data structure.
		ZeroMemory(&m_MouseState, sizeof(m_MouseState));
		// Try to acquire for next time we poll.
		m_pMouseDevice->Acquire();
	}
}

bool Input::IsMouseDown(int button)
{
	return ((m_MouseState.rgbButtons[button] & 0x80) != 0);
}

long Input::mouseDX()
{
	return m_MouseState.lX;
}

long Input::mouseDY()
{
	return m_MouseState.lY;
}

long Input::mouseDZ()
{
	return m_MouseState.lZ;
}


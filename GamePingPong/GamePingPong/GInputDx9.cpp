#include "GInputDx9.h"

GInputDx9::GInputDx9() :
	m_lpDirectInput(0),
	m_lpKeyBoardDevice(0),
	m_lpMouseDevice(0)
{
	m_cursorLocation.x = 0;
	m_cursorLocation.y = 0;
}
GInputDx9* GInputDx9::s_Instance = 0;
GInputDx9* GInputDx9::getInstance()
{
	if (s_Instance == 0)
	{
		s_Instance = new GInputDx9();
	}
	return s_Instance;
}

void GInputDx9::InitializeInput()
{
	HRESULT result;

	result = DirectInput8Create(	GetModuleHandle(0),
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&m_lpDirectInput,
		0);

	if (result != D3D_OK)
	{
	}


	result = m_lpDirectInput->CreateDevice(GUID_SysKeyboard, &m_lpKeyBoardDevice, 0);

	if (result != D3D_OK)
	{
	}

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024; // Arbitary buffer size

	HRESULT hr = m_lpKeyBoardDevice->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	if (hr != DI_OK) return;


	result = m_lpDirectInput->CreateDevice(GUID_SysMouse, &m_lpMouseDevice, 0);

	if (result != D3D_OK)
	{
	}
	for (int i = 0; i < 256; i++)
	{
		m_PressKey[i] = false;
		m_currentBuffer[i] = 0;
		m_previousBuffer[i] = 0;
	}
}

void GInputDx9::InitializeKeyBoardDevice(HWND handleWindow)
{
	HRESULT result;
	result = m_lpKeyBoardDevice->SetDataFormat(&c_dfDIKeyboard);
	if (result != D3D_OK)
	{
	}

	result = m_lpKeyBoardDevice->SetCooperativeLevel(handleWindow, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (result != D3D_OK)
	{
	}

	result = m_lpKeyBoardDevice->Acquire();
	if (result != D3D_OK)
	{
	}
}

void GInputDx9::InitializeMouseDevice(HWND handleWindow)
{
	HRESULT result;

	ZeroMemory(&m_mouseState, sizeof(m_mouseState));

	result = m_lpMouseDevice->SetDataFormat(&c_dfDIMouse2);

	if (result != DI_OK)
	{
	}

	result = m_lpMouseDevice->SetCooperativeLevel(handleWindow, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	if (result != DI_OK)
	{
	}

	result = m_lpMouseDevice->Acquire();
	if (result != D3D_OK)
	{
	}
}

bool GInputDx9::IsMouseRightDown()
{
	return ((m_mouseState.rgbButtons[1] & 0x80) != 0);
}

bool GInputDx9::IsMouseLeftDown()
{
	return ((m_mouseState.rgbButtons[0] & 0x80) != 0);
}

bool GInputDx9::IsMouseRightPress()
{
	return (((m_previousMouseState.rgbButtons[1] & 0x80) == 0) && ((m_mouseState.rgbButtons[1] & 0x80) != 0));
}

bool GInputDx9::IsMouseLeftPress()
{
	return (((m_previousMouseState.rgbButtons[0] & 0x80) == 0) && ((m_mouseState.rgbButtons[0] & 0x80) != 0));
}

void GInputDx9::UpdateKeyBoard()
{
	memcpy(m_previousBuffer, m_currentBuffer, 256);
	m_lpKeyBoardDevice->Acquire(); // Acquire device
	m_lpKeyBoardDevice->GetDeviceState(sizeof(m_currentBuffer), (LPVOID)&m_currentBuffer);

	DWORD dwElements = 1024;
	HRESULT hr = m_lpKeyBoardDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), m_KeyEvents, &dwElements, 0);

	if (!FAILED(hr))
	{
		for (DWORD i = 0; i < dwElements; i++)
		{
			int KeyCode = m_KeyEvents[i].dwOfs;
			int KeyState = m_KeyEvents[i].dwData;
			if ((KeyState & 0x80) > 0)
				m_PressKey[KeyCode] = true;
			else
				m_PressKey[KeyCode] = false;
		}
	}
	else
	{
		for (int i = 0; i < 256; i++)
		{
			m_PressKey[i] = false;
		}
	}
}

bool GInputDx9::IsKeyDown(int keyCode)
{
	if (m_currentBuffer[keyCode] & 0x00000080)
	{
		return true;
	}
	return false;
}

bool GInputDx9::IsKeyUp(int keyCode)
{
	if (m_currentBuffer[keyCode] & 0x00000080)
	{
		return false;
	}
	return true;
}

void GInputDx9::SetKeyDown(int keyCode)
{
	m_currentBuffer[keyCode] |= 0x00000080;
}

void GInputDx9::SetKeyUp(int keyCode)
{
	m_currentBuffer[keyCode] &= 0x00000000;
}

bool GInputDx9::IsKeyLeftUpAndKeyRightDown()
{
	return IsKeyUp(DIK_LEFT) && IsKeyDown(DIK_RIGHT);
}

bool GInputDx9::IsKeyLeftDownAndKeyRightUp()
{
	return IsKeyDown(DIK_LEFT) && IsKeyUp(DIK_RIGHT);
}

bool GInputDx9::IsKeyLeftDownAndKeyRightDown()
{
	return IsKeyDown(DIK_LEFT) && IsKeyDown(DIK_RIGHT);
}

bool GInputDx9::IsKeyLeftUpAndKeyRightUp()
{
	return IsKeyUp(DIK_LEFT) && IsKeyUp(DIK_RIGHT);
}

bool GInputDx9::IsKeyUpUpAndKeyDownUp()
{
	return IsKeyUp(DIK_UP) && IsKeyUp(DIK_DOWN);
}

bool GInputDx9::IsKeyUpDownAndKeyDownDown()
{
	return IsKeyDown(DIK_UP) && IsKeyDown(DIK_DOWN);
}

bool GInputDx9::IsKeyUpDownAndKeyDownUp()
{
	return IsKeyDown(DIK_UP) && IsKeyUp(DIK_DOWN);
}

bool GInputDx9::IsKeyUpUpAndKeyDownDown()
{
	return IsKeyUp(DIK_UP) && IsKeyDown(DIK_DOWN);
}


bool GInputDx9::IsKeyPress(int keyCode)
{
	if (
		(m_currentBuffer[keyCode] & 0x00000080) &&
		!(m_previousBuffer[keyCode] & 0x00000080))
	{
		return true;
	}
	return false;
	//	return m_PressKey[keyCode];
}

bool GInputDx9::IsKeyRelease(int keyCode)
{
	if (
		!(m_currentBuffer[keyCode] & 0x00000080) &&
		(m_previousBuffer[keyCode] & 0x00000080))
	{
		return true;
	}
	return false;
	/*return !m_PressKey[keyCode];*/
}

void GInputDx9::UpdateMouse()
{
	memcpy(m_previousMouseState.rgbButtons, m_mouseState.rgbButtons, 8);
	ZeroMemory(&m_mouseState, sizeof(m_mouseState));
	HRESULT result = m_lpMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)&m_mouseState);

	m_cursorLocation.x += m_mouseState.lX;
	m_cursorLocation.y += m_mouseState.lY;

	if (FAILED(result))
	{
		ZeroMemory(&m_mouseState, sizeof(m_mouseState));
		m_lpMouseDevice->Acquire();
	}

}

D3DXVECTOR2 GInputDx9::GetCursorLocation()
{
	return D3DXVECTOR2((float)m_mouseState.lX, (float)m_mouseState.lY);
}

void GInputDx9::Release()
{
	SAFE_RELEASE(m_lpDirectInput);
	SAFE_RELEASE(m_lpKeyBoardDevice);
	SAFE_RELEASE(m_lpMouseDevice);
}

GInputDx9::~GInputDx9()
{
	Release();
}
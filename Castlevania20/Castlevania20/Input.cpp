#include "Input.h"

Input* Input::m_Instance = 0;

Input::Input() :m_lpDirectInput(0), m_lpKeyBoardDevice(0), m_lpMouseDevice(0) {
	m_cursorLocation.x = 0;
	m_cursorLocation.y = 0;
}

Input* Input::getInstance() {
	if (m_Instance = 0) {
		m_Instance = new Input();
	}
	return m_Instance;
}

bool Input::IsKeyUp(int keyCode) {
	if (m_currentBuffer[keyCode] & 0x00000080) {
		return false;
	}
	return true;
}

bool Input::IsKeyDown(int keyCode) {
	if (m_currentBuffer[keyCode] & 0x00000080) {
		return true;
	}
	return false;
}

bool Input::IsKeyPress(int keyCode) {
	if (!(m_previousBuffer[keyCode] & 0x00000080 ) && m_currentBuffer[keyCode] & 0x00000080) {
		return true;
	}
	return false;
}

bool Input::IsKeyRelease(int keyCode) {
	if (!(m_currentBuffer[keyCode] & 0x00000080) && m_previousBuffer[keyCode] & 0x00000080) {
		return true;
	}
	return false;
}

bool Input::IsKeyLeftUpAndKeyRightUp()
{
	return IsKeyUp(DIK_LEFT) && IsKeyUp(DIK_RIGHT);
}

bool Input::IsKeyLeftUpAndKeyRightDown()
{
	return IsKeyUp(DIK_LEFT) && IsKeyDown(DIK_RIGHT);
}

bool Input::IsKeyLeftDownAndKeyRightUp()
{
	return IsKeyDown(DIK_LEFT) && IsKeyUp(DIK_RIGHT);
}

bool Input::IsKeyLeftDownAndKeyRightDown() {
	return IsKeyDown(DIK_LEFT) && IsKeyDown(DIK_RIGHT);
}

bool Input::IsMouseLeftDown() {
	return ( (m_mouseState.rgbButtons[0] & 0x80) != 0 );
}

bool Input::IsMouseRightDown() {
	return ((m_mouseState.rgbButtons[1] & 0x80) != 0);
}

bool Input::IsMouseLeftPress() {
	return ( (m_previousMouseState.rgbButtons[0] & 0x80)==0 && (m_mouseState.rgbButtons[0] & 0x80) != 0 );
}

bool Input::IsMouseRightPress(){
	return ((m_previousMouseState.rgbButtons[1] & 0x80) == 0 && (m_mouseState.rgbButtons[1] & 0x80) != 0);
}

bool Input::IsKeyUpUpAndKeyUpDown() {
	return IsKeyUp(DIK_UP) && IsKeyUp(DIK_DOWN);
}

bool Input::IsKeyDownUpAndKeyDownDown() {
	return IsKeyDown(DIK_UP) && IsKeyDown(DIK_DOWN);
}

bool Input::IsKeyDownUpAndKeyUpDown() {
	return IsKeyDown(DIK_UP) && IsKeyUp(DIK_DOWN);
}

bool Input::IsKeyUpUpAndKeyDownDown() {
	return IsKeyUp(DIK_UP) && IsKeyDown(DIK_DOWN);
}

D3DXVECTOR2 Input::GetCursorLocation() {
	return D3DXVECTOR2( (float)m_mouseState.lX, (float)m_mouseState.lY );
}

void Input::InitializeInput() {
	HRESULT result;

	result = DirectInput8Create(GetModuleHandle(0), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_lpDirectInput,0);
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

void Input::InitializeKeyBoardDevice(HWND handleWindow) {
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

void Input::InitializeMouseDevice(HWND handleWindow) {

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
void Input::Release() {
	SAFE_RELEASE(m_lpDirectInput);
	SAFE_RELEASE(m_lpKeyBoardDevice);
	SAFE_RELEASE(m_lpMouseDevice);
}

void Input::SetKeyDown(int keyCode) {
	m_currentBuffer[keyCode] &= 0x00000080;
}

void Input::SetKeyUp(int keyCode) {
	m_currentBuffer[keyCode] &= 0x00000000;
}

void Input::UpdateKeyBoard() {
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
void Input::UpdateMouse(){
	memcpy(m_previousMouseState.rgbButtons, m_mouseState.rgbButtons, 8);//copy character(state of mouse)
	ZeroMemory(&m_mouseState, sizeof(m_mouseState));//give memory
	HRESULT result = m_lpMouseDevice->GetDeviceState(sizeof(DIMOUSESTATE2), (LPVOID)&m_mouseState);

	m_cursorLocation.x += m_mouseState.lX;
	m_cursorLocation.y += m_mouseState.lY;

	if (FAILED(result))
	{
		ZeroMemory(&m_mouseState, sizeof(m_mouseState));
		m_lpMouseDevice->Acquire();
	}

}

Input::~Input()
{
	Release();
}

#include "Input.h"


Input* Input::_keyboard = 0;

Input* Input::getCurrentInput() {
	if (_keyboard == 0)
		_keyboard = new Input();
	return _keyboard;
}

int Input::InputInput() {

	HRESULT hr = DirectInput8Create(GetModuleHandle(NULL)
		, DIRECTINPUT_VERSION
		, IID_IDirectInput8
		, (void**)&_input
		, NULL);
	_input->CreateDevice(GUID_SysKeyboard, &_inputDevice, NULL);

	HRESULT hr1 = _inputDevice->SetDataFormat(&c_dfDIKeyboard);
	HRESULT hr2 = _inputDevice->SetCooperativeLevel(Windows::getCurrentWindows()->_hWindows, DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = 1024;

	_inputDevice->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	_inputDevice->Acquire();

	for (int i = 0; i < 256; i++)
	{
		_keyStates[i] = 0x00;
	}

	if (FAILED(hr1))
	{
		MessageBox(0, L"Không tạo định dạng được dữ liệu", L"Lỗi", MB_ICONERROR);
		return 0;
	}

	return 1;
}



void Input::UpdateKeyboard()
{
	BYTE keys[256];
	_inputDevice->GetDeviceState(256, keys);
	for (int i = 0; i < 256; i++)
	{
		_keyStates[i] = keys[i];
	}
}
void Input::PollKeyboard()
{
	//_inputDevice->Poll();
	//if (FAILED(_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates)))
	//{
	//	//keyboard device lost, try to re-acquire
	//	_inputDevice->Acquire();
	//	_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates);
	//}
	//else
	//{
	//	_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates);
	//}
	_inputDevice->Poll();
	if (FAILED(_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates)))
	{
		_inputDevice->Acquire();
		_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates);
	}
	else
	{
		_inputDevice->GetDeviceState(sizeof(_keyStates), (LPVOID)&_keyStates);
	}

}

bool Input::IsKeyDown(BYTE keyCode)
{
	return (_keyStates[keyCode] & 0x80) > 0;
}

bool Input::IsKeyUp(BYTE keyCode)
{
	return !((_keyStates[keyCode] & 0x80) > 0);
}

bool Input::keyLeft()
{
	return IsKeyDown(DIK_LEFT);
}

bool Input::keyRight()
{
	return IsKeyDown(DIK_RIGHT);
}

bool Input::keyUp()
{
	return IsKeyDown(DIK_UP);
}

bool Input::keyDown()
{
	return IsKeyDown(DIK_DOWN);
}

bool Input::keySpace()
{
	return IsKeyDown(DIK_SPACE);
}

bool Input::keyS()
{
	return IsKeyDown(DIK_S);
}

bool Input::keyW()
{
	return IsKeyDown(DIK_W);
}

bool Input::keyX()
{
	return IsKeyDown(DIK_X);
}

bool Input::keyC()
{
	return IsKeyDown(DIK_C);
}

Input::Input(void)
{
}


Input::~Input(void)
{
}

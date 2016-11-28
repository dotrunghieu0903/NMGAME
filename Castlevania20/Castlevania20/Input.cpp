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

bool Input::IsKeyUp(int keyCode) {
	if (m_currentBuffer[keyCode] & 0x00000080) {
		return false;
	}
	return true;
}
Input::~Input()
{
}

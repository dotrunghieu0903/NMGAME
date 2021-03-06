#ifndef  _WINDOWSCONFIG_H_
#define _WINDOWSCONFIG_H_
#pragma once

#include "mainDefine.h"

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>

#include"Windows.h"


#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

class GameConfig {
public:
	GameConfig();
	//write string to a tracing file
	static void GLTrace(char* format, ...);

	//show a message box
	static void GLMessage(LPCWSTR text);

	//show string to the caption of window
	static void GLTitle(LPCWSTR text);
	~GameConfig();
};

#endif
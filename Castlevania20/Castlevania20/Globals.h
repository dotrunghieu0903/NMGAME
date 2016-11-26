#ifndef _GLOBAL_H_
#define _GLOBAL_H_


#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <dinput.h>
#include <d3d9.h>
#include <d3dx9.h>

#define GAME_SCREEN_RESOLUTION_640_480_24   1000
#define GAME_SCREEN_RESOLUTION_800_600_24   1001
#define GAME_SCREEN_RESOLUTION_1024_768_24  1002


extern int		GL_scrWidth;
extern int		GL_scrHeight;
extern int		GL_mode;
extern bool		GL_windowMode;
extern int		GL_frameRate;
extern TCHAR	GL_AppName[];
extern float	GL_DeltaTime;
extern int		GL_FPS;


#endif _GLOBAL_H_
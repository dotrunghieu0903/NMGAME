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

#include "Timer.h"
#include "Graphics.h"
#include "Input.h"
#include "Define.h"

enum SpriteEffect
{
	None = 0,
	Horizontally = 1,
	Vertical = 2,
};
enum ObjectName {
	NONE = 0,
	SIMON =1,
};
enum StateSimon
{
	STANDING = 1,
	JOGGING = 2,
	SITTING = 3,
	JUMPING = 4,
	FALLING = 5,
};
enum SoundName
{
	HIT,
	//...
};
extern Timer *GL_timer;
extern Graphic *GL_graphic;

extern TCHAR	GL_AppName[];	// App title
extern int		GL_scrWidth;	// Screen Width (px)
extern int		GL_scrHeight;	// Screen Height (px)
extern int		GL_mode;
extern int		GL_frameRate;
extern int		GL_FPS;
extern float	GL_DeltaTime;
extern bool		GL_windowMode;

//
//GLOBAL FUNCTION
//

//write string to a log file
void GLLogger(char* format, ...);

//show a message box
void GLMessage(char* text);

//show string to the caption of window
void GLTitle(char* text);


#endif _GLOBAL_H_
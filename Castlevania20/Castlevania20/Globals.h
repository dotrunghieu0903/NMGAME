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
#include "Define.h"

#define SAFE_DELETE(p)			if(p){ delete (p);		(p) = 0;}

#define SAFE_DELETE_ARRAY(p)	if(p){ delete[] (p);	(p) = 0;}

#define SAFE_RELEASE(p)			if(p){ (p)->Release();	(p) = 0;}

enum CSprite
{
	None = 0,
	Horizontally = 1,
	Vertically = 2,
};

enum ObjectName {
	NONE = 0,
	SIMON =1,
};
enum SoundName
{
	BACKMUSIC_NAME,
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


#endif _GLOBAL_H_
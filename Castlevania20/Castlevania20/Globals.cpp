#include "Globals.h"

Timer *GL_timer = NULL;
Graphic *GL_graphic = NULL;

TCHAR	GL_AppName[] = "CASTLEVANIA 20";
int		GL_scrWidth = 256;
int		GL_scrHeight = 244;
float	GL_DeltaTime = 0;
int		GL_FPS = 0;
bool	GL_windowMode = false;
int		GL_mode;
int		GL_frameRate;


void GLLogger(char* format, ...)
{
	char *_logFile = "C:\\db\\Castlevania.log";
	int _logNum = 1;

	if (!_logNum) return;

	FILE *f = stderr;
	if (_logFile != NULL)
	{
		if (fopen_s(&f, _logFile, "a") != 0)
		{
			fprintf(stderr, "WARNING: Failed to open trace file '%s' for writing!\n", _logFile);
			return;
		}
	}
	va_list ap;
	va_start(ap, format);
	fprintf(f, format, ap);
	va_end(ap);
	fprintf(f, "\n");
	if (_logFile != NULL) fclose(f);
}

void GLMessage(char* text)
{
	MessageBox(GL_graphic->GethWindow(), text, "Castlevania Voice", MB_OK);
}

void GLTitle(char* text) {
	SetWindowText(GL_graphic->GethWindow(), text);
}

#include <windows.h>
#include "camera.h"
#include "Map.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CCamera g(hInstance, L"Camera - My world", GAME_SCREEN_RESOLUTION_800_600_24, 0, 60);

	g.Init();
	g.Run();
	return 0;
}



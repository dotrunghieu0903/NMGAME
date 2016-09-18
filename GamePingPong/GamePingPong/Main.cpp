#include"d3d9.h"
#include <stdio.h>
#include "Game.h"

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstace,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{
	Game mygame(WIDTH, HEIGHT, false);
	mygame.GameInit();
	mygame.GameRun();
	return 0;
}
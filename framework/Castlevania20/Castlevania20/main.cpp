#include "Game.h"
#include "Input.h"
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstace,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{

	Game* myGame = new Game(SCREEN_WIDTH, SCREEN_HEIGHT);

	myGame->GameInit();
	myGame->Run();

	return 0;
}
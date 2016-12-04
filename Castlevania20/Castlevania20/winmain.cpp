#include <Windows.h>

#include "GamePlay.h"
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{

	GamePlay* game = new GamePlay(hInstance, GAME_SCREEN_RESOLUTION_800_600_24, false, 60);

	if (!game->GameInit())
	{
		MessageBox(0, "Failed init", 0, 0);
		game->GameEnd();
		return 0;
	}
	//game->GameInit();
	game->GameRun();

	game->GameEnd();

	return 0;
}

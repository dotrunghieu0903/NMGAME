#ifndef	_IGame_H
#define _IGame_H
#include "Globals.h"
//#include "CInput.h"

class IGame
{
public:
	IGame(void) {};
	IGame(HINSTANCE hInstance, int _mode, bool _Isfullscreen, int _frameRate);
	~IGame();
	static	LRESULT CALLBACK		WndProc(HWND, UINT, WPARAM, LPARAM);
	bool	GameInit();
	void	GameRun();
	void	GameEnd();

	virtual void	Init();
	virtual void	Render();
	virtual void	Update(float dt);
	virtual void	Destroy();
	//CInput			*m_Input;
protected:
	HWND		m_hWindow;
	HINSTANCE	m_hInstance;
	int			m_Mode; //window mode
	bool			InitWindow();
	void			SetScreenDimension();
};

#endif
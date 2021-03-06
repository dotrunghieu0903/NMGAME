#ifndef  _INPUT_H_
#define _INPUT_H_
#include <dinput.h>
#include "Graphics.h"


class Input
{
	static Input* _keyboard;
	LPDIRECTINPUT8 _input;
	LPDIRECTINPUTDEVICE8 _inputDevice;
	BYTE  _keyStates[256];
public:

	static Input* getCurrentInput();
	int InputInput();
	void UpdateKeyboard();
	void PollKeyboard();
	bool IsKeyDown(BYTE keyCode);
	bool IsKeyUp(BYTE keyCode);


	bool keyLeft();
	bool keyRight();
	bool keyUp();
	bool keyDown();
	bool keySpace();

	bool keyS();
	bool keyW();
	bool keyX();
	bool keyC();

	Input(void);
	~Input(void);
};


#endif //  _INPPUT_H_
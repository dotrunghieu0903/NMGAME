#ifndef _FONT_H_
#define _FONT_H_

#include "d3d9.h"
#include "d3dx9.h"
#include <iostream>
#include <Windows.h>
#include "Graphics.h"
#include <string>

class Font
{
public:
	ID3DXFont* _font;
	void DrawString(std::string str,RECT* rect);
	void DrawNumber(int num,RECT* rect);
	Font();
	~Font();
};

#endif // !_FONT_H
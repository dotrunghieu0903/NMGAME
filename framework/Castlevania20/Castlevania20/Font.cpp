#include "Font.h"

Font::Font(){
	_font = NULL;
	D3DXCreateFont(Graphics::getCurGraphics()->_Direct3DDevice,20,0,FW_BOLD,1,FALSE,DEFAULT_CHARSET,OUT_DEFAULT_PRECIS,ANTIALIASED_QUALITY,FF_DONTCARE,L"Lucida Console",&_font);
}

void Font::DrawString(std::string _str,RECT* _rect) {
	_font->DrawTextA(Graphics::getCurGraphics()->_sprite, _str.c_str(), -1, _rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
}

void Font::DrawNumber(int _num, RECT* _rect) {
	std::string _tempStr;
	_tempStr = std::to_string(_num);
	_font->DrawTextA(Graphics::getCurGraphics()->_sprite, _tempStr.c_str(), -1, _rect, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
}

Font::~Font()
{
}

#include "Bat.h"
Bat::Bat()
{}

Bat::Bat(LPDIRECT3DDEVICE9 device, LPCSTR path)
{
	_texture->LoadTextureFromFile(
		device,
		path,
		D3DCOLOR_ARGB(100, 255, 255, 255));
}

void Bat::init(float x, float y, float w, float h, float v)
{
	_width = w;
	_height = h;
	_veloc = v;
	position.x = x;
	position.y = y;
}

void Bat::render(LPD3DXSPRITE sprireHanlde) {

}

void Bat::move() {

}

Bat::~Bat() {

}
#include "ObjectDirectX.h"
ObjectDirectX::ObjectDirectX()
{}

ObjectDirectX::ObjectDirectX(LPDIRECT3DDEVICE9 device, LPCSTR path)
{
	_texture->LoadTextureFromFile(
		device,
		path,
		D3DCOLOR_ARGB(100, 255, 255, 255));
}

void ObjectDirectX::init(float x, float y, float w, float h, float v)
{
	_width = w;
	_height = h;
	_veloc = v;
	position.x = x;
	position.y = y;
}

void ObjectDirectX::render(LPD3DXSPRITE sprireHanlde) {
	
}

void ObjectDirectX::move() {
	position.x += _veloc;
	position.y += _veloc;
}

ObjectDirectX::~ObjectDirectX() {

}
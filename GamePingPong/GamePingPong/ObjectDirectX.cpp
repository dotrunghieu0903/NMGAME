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

void ObjectDirectX::init(float x, float y, float w, float h, float vX, float vY)
{
	_width = w;
	_height = h;
	_velocX = vX;
	_velocY = vY;
	position.x = x;
	position.y = y;
}

void ObjectDirectX::render(LPD3DXSPRITE sprireHanlde) {
	
}

float ObjectDirectX::get_width() {
	return _width;
}

float ObjectDirectX::get_height() {
	return _height;
}

float ObjectDirectX::getX() {
	return position.x;
}

float ObjectDirectX::getY() {
	return position.y;
}

void ObjectDirectX::setY(float y) {
	position.y = y;
}

void ObjectDirectX::move() {
	position.x += _velocX;
	position.y += _velocY;
}

void ObjectDirectX::setVeloc(float x, float y)
{
	_velocX = x;
	_velocY = y;
}

float ObjectDirectX::get_velocX() 
{
	return _velocX;
}

float ObjectDirectX::get_velocY()
{
	return _velocY;
}


ObjectDirectX::~ObjectDirectX() {

}
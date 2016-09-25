#include "Ball.h"
Ball::Ball()
{}

Ball::Ball(LPDIRECT3DDEVICE9 device, LPCSTR path)
{
	_texture->LoadTextureFromFile(
		device,
		path,
		D3DCOLOR_ARGB(100, 255, 255, 255));
}

void Ball::init(float x, float y, float w, float h, float v)
{
	_width = w;
	_height = h;
	_veloc = v;
	position.x = x;
	position.y = y;
}

void Ball::render(LPD3DXSPRITE sprireHanlde) {

}

void Ball::move() {

}

Ball::~Ball() {

}
#include "Ball.h"

Ball::Ball()
{

}

Ball::Ball(LPDIRECT3DDEVICE9 device, LPCSTR path) : ObjectDirectX(device, path) {

}

void Ball:: render(LPD3DXSPRITE sprireHanlde) {
	RECT rec;
	rec.left = 0;
	rec.right = 65;
	rec.top = 0;
	rec.bottom = 65;
	_texture->RenderTexture(sprireHanlde, position, D3DXVECTOR2(1.0f, 1.0f), 0.0f, &rec, NULL, D3DCOLOR_ARGB(100, 255, 255, 255));
}

Ball::~Ball()  {}
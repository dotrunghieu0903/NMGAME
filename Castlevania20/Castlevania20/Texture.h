#ifndef _TEXTTURE_H_
#define _TEXTTURE_H_

#include "Globals.h"
class Texture
{
public:
	Texture();
	~Texture();
	int width;
	int height;
	void LoadTextureFromFile(LPDIRECT3DDEVICE9 lpDirectdevice,LPCSTR fileName,D3DXCOLOR ColorKey = 0xffffffff);
	void Render(LPD3DXSPRITE spriteHandle, D3DXVECTOR2 position, D3DXVECTOR2 scale, float rotate, RECT *srcRect, float deep = 0.0f, D3DCOLOR color = 0xffffffff);
private:
	LPDIRECT3DTEXTURE9		lpDirect3DTexture;
};

#endif
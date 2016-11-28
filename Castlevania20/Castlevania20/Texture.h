#ifndef _TEXTTURE_H_
#define _TEXTTURE_H_
#include "Globals.h"

class Texture
{
private:
	LPDIRECT3DTEXTURE9		m_lpDirect3DTexture;
public:
	int							m_Width;
	int							m_Height;
	Texture();
	void LoadTextureFromFile(LPDIRECT3DDEVICE9 _lpDirectdevice, LPCSTR fileName, D3DXCOLOR ColorKey = 0xffffffff);
	void RenderTexture(LPD3DXSPRITE _lpDSpriteHandle, D3DXVECTOR2 position, D3DXVECTOR2 scale, float angle, RECT *srcRect, float deep, D3DCOLOR color = 0xffffffff);
	~Texture();
};
#endif
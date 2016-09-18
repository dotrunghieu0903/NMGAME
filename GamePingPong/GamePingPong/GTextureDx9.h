#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <d3d9.h>
#include <d3dx9.h>

class GTextureDx9
{
private:
	LPDIRECT3DTEXTURE9		m_lpDirect3DTexture;
public:
	int							m_Width;

	int							m_Height;
	GTextureDx9();
	~GTextureDx9();
	void LoadTextureFromFile(LPDIRECT3DDEVICE9 _lpDirectdevice, 
								LPCSTR fileName, 
								D3DXCOLOR ColorKey = 0xffffffff);
	void RenderTexture(LPD3DXSPRITE _lpDSpriteHandle,
		D3DXVECTOR2 position,
		D3DXVECTOR2 scale,
		float angle,
		RECT *srcRect, float deep,
		D3DCOLOR color = 0xffffffff);
};

#endif

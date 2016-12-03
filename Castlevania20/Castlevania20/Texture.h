#ifndef TEXTURE_H
#define TEXTURE_H
#include "Globals.h"

class Texture
{
public:
	char*				m_pFileName;
	RECT				m_rSize;
	LPDIRECT3DTEXTURE9	m_pTexture;
	D3DXIMAGE_INFO		m_Info;
	LPD3DXSPRITE		m_pSpriteHandler;
public:
	Texture(char* _fileName);
	~Texture();
	static Texture* create(char* _fileName);
	D3DXIMAGE_INFO getInfo();
	void Load();
	void DefaultTransform();
	//Draw method
	void Draw(D3DXVECTOR2 position, float depth = 0.5f);
	void Draw(D3DXVECTOR2 position, D3DXVECTOR2 Center, const RECT *srcRect, float depth = 0.5f);
	void Draw(D3DXVECTOR2 position, float depth, const RECT *srcRect, D3DCOLOR Color);
	void Draw(D3DXVECTOR2 position, D3DXVECTOR2 scale, float angle, D3DCOLOR color, RECT *rSrc, float deep);
	//Proffectional Draw Func
	void Draw(D3DXVECTOR2 position, D3DXVECTOR2 Center, D3DXVECTOR2 scale, float angle, D3DCOLOR color, RECT *rSrc, float deep = 0.5f);
};

#endif
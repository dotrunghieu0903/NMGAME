#include "Sprite.h"

#include <d3dx9.h>

CSprite::CSprite( char* FilePath, int Width, int Height, int Count, int SpritePerRow)
{
	D3DXIMAGE_INFO info;
	HRESULT result;

	_Image = NULL;

	_Width = Width;
	_Height = Height;
	_Count = Count;
	_SpritePerRow = SpritePerRow;
	_Index = 0;

	result = D3DXGetImageInfoFromFile(FilePath, &info);
	if (result != D3D_OK)
	{
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv;
	GL_graphic->m_pSpriteHandler->GetDevice(&d3ddv);

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		FilePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&info,
		NULL,
		&_Image);

	if (result != D3D_OK)
	{
		return;
	}
}


void CSprite::Render(int X, int Y)
{
	RECT srect;

	srect.left = (_Index % _SpritePerRow)*(_Width)+1;
	srect.top = (_Index / _SpritePerRow)*(_Height)+1;
	srect.right = srect.left + _Width;
	srect.bottom = srect.top + _Height + 1;

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	//
	// WORLD TO VIEWPORT TRANSFORM USING MATRIX
	//

	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = -(CCamera::GetCamera()->GetPosition().x);
	mt._42 = CCamera::GetCamera()->GetPosition().y;
	D3DXVECTOR4 vp_pos;
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);
	D3DXVECTOR3 center((float)_Width / 2, (float)_Height / 2, 0);

	GL_graphic->m_pSpriteHandler->Draw(
		_Image,
		&srect,
		&center,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
	);


}

void CSprite::Render(int X, int Y, int index)
{
	RECT srect;

	srect.left = (index % _SpritePerRow)*(_Width);
	srect.top = (index / _SpritePerRow)*(_Height);
	srect.right = srect.left + _Width;
	srect.bottom = srect.top + _Height;

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	//
	// WORLD TO VIEWPORT TRANSFORM USING MATRIX
	//

	D3DXMATRIX mt;
	D3DXMatrixIdentity(&mt);
	mt._22 = -1.0f;
	mt._41 = -(CCamera::GetCamera()->GetPosition().x);
	mt._42 = CCamera::GetCamera()->GetPosition().y;
	D3DXVECTOR4 vp_pos;//view port position
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);
	D3DXVECTOR3 center((float)_Width / 2, (float)_Height / 2, 0);

	GL_graphic->m_pSpriteHandler->Draw(
		_Image,
		&srect,
		&center,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
	);


}

void CSprite::Next()
{
	_Index = (_Index + _Count - 1) % _Count;
}

void CSprite::Reset()
{
	_Index = 0;
}

CSprite::~CSprite()
{
	_Image->Release();
}
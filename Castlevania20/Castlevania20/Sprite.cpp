#include "Sprite.h"

#include <d3dx9.h>

Sprite::Sprite( char* FilePath, int Width, int Height, int Count, int SpritePerRow)
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


void Sprite::Render(int X, int Y)
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
	mt._41 = -(CCamera::GetCamera()->getViewPortX());
	mt._42 = CCamera::GetCamera()->getViewPortY();
	D3DXVECTOR4 vp_pos;
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);
	D3DXVECTOR3 center(0, 0, 0);

	GL_graphic->m_pSpriteHandler->Draw(
		_Image,
		&srect,
		&center,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
	);


}

void Sprite::Render(int X, int Y, int index)
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
	mt._41 = -(CCamera::GetCamera()->getViewPortX());
	mt._42 = CCamera::GetCamera()->getViewPortY();
	D3DXVECTOR4 vp_pos;//view port position
	D3DXVec3Transform(&vp_pos, &position, &mt);

	D3DXVECTOR3 p(vp_pos.x, vp_pos.y, 0);
	D3DXVECTOR3 center(0, 0, 0);

	GL_graphic->m_pSpriteHandler->Draw(
		_Image,
		&srect,
		&center,
		&p,
		D3DCOLOR_XRGB(255, 255, 255)
	);


}

void Sprite::RenderFlipX(int X,int Y) {
	D3DXMATRIX old;
	GL_graphic->m_pSpriteHandler->GetTransform(&old);
	D3DXMATRIX newMt;
	D3DXMATRIX finalMt;
	D3DXVECTOR2 center = D3DXVECTOR2(X + this-> _Width/ 2, Y + this->_Height / 2);
	D3DXVECTOR2 rotation = D3DXVECTOR2(-1, 1);
	D3DXMatrixTransformation2D(&newMt, &center, 0.0f, &rotation, NULL, 0.0f, NULL);
	finalMt = old*newMt;
	GL_graphic->m_pSpriteHandler->SetTransform(&finalMt);
	X += this->_Width;
	this->Render(X,Y);
	GL_graphic->m_pSpriteHandler->SetTransform(&old);
}

void Sprite::Next()
{
	_Index = (_Index + _Count - 1) % _Count;
}

void Sprite::Reset()
{
	_Index = 0;
}

Sprite::~Sprite()
{
	_Image->Release();
}
#include "Texture.h"



Texture::Texture()
{
	m_lpDirect3DTexture = 0;
}

void Texture::LoadTextureFromFile(LPDIRECT3DDEVICE9 _lpDirectdevice, LPCSTR fileName, D3DXCOLOR ColorKey)
{
	D3DXIMAGE_INFO _infoImg;
	HRESULT hr;
	hr = D3DXGetImageInfoFromFile(fileName, &_infoImg);

	if (FAILED(hr))
	{
		return;
	}
	m_Width = _infoImg.Width;
	m_Height = _infoImg.Height;
	hr = D3DXCreateTextureFromFileEx(
		_lpDirectdevice,
		fileName,
		_infoImg.Width,
		_infoImg.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		ColorKey,
		&_infoImg,
		0,
		&m_lpDirect3DTexture
	);
	if (FAILED(hr))
	{
		return;
	}
}

void Texture::RenderTexture(LPD3DXSPRITE _lpDSpriteHandle, D3DXVECTOR2 position, D3DXVECTOR2 scale, float angle, RECT * srcRect, float deep, D3DCOLOR color)
{
	D3DXVECTOR3 currentPosition(position.x, position.y, deep); //toa do trong the gioi thuc

	D3DXMATRIX oldMatrix; //ma tran luu lai phep transform cua SpriteBatch

	_lpDSpriteHandle->GetTransform(&oldMatrix);

	D3DXVECTOR2 centerScaleAndRotate = D3DXVECTOR2(position.x, position.y);//lay vi tri cua vat the lam tam xoay(vi vi tri cua vat la vi tri chinh giua cua vat)

	D3DXMATRIX matrixScalingRotate; //ma tran rotate, scale

	D3DXMatrixTransformation2D(&matrixScalingRotate,
		&centerScaleAndRotate,
		0.0f,
		&scale,
		&centerScaleAndRotate,
		D3DXToRadian(angle), 0);

	D3DXMATRIX finalMatrix = matrixScalingRotate * oldMatrix;

	_lpDSpriteHandle->SetTransform(&finalMatrix); //ma tran chuyen toa do vi tri cua vat the tu the gioi thuc sang toa do trong directX de ve

	_lpDSpriteHandle->Draw(
		this->m_lpDirect3DTexture,
		srcRect,
		&D3DXVECTOR3((float)(srcRect->right - srcRect->left) / 2, (float)(srcRect->bottom - srcRect->top) / 2, 0),
		&currentPosition,
		color);

	_lpDSpriteHandle->SetTransform(&oldMatrix);
}

Texture::~Texture()
{
}

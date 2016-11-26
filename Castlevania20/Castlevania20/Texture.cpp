#include "Texture.h"

Texture::Texture()
{
	lpDirect3DTexture = 0;
}

Texture::Texture(const Texture &textture)
{
	lpDirect3DTexture = 0;
}

Texture::~Texture()
{
}

void Texture::LoadTextureFromFile(LPDIRECT3DDEVICE9 lpDirectdevice, LPCSTR fileName, D3DXCOLOR ColorKey)
{
	D3DXIMAGE_INFO _infoImg;
	HRESULT hr;
	hr = D3DXGetImageInfoFromFile(fileName, &_infoImg);

	if (FAILED(hr))
	{
		return;
	}
	width = _infoImg.Width;
	height = _infoImg.Height;
	hr = D3DXCreateTextureFromFileEx(
		lpDirectdevice,
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
		&lpDirect3DTexture
	);
	if (FAILED(hr))
	{
		return;
	}
}

void Texture::Render(LPD3DXSPRITE lpDSpriteHandle, D3DXVECTOR2 position, D3DXVECTOR2 scale, float rotate, RECT * srcRect, float deep, D3DCOLOR color)
{
	D3DXVECTOR3 currentPosition(position.x, position.y, deep); //toa do trong the gioi thuc

	D3DXMATRIX oldMatrix; //ma tran luu lai phep transform cua SpriteBatch

	lpDSpriteHandle->GetTransform(&oldMatrix);

	D3DXVECTOR2 centerScaleAndRotate = D3DXVECTOR2(position.x, position.y);//lay vi tri cua vat the lam tam xoay(vi vi tri cua vat la vi tri chinh giua cua vat)

	D3DXMATRIX matrixScalingRotate; //ma tran rotate, scale

	D3DXMatrixTransformation2D(&matrixScalingRotate,
		&centerScaleAndRotate,
		0.0f,
		&scale,
		&centerScaleAndRotate,
		D3DXToRadian(rotate), 0);

	D3DXMATRIX finalMatrix = matrixScalingRotate * oldMatrix;

	lpDSpriteHandle->SetTransform(&finalMatrix); //ma tran chuyen toa do vi tri cua vat the tu the gioi thuc sang toa do trong directX de ve

	lpDSpriteHandle->Draw(
		this->lpDirect3DTexture,
		srcRect,
		&D3DXVECTOR3((float)(srcRect->right - srcRect->left) / 2, (float)(srcRect->bottom - srcRect->top) / 2, 0),
		&currentPosition,
		color);

	lpDSpriteHandle->SetTransform(&oldMatrix);
}

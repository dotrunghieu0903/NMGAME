#include "Texture.h"
Texture::Texture()
{
	m_pTexture = 0;
}
Texture::Texture(char* _fileName)
{
	m_pSpriteHandler = GL_graphic->m_pSpriteHandler;
	m_pFileName = _fileName;
	this->Load();
}

Texture::~Texture()
{
	if (this->m_pTexture != NULL) {
		this->m_pTexture->Release();
		m_pTexture = NULL;
	}
}

Texture* Texture::create(char* _fileName)
{
	Texture* temp = new Texture(_fileName);
	return temp;
}

D3DXIMAGE_INFO Texture::getInfo()
{
	return m_Info;
}

void Texture::Load()
{
	HRESULT result = D3DXGetImageInfoFromFile(m_pFileName, &m_Info);
	if (result != D3D_OK)
	{
		GLMessage("Can not load texture");
		GLLogger("[ERROR] Failed to get image m_Info '%s'", m_pFileName);
		return;
	}

	RECT s = { 0,0,m_Info.Width,m_Info.Height };
	m_rSize = s;

	result = D3DXCreateTextureFromFileEx(
		GL_graphic->GetDevice(),
		m_pFileName,
		m_Info.Width,
		m_Info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0, //color 
		&m_Info,
		NULL,
		&m_pTexture
	);

	if (result != D3D_OK)
	{
		GLMessage("Can not load texture");
		GLLogger("[ERROR] D3DXCreateTextureFromFileEx() failed");
		return;
	}
	else
		GLLogger("[SUCCESS] '%s' has been loaded ", m_pFileName);
}


void Texture::DefaultTransform()
{
	D3DXMATRIX mt;
	D3DXMatrixTransformation2D(&mt, NULL, 0, NULL, NULL, 0, NULL);
	m_pSpriteHandler->SetTransform(&mt);
}

void Texture::Draw(D3DXVECTOR2 position, float depth)
{
	D3DXVECTOR3 pos(position.x, position.y, depth);
	m_pSpriteHandler->Draw(
		m_pTexture,
		&m_rSize,
		NULL,
		&pos,
		D3DCOLOR_XRGB(255, 255, 255)
	);
}

void Texture::Draw(D3DXVECTOR2 position, float depth, const RECT *srcRect, D3DCOLOR Color)
{

	D3DXVECTOR3 pos(position.x, position.y, depth);
	m_pSpriteHandler->Draw(
		m_pTexture,
		srcRect,
		NULL,
		&pos,
		Color);
}

void Texture::Draw(D3DXVECTOR2 position, D3DXVECTOR2 Center, const RECT *srcRect, float depth)
{
	D3DXVECTOR3 pos(position.x, position.y, depth);
	m_pSpriteHandler->Draw(
		m_pTexture,
		srcRect,
		NULL,
		&pos,
		0);
}


void Texture::Draw(D3DXVECTOR2 position, D3DXVECTOR2 scale, float angle, D3DCOLOR color, RECT *srcRect, float deep)
{
	D3DXMATRIX oldMt;
	m_pSpriteHandler->GetTransform(&oldMt);

	D3DXVECTOR2 spriteCenter = D3DXVECTOR2(position.x + m_Info.Width / 2, position.y + m_Info.Height / 2);
	D3DXVECTOR2 tran = D3DXVECTOR2(0.0f, 0.0f);
	D3DXMATRIX newMT;
	D3DXMatrixTransformation2D(&newMT, &spriteCenter, 0.0, &scale, &spriteCenter, D3DXToRadian(angle), NULL);
	D3DXMATRIX finalMt = newMT * oldMt;
	m_pSpriteHandler->SetTransform(&finalMt);
	D3DXVECTOR3 pos(position.x, position.y, deep);
	m_pSpriteHandler->Draw(
		m_pTexture,
		srcRect,
		NULL,
		&pos,
		/*&D3DXVECTOR3((float)(srcRect->left), (float)( srcRect->top) , 0),
		&currentPosition,*/
		color);
	m_pSpriteHandler->SetTransform(&oldMt);
}


//final draw func
void Texture::Draw(D3DXVECTOR2 position, D3DXVECTOR2 Center, D3DXVECTOR2 scale, float angle, D3DCOLOR color, RECT *srcRect, float deep)
{
	D3DXVECTOR3 pos(position.x, position.y, deep);
	//if(scale.x!=1 || angle!=0)
	{
		D3DXMATRIX oldMt;
		m_pSpriteHandler->GetTransform(&oldMt);

		D3DXVECTOR2 centerScale = D3DXVECTOR2(position.x, position.y);
		D3DXVECTOR2 tran = D3DXVECTOR2(0.0f, 0.0f);
		D3DXMATRIX newMt;
		D3DXMatrixTransformation2D(&newMt, &centerScale, 0.0, &scale, &Center, D3DXToRadian(angle), NULL);
		D3DXMATRIX finalMt = newMt * oldMt;
		m_pSpriteHandler->SetTransform(&finalMt);

		m_pSpriteHandler->Draw(
			m_pTexture,
			srcRect,
			&D3DXVECTOR3((srcRect->right - srcRect->left) / 2, (srcRect->bottom - srcRect->top) / 2, 0),
			&pos,
			color);

		m_pSpriteHandler->SetTransform(&oldMt);
	}
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
		&m_pTexture
	);
	if (FAILED(hr))
	{
		return;
	}
}


//void Texture::RenderTexture(LPD3DXSPRITE _lpDSpriteHandle, D3DXVECTOR2 position, D3DXVECTOR2 scale, float angle, RECT * srcRect, float deep, D3DCOLOR color)
//{
//	D3DXVECTOR3 currentPosition(position.x, position.y, deep); //toa do trong the gioi thuc
//
//	D3DXMATRIX oldMatrix; //ma tran luu lai phep transform cua SpriteBatch
//
//	_lpDSpriteHandle->GetTransform(&oldMatrix);
//
//	D3DXVECTOR2 centerScaleAndRotate = D3DXVECTOR2(position.x, position.y);//lay vi tri cua vat the lam tam xoay(vi vi tri cua vat la vi tri chinh giua cua vat)
//
//	D3DXMATRIX matrixScalingRotate; //ma tran rotate, scale
//
//	D3DXMatrixTransformation2D(&matrixScalingRotate,
//		&centerScaleAndRotate,
//		0.0f,
//		&scale,
//		&centerScaleAndRotate,
//		D3DXToRadian(angle), 0);
//
//	D3DXMATRIX finalMatrix = matrixScalingRotate * oldMatrix;
//
//	_lpDSpriteHandle->SetTransform(&finalMatrix); //ma tran chuyen toa do vi tri cua vat the tu the gioi thuc sang toa do trong directX de ve
//
//	_lpDSpriteHandle->Draw(
//		this->m_pTexture,
//		srcRect,
//		&D3DXVECTOR3((float)(srcRect->right - srcRect->left) / 2, (float)(srcRect->bottom - srcRect->top) / 2, 0),
//		&currentPosition,
//		color);
//
//	_lpDSpriteHandle->SetTransform(&oldMatrix);
//}

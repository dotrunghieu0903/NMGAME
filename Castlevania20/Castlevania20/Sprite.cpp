#include "Sprite.h"

#include <d3dx9.h>

Sprite::Sprite()
{
	m_pTexture	= NULL;
	m_Effect	= SpriteEffect::None;
	m_fRotate	= 0;
	m_fScale	= 1;
	m_hasAni	= false;
}


Sprite::Sprite(Texture* texture) : m_Effect(SpriteEffect::None), m_fRotate(0), m_fScale(1), m_hasAni(false)
{
	m_pTexture = texture;
	//m_rSrcRect = m_pTexture->size;
	m_rSrcRect = CRectMake(0, 0, m_pTexture->m_Info.Width, m_pTexture->m_Info.Height);
	_Width = texture->getInfo().Width;
	_Height = texture->getInfo().Height;
}

Sprite::Sprite(Texture* texture, CRect srcRect) : m_Effect(SpriteEffect::None), m_fRotate(0), m_fScale(1), m_hasAni(false)
{
	m_pTexture = texture;
	m_rSrcRect = srcRect;
	_Width = srcRect._width;
	_Height = srcRect._height;
}

Sprite::Sprite(Texture* texture, int cols, int rows, int count, int start, int end)
{
	m_pTexture = texture;
	_Cols = cols;
	_SpritePerRow = rows;
	_Count = count;
	_Start = start;
	_End = end;
	_Index = _Start;
	_Width = m_pTexture->m_Info.Width / _Cols;
	_Height = m_pTexture->m_Info.Height / _SpritePerRow;
	m_vOrigin = D3DXVECTOR2(_Width / 2, _Height / 2);
	m_Effect = SpriteEffect::None;
	m_fRotate = 0;
	m_fScale = 1;
	m_rSrcRect = CRectMake((_Index % _Cols)*_Width, (_Index / _Cols)*_Height, _Width, _Height);
	m_TimeAni = TIME_ANI_DEFAULT;
	m_Timer = 0;
	m_hasAni = true;
}

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

void Sprite::Update(float dt)
{
	if (m_hasAni == true)
	{
		m_Timer += dt;
		if (m_Timer > m_TimeAni)
		{
			if (_Index <= _End)
				m_rSrcRect = CRectMake((_Index % _Cols)*_Width, (_Index / _Cols)*_Height, _Width, _Height);
			if (_Index < _End)
				_Index++;
			else
				_Index = _Start;
			m_Timer = 0;
		}
	}
}

void Sprite::SetIndex(int index)
{
	this->_Start = index;
	this->_End = index;
	this->_Index = index;
}

CRect Sprite::GetBound()
{
	CRect temp(0, 0, _Width, _Height);
	return temp;
}

void Sprite::Draw(D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale, float deep, D3DCOLOR color)
{
	if (m_pTexture != NULL)
	{
		m_vOrigin = D3DXVECTOR2(position.x + _Width / 2, position.y + _Height / 2);
		m_Effect = effect;
		if (rotate != 0)
			m_fRotate = rotate;
		if (scale != 1)
			m_fScale = scale;
		if (m_Effect == SpriteEffect::None)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(m_fScale, -m_fScale), m_fRotate, color, &m_rSrcRect.getRECT(), deep);
		else if (m_Effect == SpriteEffect::Horizontally)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(-m_fScale, -m_fScale), m_fRotate, color, &m_rSrcRect.getRECT(), deep);
		else if (m_Effect == SpriteEffect::Vertical)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(m_fScale, m_fScale), m_fRotate, color, &m_rSrcRect.getRECT(), deep);
	}
}

Sprite::~Sprite()
{
	if (_Image != NULL )
	{
		_Image->Release();
	}
	if (m_pTexture != NULL)
	{
		delete m_pTexture;
		m_pTexture = NULL;
	}
}
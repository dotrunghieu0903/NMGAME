#include "Sprite.h"

Sprite::Sprite()
{
	m_pTexture = NULL;
	m_Effect = SpriteEffect::None;
	m_fRotate = 0;
	m_fScale = 1;
	m_hasAni = false;
}

Sprite::Sprite(Texture* texture) : m_Effect(SpriteEffect::None), m_fRotate(0), m_fScale(1), m_hasAni(false)
{
	m_pTexture = texture;
	//m_rSrcRect = m_pTexture->size;
	m_rSrcRect = CRectMake(0, 0, m_pTexture->m_Info.Width, m_pTexture->m_Info.Height);
	m_FrameWidth = texture->getInfo().Width;
	m_FrameHeight = texture->getInfo().Height;
}

Sprite::Sprite(Texture* texture, CRect srcRect) : m_Effect(SpriteEffect::None), m_fRotate(0), m_fScale(1), m_hasAni(false)
{
	m_pTexture = texture;
	m_rSrcRect = srcRect;
	m_FrameWidth = srcRect._width;
	m_FrameHeight = srcRect._height;
}

Sprite::Sprite(Texture* texture, int cols, int rows, int count, int start, int end)
{
	m_pTexture = texture;
	m_Cols = cols;
	m_Rows = rows;
	m_Count = count;
	m_Start = start;
	m_End = end;
	m_Index = m_Start;
	m_FrameWidth = m_pTexture->m_Info.Width / m_Cols;
	m_FrameHeight = m_pTexture->m_Info.Height / m_Rows;
	m_vOrigin = D3DXVECTOR2(m_FrameWidth / 2, m_FrameHeight / 2);
	m_Effect = SpriteEffect::None;
	m_fRotate = 0;
	m_fScale = 1;
	m_rSrcRect = CRectMake((m_Index%m_Cols)*m_FrameWidth, (m_Index / m_Cols)*m_FrameHeight, m_FrameWidth, m_FrameHeight);
	m_TimeAni = TIME_ANI_DEFAULT;
	m_Timer = 0;
	m_hasAni = true;
}

Sprite::~Sprite()
{
	if (m_pTexture != NULL)
	{
		delete m_pTexture;
		m_pTexture = NULL;
	}
}

void Sprite::SetIndex(int index)
{
	this->m_Start = index;
	this->m_End = index;
	this->m_Index = index;
}

void Sprite::Update(float dt)
{
	if (m_hasAni == true)
	{
		m_Timer += dt;
		if (m_Timer > m_TimeAni)
		{
			if (m_Index <= m_End)
				m_rSrcRect = CRectMake((m_Index%m_Cols)*m_FrameWidth, (m_Index / m_Cols)*m_FrameHeight, m_FrameWidth, m_FrameHeight);
			if (m_Index < m_End)
				m_Index++;
			else
				m_Index = m_Start;
			m_Timer = 0;
		}
	}
}

void Sprite::Draw(CRect srcRect, D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale)
{
	if (m_pTexture != NULL)
	{
		m_FrameWidth = srcRect._width;
		m_FrameHeight = srcRect._height;
		m_vOrigin = D3DXVECTOR2(position.x + m_FrameWidth / 2, position.y + m_FrameHeight / 2);
		m_Effect = effect;
		m_fRotate = rotate;
		m_fScale = scale;
		m_rSrcRect = srcRect;
		if (m_Effect == SpriteEffect::None)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(m_fScale, -m_fScale), m_fRotate, D3DCOLOR_XRGB(255, 255, 255), &m_rSrcRect.getRECT(), 0.5f);
		else if (m_Effect == SpriteEffect::Horizontally)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(-m_fScale, -m_fScale), m_fRotate, D3DCOLOR_XRGB(255, 255, 255), &m_rSrcRect.getRECT(), 0.5f);
	}
}

void Sprite::Draw(D3DXVECTOR2 position, SpriteEffect effect)
{
	if (m_pTexture != NULL)
	{
		m_vOrigin = D3DXVECTOR2(position.x + m_FrameWidth / 2, position.y + m_FrameHeight / 2);
		m_Effect = effect;
		if (m_Effect == SpriteEffect::None)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(m_fScale, -m_fScale), m_fRotate, D3DCOLOR_XRGB(255, 255, 255), &m_rSrcRect.getRECT(), 0.5f);
		else if (m_Effect == SpriteEffect::Horizontally)
			m_pTexture->Draw(position, m_vOrigin, D3DXVECTOR2(-m_fScale, -m_fScale), m_fRotate, D3DCOLOR_XRGB(255, 255, 255), &m_rSrcRect.getRECT(), 0.5f);
	}
}
void Sprite::Draw(D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale, float deep, D3DCOLOR color)
{
	if (m_pTexture != NULL)
	{
		m_vOrigin = D3DXVECTOR2(position.x + m_FrameWidth / 2, position.y + m_FrameHeight / 2);
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

CRect Sprite::GetBound()
{
	CRect temp(0, 0, m_FrameWidth, m_FrameHeight);
	return temp;
}
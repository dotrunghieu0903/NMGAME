#include "GSpriteDx9.h"


GSpriteDx9::GSpriteDx9(void)
{
	m_MyTexture = 0;
	m_AnimationAction = 0;
	m_SpriteEffect = ESpriteEffect::NONE;
	m_Scale = 1.0f;
	m_Rotate = 0.0f;
}

GSpriteDx9::GSpriteDx9(const GSpriteDx9 & Sprite)
{
	m_MyTexture = new GTextureDx9(*Sprite.m_MyTexture);
	m_AnimationAction = new GAnimationDx9(*Sprite.m_AnimationAction);
	m_Column = Sprite.m_Column;
	m_Row = Sprite.m_Row;
	m_Total = Sprite.m_Total;
	m_Scale = Sprite.m_Scale;
	m_Rotate = Sprite.m_Rotate;
	m_SpriteEffect = Sprite.m_SpriteEffect;
}

void GSpriteDx9::LoadContent(LPDIRECT3DDEVICE9 lpDirectDevice, LPCSTR fileName, int Column, int Row, int Total, D3DXCOLOR TransparentColor)
{
	m_MyTexture = new GTextureDx9();
	m_MyTexture->LoadTextureFromFile(lpDirectDevice, fileName, TransparentColor);
	m_Column = Column;
	m_Row = Row;
	m_Total = Total;
	m_AnimationAction = new GAnimationDx9(m_MyTexture->m_Width / Column, m_MyTexture->m_Height / Row, Column, Total);
}

void GSpriteDx9::Render(LPD3DXSPRITE spriteHandle, D3DXVECTOR2 position, float scale, float rotateAngle, float deep, ESpriteEffect effect, D3DCOLOR color)
{
	switch (effect)
	{
	case ESpriteEffect::NONE:
		this->m_MyTexture->RenderTexture(spriteHandle, 
										position, 
										D3DXVECTOR2(scale, scale), 
										rotateAngle, 
										getAnimationAction()->getSourceRect(), 
										deep, 
										color);
		break;
	case ESpriteEffect::VER:
		this->m_MyTexture->RenderTexture(spriteHandle, position, D3DXVECTOR2(scale, -scale), rotateAngle, getAnimationAction()->getSourceRect(), deep, color);
		break;
	case ESpriteEffect::HOR:
		this->m_MyTexture->RenderTexture(spriteHandle, position, D3DXVECTOR2(-scale, scale), rotateAngle, getAnimationAction()->getSourceRect(), deep, color);
		break;
	default:
		break;
	}
}

void GSpriteDx9::UpdateAnimation(int timeAnimation)
{
	this->getAnimationAction()->UpdateAnimation(timeAnimation);
}

GSpriteDx9::~GSpriteDx9(void)
{
}

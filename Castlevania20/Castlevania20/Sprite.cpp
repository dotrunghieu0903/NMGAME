#include "Sprite.h"
Sprite::Sprite(Texture* texture,  int col, int row, int total)
{
	m_AnimationAction = 0;
	//m_SpriteEffect = CSprite::None;
	m_Scale = 1.0f;
	m_Rotate = 0.0f;
	m_AnimationAction = new Animation(texture->m_Width/col, texture->m_Height/row, col, total);
	m_MyTexture = texture;
}



Sprite::Sprite(const Sprite & Sprite)
{
	m_MyTexture = new Texture(*Sprite.m_MyTexture);
	m_AnimationAction = new Animation(*Sprite.m_AnimationAction);
	m_Column = Sprite.m_Column;
	m_Row = Sprite.m_Row;
	m_Total = Sprite.m_Total;
	m_Scale = Sprite.m_Scale;
	m_Rotate = Sprite.m_Rotate;
	//m_SpriteEffect = Sprite.m_SpriteEffect;
}

void Sprite::LoadContent(LPDIRECT3DDEVICE9 lpDirectDevice, LPCSTR fileName, int Column, int Row, int Total, D3DXCOLOR TransparentColor)
{
	m_MyTexture = new Texture();
	m_MyTexture->LoadTextureFromFile(lpDirectDevice, fileName, TransparentColor);
	m_Column = Column;
	m_Row = Row;
	m_Total = Total;
	m_AnimationAction = new Animation(m_MyTexture->m_Width / Column, m_MyTexture->m_Height / Row, Column, Total);
}

void Sprite::RenderXY(int _x, int _y) {
	RECT *rec = getAnimationAction()->getSourceRectAtIndex(1);
	D3DXVECTOR3 center(0, 0, 0);
	D3DXVECTOR3 position((float)_x, (float)_y, 0);
	GL_graphic->m_pSpriteHandler->Draw(this->getMyTexture()->getTexture(), getAnimationAction()->getSourceRect(), &center, &position, D3DCOLOR_XRGB(255, 255, 255));//color
	//this->m_MyTexture->RenderTexture(GL_graphic->m_pSpriteHandler,D3DXVECTOR2((float)_x, (float)_y), D3DXVECTOR2(1,1),0, getAnimationAction()->getSourceRect(),0, D3DCOLOR_XRGB(255,255,255));
}

void Sprite::RenderIndex(float _x, float _y, int index) {
	RECT *rec = getAnimationAction()->getSourceRectAtIndex(index);
	D3DXVECTOR3 center(0, 0, 0);
	D3DXVECTOR3 position((float)_x, (float)_y, 0);
	GL_graphic->m_pSpriteHandler->Draw(this->getMyTexture()->getTexture(), rec,&center,&position, D3DCOLOR_XRGB(255, 255, 255));
	//this->m_MyTexture->RenderTexture(GL_graphic->m_pSpriteHandler, D3DXVECTOR2(_x, _y), D3DXVECTOR2(1.0f, 1.0f), 0.0f, getAnimationAction()->getSourceRectAtIndex(index), 0, D3DCOLOR_XRGB(255, 255, 255));
	delete rec;
}

void Sprite::RenderFlipX(int _x, int _y) {
	this->m_MyTexture->RenderTexture(GL_graphic->m_pSpriteHandler, D3DXVECTOR2((float)_x, (float)_y), D3DXVECTOR2(1, 1), D3DXToRadian(90), getAnimationAction()->getSourceRect(), 0, D3DCOLOR_XRGB(255, 255, 255));
}
void Sprite::Render(LPD3DXSPRITE spriteHandle, D3DXVECTOR2 position, float scale, float rotateAngle, float deep, CSprite effect, D3DCOLOR color)
{
	switch (effect)
	{
	case CSprite::None:
		this->m_MyTexture->RenderTexture(spriteHandle,
			position,
			D3DXVECTOR2(scale, scale),
			rotateAngle,
			getAnimationAction()->getSourceRect(),
			deep,
			color);
		break;
	case CSprite::Vertically:
		this->m_MyTexture->RenderTexture(spriteHandle, position, D3DXVECTOR2(scale, -scale), rotateAngle, getAnimationAction()->getSourceRect(), deep, color);
		break;
	case CSprite::Horizontally:
		this->m_MyTexture->RenderTexture(spriteHandle, position, D3DXVECTOR2(-scale, scale), rotateAngle, getAnimationAction()->getSourceRect(), deep, color);
		break;
	default:
		break;
	}
}

void Sprite::UpdateAnimation(int timeAnimation)
{
	this->getAnimationAction()->UpdateAnimation(timeAnimation);
}

void Sprite::Release() {

}

Sprite::~Sprite()
{
	
}
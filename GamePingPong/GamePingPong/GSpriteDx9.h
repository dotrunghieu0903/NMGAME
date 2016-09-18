#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "GTextureDx9.h"
#include "GAnimationDx9.h"
#include "DefineMacro.h"

class GSpriteDx9
{
private:
	GAnimationDx9*	m_AnimationAction;
	GTextureDx9*	m_MyTexture;
	int				m_Column;
	int				m_Row;
	int				m_Total;
	ESpriteEffect	m_SpriteEffect;
	float			m_Scale;
	float			m_Rotate;
public:
	GSpriteDx9(void);
	GSpriteDx9(const GSpriteDx9& Sprite);
	~GSpriteDx9(void);
	void					LoadContent(LPDIRECT3DDEVICE9 lpDirectDevice, LPCSTR fileName, int Column, int Row, int Total, D3DXCOLOR TransparentColor = 0xFFFF00FF);
	void					Render(LPD3DXSPRITE spriteHandle, 
									D3DXVECTOR2 position, 
									float scale,
									float rotateAngle, 
									float deep, 		
									ESpriteEffect effect,
									D3DCOLOR color = 0xffffffff);
	void					UpdateAnimation(int timeAnimation);
	void					Release();


	GAnimationDx9*			getAnimationAction() { return m_AnimationAction; }
	GTextureDx9*			getMyTexture() { return m_MyTexture; }
	ESpriteEffect			getSpriteEffect() { return m_SpriteEffect; }
	float					getRotate() { return m_Rotate; }
	float					getScale() { return m_Scale; }
	int						getColumn() { return m_Column; }
	int						getRow() { return m_Row; }
	int						getTotal() { return m_Total; }
	void					setAnimationAction(GAnimationDx9* _animationaction) { m_AnimationAction = _animationaction; }
	void					setColumn(int _column) { m_Column = _column; }
	void					setMyTexture(GTextureDx9* _mytexture) { m_MyTexture = _mytexture; }
	void					setRotate(float _rotate) { m_Rotate = _rotate; }
	void					setRow(int _row) { m_Row = _row; }
	void					setScale(float _scale) { m_Scale = _scale; }
	void					setSpriteEffect(ESpriteEffect _spriteeffect) { m_SpriteEffect = _spriteeffect; }
	void					setTotal(int _total) { m_Total = _total; }
};
#endif


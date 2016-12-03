#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Texture.h"
#include "Animation.h"
#include "Globals.h"

class Sprite
{
private:
	Animation*		m_AnimationAction;
	Texture*		m_MyTexture;
	int				m_Column;
	int				m_Row;
	int				m_Total;
	//CSprite			m_SpriteEffect;
	float			m_Scale;
	float			m_Rotate;
public:
	Sprite(Texture* texture, int col, int row, int total);
	Sprite(const Sprite& Sprite);
	~Sprite();
	void	LoadContent(LPDIRECT3DDEVICE9 lpDirectDevice, LPCSTR fileName, int Column, int Row, int Total, D3DXCOLOR TransparentColor = 0xFFFF00FF);
	void	RenderXY(int x, int y);
	void	RenderIndex(float x, float y, int index);
	void	RenderFlipX(int x, int y);
	void	Render(LPD3DXSPRITE spriteHandle, D3DXVECTOR2 position, float scale, float rotateAngle, float deep, CSprite effect, D3DCOLOR color = 0xffffffff);
	void	UpdateAnimation(int timeAnimation);
	void	Release();


	Animation*			getAnimationAction() { return m_AnimationAction; }
	Texture*			getMyTexture() { return m_MyTexture; }
	//CSprite			getSpriteEffect() { return m_SpriteEffect; }
	float					getRotate() { return m_Rotate; }
	float					getScale() { return m_Scale; }
	int						getColumn() { return m_Column; }
	int						getRow() { return m_Row; }
	int						getTotal() { return m_Total; }
	void					setAnimationAction(Animation* _animationaction) { m_AnimationAction = _animationaction; }
	void					setColumn(int _column) { m_Column = _column; }
	void					setMyTexture(Texture* _mytexture) { m_MyTexture = _mytexture; }
	void					setRotate(float _rotate) { m_Rotate = _rotate; }
	void					setRow(int _row) { m_Row = _row; }
	void					setScale(float _scale) { m_Scale = _scale; }
	//void					setSpriteEffect(CSprite _spriteeffect) { m_SpriteEffect = _spriteeffect; }
	void					setTotal(int _total) { m_Total = _total; }

};
#endif
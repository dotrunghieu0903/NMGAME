#ifndef _CSPRITE_H_
#define _CSPRITE_H_
#include "Globals.h"
#include "Texture.h"
#include "Rect.h"
#include "Animation.h"

#define TIME_ANI_DEFAULT 0.4f

class Sprite
{
private:
	Animation*		m_AnimationAction;
	Texture*		m_MyTexture;
	float			m_Scale;
	float			m_Rotate;
public:
	Texture* m_pTexture;
	D3DXVECTOR2 m_vOrigin;
	SpriteEffect m_Effect;
	float m_fRotate;
	float m_fScale;
	D3DCOLOR m_color;
	CRect m_rSrcRect;
	bool m_hasAni;
	//ANIMATION

	int m_FrameWidth;
	int m_FrameHeight;
	int m_Count; //Sum of Frames
	int m_Cols;
	int m_Rows;
	int m_Index; //current frame

	int m_Start; //start index
	int m_End; //end index
	float m_TimeAni; //num of second to next frame
	float m_Timer;

	Sprite();
	~Sprite();
	Sprite(Texture* texture);
	Sprite(Texture* texture, CRect srcRect);
	Sprite(Texture* texture, int col, int row, int total);
	Sprite(Texture* texture, int cols, int rows, int count, int start, int end);
	void RenderXY(float x, float y);
	void RenderFlipX(float x, float y);
	void RenderIndex(float x, float y, int index);

	void SetIndex(int index);
	void Update(float dt);
	Animation*			getAnimationAction() { return m_AnimationAction; }
	Texture*			getMyTexture() { return m_MyTexture; }
	CRect GetBound();
	void Draw(CRect srcRect, D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale);
	void Draw(D3DXVECTOR2 position, SpriteEffect effect);
	void Draw(D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale, float deep = 0.5f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	//void Draw(D3DXVECTOR2 position, SpriteEffect effect, float rotate , float scale, float deep);
};
#endif
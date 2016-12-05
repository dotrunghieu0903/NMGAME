#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <d3d9.h>
#include <d3dx9.h>
#include "Globals.h"
#include "CCamera.h"
#include "Texture.h"
#include "Rect.h"

#define TIME_ANI_DEFAULT 0.4f

class Sprite {
private:
	Texture*		m_pTexture;
	D3DXVECTOR2		m_vOrigin;
	SpriteEffect	m_Effect;
	D3DCOLOR		m_color;
	CRect			m_rSrcRect;
	bool			m_hasAni;

protected:
	LPDIRECT3DTEXTURE9	_Image;				// The container of all the sprites
public:
	int		_Index;				// Current sprite index
	int		_Width;				// Frame width
	int		_Height;			// Frame height
	int		_Count;				// Number of sprites
	int		_SpritePerRow;		// Number of sprites per row
	int		_Cols;				// Number of sprites per col
	int		_Start;				// Run from first frame
	int		_End;				// Run to last frame
	float	m_TimeAni;			//num of second to next frame
	float	m_Timer;
	float	m_fRotate;
	float	m_fScale;

	Sprite();
	Sprite(char* FilePath, int Width, int Height, int Count, int SpritePerRow);
	Sprite(Texture* texture);
	Sprite(Texture* texture, CRect srcRect);
	Sprite(Texture* texture, int cols, int rows, int count, int start, int end);
	~Sprite();

	void Next();
	void Reset();

	// Render current sprite at location (X,Y)
	void Render(int X, int Y);
	void Render(int X, int Y, int index);
	void RenderFlipX(int X,int Y);

	void Update(float dt);
	void SetIndex(int index);
	CRect GetBound();
	void Draw(D3DXVECTOR2 position, SpriteEffect effect, float rotate, float scale, float deep = 0.5f, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));


};

#endif
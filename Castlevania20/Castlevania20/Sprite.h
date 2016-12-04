#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <d3d9.h>
#include <d3dx9.h>
#include "Globals.h"
#include "CCamera.h"

class CSprite {
protected:
	LPDIRECT3DTEXTURE9 _Image;				// The container of all the sprites

	int _Index;								// Current sprite index
	int _Width;								// Sprite width
	int _Height;							// Sprite height
	int _Count;								// Number of sprites
	int _SpritePerRow;						// Number of sprites per row
public:
	CSprite::CSprite(char* FilePath, int Width, int Height, int Count, int SpritePerRow);
	void Next();
	void Reset();

	// Render current sprite at location (X,Y)
	void Render(int X, int Y);
	void Render(int X, int Y, int index);
	~CSprite();
};

#endif
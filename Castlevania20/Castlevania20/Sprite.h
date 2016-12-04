#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <d3d9.h>
#include <d3dx9.h>
#include "Globals.h"
#include "CCamera.h"

class Sprite {
protected:
	LPDIRECT3DTEXTURE9 _Image;				// The container of all the sprites
public:
	int _Index;	// Current sprite index
	int _Width;	// Frame width
	int _Height;// Frame height
	int _Count;// Number of sprites
	int _SpritePerRow;// Number of sprites per row
	int _Start;// Run from first frame
	int _End;//Run to last frame
	Sprite::Sprite(char* FilePath, int Width, int Height, int Count, int SpritePerRow);
	void Next();
	void Reset();

	// Render current sprite at location (X,Y)
	void Render(int X, int Y);
	void Render(int X, int Y, int index);
	void RenderFlipX(int X,int Y);
	~Sprite();
};

#endif
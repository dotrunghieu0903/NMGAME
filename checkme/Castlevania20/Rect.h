#ifndef CRECT_H
#define CRECT_H
#include <d3d9.h>
#include <d3dx9.h>

#include "SweptAABB.h"
#define CRectMake(x, y, width, height) CRect((float)(x), (float)(y), (float)(width), (float)(height))

class CRect
{
public:
	float _x;
	float _y;
	float _width;
	float _height;
	D3DXVECTOR2 origin;
public:
	CRect();
	~CRect();
	CRect(float x, float y, float w, float h);
	CRect(D3DXVECTOR2 pos, float w, float h);
	static CRect* create(float x, float y, float w, float h);
	RECT getRECT();
	void setRect(float x, float y, float w, float h);
	float getMinX()const;
	float getMidX()const;
	float getMaxX()const;
	float getMinY()const;
	float getMidY()const;
	float getMaxY()const;
	bool containsPoint(D3DXVECTOR2 point);
	bool intersectsRect(const CRect& rect);
	static CRect Convert(Box box)
	{
		return CRect(box.x, box.y, box.w, box.h);
	};
	// new phuc vu cho quadtree
	// child CRect
	bool containRect(const CRect &rect);
	CRect QuadTL();
	CRect QuadTR();
	CRect QuadBL();
	CRect QuadBR();
	static CRect Overlap(const CRect &r1, const CRect &r2);
};
#endif
#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_
#include "GameTime.h"
#include "Texture.h"
#include "IGame.h"
#include "SweptAABB.h"

static bool Intersect(const RECT *rect1, const RECT *rect2)
{
	if (rect1 == NULL || rect2 == NULL)
		return false;

	if (rect1->right < rect2->left) // _rect bên trái so với obj->_rect
		return false;
	if (rect1->left > rect2->right) // _rect bên phải so với obj->_rect
		return false;
	if (rect1->bottom > rect2->top) // _rect bên trên so với obj->_rect
		return false;
	if (rect1->top < rect2->bottom) // _rect bên dưới so với obj->_rect
		return false;

	return true;
}

static Box ConvertRectToBox(RECT rect, float vx = 0.0f, float vy = 0.0f)
{
	Box box(
		(float)rect.left,
		(float)rect.top,
		(float)(rect.right - rect.left),
		(float)(rect.top - rect.bottom),
		vx,
		vy
	);

	return box;
}

static Box ConvertRectToBoardBox(RECT rect, float vx = 0.0f, float vy = 0.0f)
{
	return GetSweptBroadphaseBox(ConvertRectToBox(rect, vx, vy));
}

class BaseObject
{
public:
	ObjectName objName;
	Texture * m_Texture;
	int m_OffSetX;//xác định Frame
	int m_OffSetY;
	int m_x, m_y;
	RECT m_rect;// HCN thể hiện frame animation đối tượng
	int m_height, m_width;
	RECT m_rectObj;
	D3DXVECTOR2 m_position;
	CSprite* m_Sprite;
	BaseObject();
	BaseObject(Texture *, D3DXVECTOR2);
	virtual void Update(GameTime *);
	//virtual void Draw(IGame *, Camera *);//draw follow camera
	//virtual void Draw(IGame *, Camera *,D3DXCOLOR);
	virtual void UpdateBound();// update rectangle around object
	virtual Box GetObjectBox();
	virtual ObjectName GetName();
	virtual~BaseObject();
};

#endif // class baseobject
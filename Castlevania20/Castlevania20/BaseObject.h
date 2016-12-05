#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_
#include "FrameWork.h"
#include "SweptAABB.h"
using namespace std;

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

enum EObjectType
{
	ESimon,
};
enum EState
{
	Alive,
	Move,
	Die,
	Breaking,
	Stand,
	Hit,
	KickUp,
	Blocked,
	NoCheckCollision,
	NoUpdate
};

enum ECollisionDirect
{
	Colls_None,
	Colls_Left,
	Colls_Right,
	Colls_Bot,
	Colls_Top
};

enum EKind
{
	EDynamic,
	EStatic,
	ESolid,
	EScene
};

class BaseObject
{
protected:
	EState				m_state;		// trang thai cua doi tuong
	EObjectType			m_type;			// type of object
	Sprite*				m_pSprite;		// object'sprite
	D3DXVECTOR2			m_position;		// object' position
	EDirection			m_direction;	// huong di chuyen
	D3DXVECTOR2			m_velocity;		// van toc
	SpriteEffect		m_effect;
	float				rotate;
	bool				m_isFall;
	bool				canUpdate;

	//new
	int _id;
public:
	BaseObject();

	static list<BaseObject*> _creatingAfterObjects;
	static void RemoveDiedObject(); // remove died object in _creatingAfterObjects

	 /*constructor destructor*/
	BaseObject(D3DXVECTOR2, EObjectType, EState state = Alive);
	BaseObject(D3DXVECTOR2, EObjectType, int id, EState state);
	virtual ~BaseObject();

	/*Update and Draw method*/
	virtual void Update(float);
	virtual void Draw();

	virtual CRect GetBound() const; // rectangle bounds the object
	virtual Box GetBox();
	virtual EObjectType GetRealObjectType() { return m_type; };
	virtual void SetCanUpdate(bool value) { canUpdate = value; }

	//Get , set method
	EDirection GetDirection();
	D3DXVECTOR2 GetPosition();
	D3DXVECTOR2 GetVelocity();
	EState GetObjectState();
	EObjectType GetObjectType() const; // object type	
	Sprite* GetSprite();
	EKind GetKindOfObject();

	void SetDirection(EDirection di);
	void SetPosition(D3DXVECTOR2 pos);
	void SetVelocity(D3DXVECTOR2 vel);
	void SetObjectState(EState);
	void SetFall(bool isfall);

};

#endif // class baseobject
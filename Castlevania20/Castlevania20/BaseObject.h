#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_
#include "GameTime.h"
#include "Camera.h"

class BaseObject
{
private: 
	ObjectName objName;
	int m_OffSetX;//xác định Frame
	int m_OffSetY;
	RECT* rect;// HCN thể hiện frame animation đối tượng
public:
	BaseObject();
	//virtual void Update(GameTime *); // Update Object
	//virtual void UpdateBound();
	virtual~BaseObject();
};

#endif // class baseobject
#ifndef _SIMON_H_
#define _SIMON_H_
#include "BaseObject.h"
#include "SweptAABB.h"

class Simon : public BaseObject
{
private:
	bool _isMoveRight;
	
public:
	static Simon* _simon;
	int m_State;
	Simon();
	static Simon* getCurrentSimon();
	Simon(int _x,int _y);
	bool isDead();
	void SetFrame();
	void Draw();
	~Simon();
};
#endif
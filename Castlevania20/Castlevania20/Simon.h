#ifndef _SIMON_H_
#define _SIMON_H_
#include "BaseObject.h"
#include "SweptAABB.h"

class Simon : public BaseObject
{
private:
	int _state;
	bool _isMoveRight;
	bool _isFalling;
	bool _isOnStair;
	
public:
	static Simon* _simon;
	Simon();
	int GetState() {	return _state;	}
	static Simon* getCurrentSimon();
	Simon(int _x, int _y);
	bool isDead();
	void SetFrame(float deltime);
	void MoveUpdate(float deltime);
	void Update(float deltime);
	
	void Draw();
	~Simon();
};
#endif
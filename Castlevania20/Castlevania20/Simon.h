#ifndef _SIMON_H_
#define _SIMON_H_
#include "BaseObject.h"
#include "SweptAABB.h"

class Simon : public BaseObject
{
private:
	int _state;
	bool _isMoveRight;
	bool _isMoveLeft;
	bool _isFalling;
	bool _isOnStair;
	bool _isJumping;
	
public:
	static Simon* _simon;
	Simon();
	Simon(int _x, int _y);
	int GetState() {	return _state;	}
	static Simon* getCurrentSimon();
	bool isDead();
	void SetFrame(float deltime);
	void MoveUpdate(float deltime);
	void Update(float deltime);
	void UpdateKeyboard(float deltime);
	void Draw();
	~Simon();
};
#endif
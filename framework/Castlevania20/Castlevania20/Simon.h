#ifndef __SIMON_H__
#define __SIMON_H__


#include "BaseObject.h"
#include "Input.h"

#define SIMON_SPRITE		L"resource\\sprite\\simon.png"
#define SIMON_WIDTH			32
#define SIMON_HEIGHT		64
#define SIMON_SPEED			0.2f
#define SIMON_JUMP_SPEED	0.7f
#define SIMON_ANIMATE_RATE	7
#define SIMON_ATTACK_RATE	10
#define TYPE 2
#define SIMON_JUMPMAX 64

enum STATE
{
	IS_STANDING = 1, // đứng
	IS_JOGGING = 2, //đi bộ
	IS_SITTING = 3, // NGỒI
	IS_JUMPING = 4, //NHẢY 
	IS_UPING = 5, // LÊN CẦU THANG
	IS_DOWNING = 6, // XUỐNG CẦU THANG
	IS_FIGHTING = 7, // ĐÁNH
	IS_JUMPFIGH = 8, //NHẢY LÊN ĐÁNH
	IS_SITFIGHT = 9, // NGỒI ĐÁNH
	IS_UPFIGHT = 10, //LÊN CẦU THANG VỪA ĐÁH
	IS_DOWNFIGHT = 11, // VỪA XUỐNG CẦU THANG VỪA ĐÁNH.
	IS_PASSGATE = 12, // QUA MAN.
	IS_FALLING = 13 // DANG ROI XUONG.
};

class Simon : public BaseObject {
private:

	static Simon* _simon;

	int _stateCurrent; //trạng thái hiện tại
	bool _isMoveleft; // quay qua trái hay k
	bool _isMoveright;
	bool _isOnStair; // dang o tren cau thang hay k
	bool _isJumping; //dang nhay
	bool _isFalling;// dang roi xuong
	bool _isFighting;
public:
	static Simon* getCurrentSimon();
	Simon(int x, int y);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void InputUpdate(float deltatime);
	void Update(float deltatime);
	void ChangeState(int state);
	int GetState() {
		return _stateCurrent;
	}
	void Draw();
	void Jump();
	Simon();
	~Simon();
};

#endif
#ifndef __SIMON_H__
#define __SIMON_H__


#include "BaseObject.h"
#include "Input.h"
#include <vector>
using namespace std;

#define SIMON_SPRITE		L"resource\\sprite\\simon.png"
#define SIMON_WIDTH			60
#define SIMON_HEIGHT		66
#define SIMON_SPEED			0.2f
//#define SIMON_JUMP_SPEED	0.7f
//#define SIMON_ANIMATE_RATE	7
//#define SIMON_ATTACK_RATE	10
#define TYPE 2
//#define SIMON_JUMPMAX 64
#define SIMON_VX_STAIR 0.7f

enum STATESIMON
{
	STANDING = 1, // đứng
	JOGGING = 2, //đi bộ //qua trái/qua phải
	SITTING = 3, // NGỒI
	JUMPING = 4, //NHẢY 
	UPING = 5, // LÊN CẦU THANG
	DOWNING = 6, // XUỐNG CẦU THANG
	FIGHTING = 7, // ĐÁNH
	JUMPFIGH = 8, //NHẢY LÊN ĐÁNH
	SITFIGHT = 9, // NGỒI ĐÁNH
	UPFIGHT = 10, //LÊN CẦU THANG VỪA ĐÁH
	DOWNFIGHT = 11, // VỪA XUỐNG CẦU THANG VỪA ĐÁNH.
	PASSGATE = 12, // QUA MAN.
	FALLING = 13 // DANG ROI XUONG.
};

class Simon : public BaseObject {
private:

	static Simon* _simon;

	int _stateCurrent; //trạng thái hiện tại
	bool _isMoveleft; // quay qua trái
	bool _isMoveright;//qua phai
	bool _isOnStair; // dang o tren cau thang hay k
	bool _isJumping; //dang nhay
	bool _isFalling;// dang roi xuong
	bool _isFighting;//dang danh
public:
	static Simon* getCurrentSimon();
	Simon();
	Simon(int x, int y);
	void MoveUpdate(float deltatime);
	void SetFrame(float deltattime);
	void InputUpdate(float deltatime);
	//void ChangeState(int state);
	int GetState() {
		return _stateCurrent;
	}
	void Draw();
	void ReturnCheckCollision(vector<BaseObject*> lisobject);
	void Jump();
	~Simon();
};

#endif
#ifndef _SIMON_H_
#define _SIMON_H_
#include "BaseObject.h"
//#include "SweptAABB.h"

#define SIMON_SPEED 6
#define SUPER_SPEED 10
#define SIMON_SPEEDWJUMP 5.5f
#define FRICTION 0.25f
#define TIME_IMMORTAL_AFTER_HIT 2
#define TIME_SUPER_STAR 10
enum ESimonState
{
	Enone,
	Ebig,
	Edie, 
	EResborn
};

enum ESimonAction
{
	ENone,
	EStanding,
	EStandingInBar,
	EJumping,
	ESitting,
	ERunning,
	EFalling,
	EShooting,
	EDying
};
class Simon : public BaseObject
{
private:
	ESimonState simonState;
	ESimonAction simonAction;

	ESimonState nextSimonState;
	ESimonState previousState;

	Sprite* smallSimon;


	float timeCheckLastPoint;
	D3DXVECTOR2 positionLastCheck;
	bool isLeft;  //Kiem tra simon dang quay ben trai hay phai
	bool hasJumped; //Kiem tra simon co dang nhay hay ko
	bool isFall; //Kiem tra simon co dang roi hay ko
	bool isStandInBar; //Kiem tra simon co dang dung tren Bar hay ko
	bool canShoot; //Kiem tra simon co duoc phep ban sung ko
	bool isImmortal; //trang thai bat tu

	bool tmpCheck; //bien tam kieu bool
	bool tmpCheck2;

	float timeShoot;
	float timeNextShoot;
	float timeChangeState;
	float timeImmortal;
	float timeSuperStar;

	int alpha_immortal;
	int alpha_superstar;

	bool isInPiPe;

	int gold;
	int life;
	int score;
public:
	Simon(D3DXVECTOR2 pos, ESimonState stateSimon, ESimonState previousState = Ebig);
	virtual ~Simon();
	void TurnLeft();
	void TurnRight();
	void Stop();
	void Jump(int v = 25);
	void Sit();
	void Fall();
	void Shoot();
	//void Reborn();
	/*Update & Draw method*/
	virtual void Update(float dt);
	//virtual void UpdateCollision(list<BaseObject*>, float dt);
	virtual void Draw();
	void ChangeState(float dt);
	bool isLevelFinish;

	int GetCoin() { return gold; }
	int GetLife() { return life; }
	int GetScore() { return score; }
	void SetCoin(int c) { gold = c; }
	void SetLife(int l) { life = l; }
	void SetScore(int s) { score = s; }
	ESimonState GetSimonState() { return simonState; }
	ESimonState GetPreviousState() { return previousState; }
	void SetSimonState(ESimonState state) { simonState = state; }

	bool GetIsInPipe() { return isInPiPe; }
};
#endif
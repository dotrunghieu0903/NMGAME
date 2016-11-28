#ifndef _GAMETIME_H_
#define _GAMETIME_H_
#include "TimeSpan.h"
class GameTime
{
private:
	static GameTime*	m_Instance;
	TimeSpan			m_ElapsedGameTime;
	LARGE_INTEGER			m_Query;
	float					m_FreQuency;
	LONGLONG				StartTicks;
	LONGLONG				LastTicks;
	LONGLONG				CurTicks;

public:
	GameTime();
	static GameTime* getInstance();
	void InitGameTime();
	void ResetLastTick();
	void UpdateGameTime();
	TimeSpan	getElapsedGameTime();
	void			setElapsedGameTime(TimeSpan& elapsedGameTime);
	GameTime(TimeSpan& elapsedGameTime, TimeSpan& totalGameTime);
	~GameTime();
};

#endif // ! 
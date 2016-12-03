#ifndef _TIMESPAN_H_
#define _TIMESPAN_H_
#include <windows.h>
class TimeSpan
{
private:
	UINT64 m_Tick;
public:
	static const UINT64 TicksPerSecond = 10000000;
	static const UINT64 TicksPerMillisecond = 10000;
	TimeSpan();
	TimeSpan(UINT64 tick);
	int getMilisecond();
	UINT64 getTick();
	TimeSpan& operator= (const TimeSpan& timeSp);
	~TimeSpan();
};
#endif
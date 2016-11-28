#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	this->m_Tick = 0;
}

TimeSpan::TimeSpan(UINT64 tick)
{
	this->m_Tick = tick;
}

int TimeSpan::getMilisecond()
{
	return (int)(m_Tick / TicksPerMillisecond);
}
UINT64 TimeSpan::getTick()
{
	return m_Tick;
}

TimeSpan& TimeSpan:: operator= (const TimeSpan& timeSp) {
	this->m_Tick = timeSp.m_Tick;
	return *this;
}
TimeSpan::~TimeSpan()
{
}

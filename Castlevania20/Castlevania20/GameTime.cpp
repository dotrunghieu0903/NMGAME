#include "GameTime.h"

GameTime* GameTime::s_Instance = 0;

GameTime::GameTime()
{
	this->m_ElapsedGameTime = TimeSpan(1);
}

GameTime::GameTime(TimeSpan &elapsedGameTime, TimeSpan &totalGameTime)
{
	this->m_ElapsedGameTime = elapsedGameTime;
}

GameTime::~GameTime()
{
}

GameTime* GameTime::getInstance()
{
	if (s_Instance == 0)
	{
		s_Instance = new GameTime();
	}
	return s_Instance;
}

void GameTime::InitGameTime()
{
	QueryPerformanceFrequency(&m_Query);
	m_FreQuency = (float)m_Query.QuadPart / 10000000;
	QueryPerformanceCounter(&m_Query);
	StartTicks = LastTicks = m_Query.QuadPart;
}
void GameTime::UpdateGameTime()
{
	QueryPerformanceCounter(&m_Query);
	CurTicks = m_Query.QuadPart;
	if ((UINT64)((float)(CurTicks - LastTicks) / m_FreQuency) < TimeSpan::TicksPerMillisecond * 16)
	{
		return;
	}
	else
	{
		this->setElapsedGameTime(TimeSpan((UINT64)((float)(CurTicks - LastTicks) / m_FreQuency)));
		LastTicks = CurTicks;
	}
}

void GameTime::ResetLastTick()
{
	LastTicks = 0;
	CurTicks = 0;
}

void GameTime::setElapsedGameTime(TimeSpan &elapsedGameTime)
{
	this->m_ElapsedGameTime = elapsedGameTime;
}
TimeSpan GameTime::getElapsedGameTime()
{
	if (m_ElapsedGameTime.getMilisecond() > 1000 / 30)
	{
		return TimeSpan(1000 / 60);
	}
	return m_ElapsedGameTime;
}

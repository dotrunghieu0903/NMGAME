#ifndef	_TIMER_H
#define _TIMER_H
#include "windows.h"
#include "math.h"
#include "tchar.h"

#include "Define.h"

class Timer
{
private:
	//Tinh toan frame per second
	float			m_Count;
	DWORD			m_LastFPSTime;
	float			m_FPSAvarage;  //so frame per second 
								   //Timer su dung QueryPerformance
	LARGE_INTEGER	m_NS_LastTime;
	LARGE_INTEGER	m_NS_CurrentTime;
	LARGE_INTEGER	m_NS_Frequency;
	//biến kiểm tra tính time theo cách nào
	bool			m_IsPerfHardware;
	//Tính timer theo cách getTime thông thường
	DWORD			m_MS_LastTime;
	DWORD			m_MS_CurrentTime;
public:
	Timer();
	~Timer();
	//public method
	float	Tick(); //lấy khoảng delta time mỗi lần update
	void	FreshTime();
	float	GetFrameRate(); //trả về số frame per second hiện tại
};

#endif
#ifndef _SOUNDMANAGEMENT_H_
#define _SOUNDMANAGEMENT_H_
#include "Globals.h"
class SoundManagement
{
private:
	long m_volume;
	bool m_mute;
	static SoundManagement m_Instance;
public:
	static SoundManagement* getInstance();
	SoundManagement();
	//void Add(LPDIRECTSOUND8);
	void SetVolume(long);
	long GetVolume();
	void SetMute(bool);
	bool GetMute();
	void VolumeUp();
	void VolumeDown();
	~SoundManagement();
};
#endif
#ifndef _SOUNDMANAGEMENT_H_
#define _SOUNDMANAGEMENT_H_
#include "Globals.h"
#include "DSound.h"
#include "SoundBuffer.h"
#include <map>
class SoundManagement
{
private:
	map<SoundName,SoundBuffer* > m_ListSound;
	long m_volume;
	bool m_mute;
	static SoundManagement m_Instance;
public:
	static SoundManagement* getInstance();
	SoundManagement();
	void AddAll(LPDIRECTSOUND8);
	void Add(LPDIRECTSOUND8, SoundName,std::string);
	SoundBuffer* GetSoundName(SoundName);
	void SetVolume(long);
	long GetVolume();
	void SetMute(bool);
	bool GetMute();
	void VolumeUp();
	void VolumeDown();
	~SoundManagement();
};
#endif
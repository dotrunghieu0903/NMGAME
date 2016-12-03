#ifndef _SOUNDBUFFER_H_
#define _SOUNDBUFFER_H_
#include "DSound.h"
#include "Globals.h"
#include "DSutil.h"

class SoundBuffer
{
private:
	LPDIRECTSOUNDBUFFER m_soundBuffer;
	LPDIRECTSOUND8 m_DS;
public:
	SoundBuffer();
	SoundBuffer(LPDIRECTSOUND8 pDS);
	bool LoadWaveToSoundBuffer(std::string wavFileName);
	LPDIRECTSOUNDBUFFER getSoundBuffer();
	void Play();
	void PlayLoop();
	void Stop();
	~SoundBuffer();
};
#endif
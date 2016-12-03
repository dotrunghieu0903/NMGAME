#include "SoundManagement.h"

SoundManagement::SoundManagement()
{
	m_volume = 0;
	m_mute = false;
}

SoundManagement SoundManagement::m_Instance = SoundManagement();

void SoundManagement::AddAll(LPDIRECTSOUND8 m_DS){
	//this->Add(m_DS, SoundName::HIT, "hit.wav");
}

void SoundManagement::Add(LPDIRECTSOUND8 m_DS, SoundName name, string wavFileName) {
	SoundBuffer* bf = new SoundBuffer(m_DS);
	bf->LoadWaveToSoundBuffer(wavFileName);
	bf->getSoundBuffer()->SetVolume(m_volume);
	m_ListSound[name] = bf;
}

SoundBuffer* SoundManagement::GetSoundName(SoundName name) {
	map<SoundName, SoundBuffer*>::iterator i;
	i = m_ListSound.find(name);
	if (i == m_ListSound.end()) {
		return NULL;
	}
	return i->second;
}

void  SoundManagement::SetVolume(long value){
	if (value < -10000)
	{
		value = -10000;
	}
	else if (value > 0)
	{
		value = 0;
	}

	m_volume = value;

	map<SoundName, SoundBuffer *>::iterator i;
	for (i = m_ListSound.begin(); i != m_ListSound.end(); i++)
	{
		i->second->getSoundBuffer()->SetVolume(m_volume);
	}
}

long SoundManagement::GetVolume() {
	return this->m_volume;
}

void SoundManagement::SetMute(bool value) {
	this->m_mute = value;
	if (m_mute==true) {
		map<SoundName, SoundBuffer *>::iterator i;
		for (i = m_ListSound.begin(); i != m_ListSound.end();i++) {
		}
	}
}

bool SoundManagement::GetMute() {
	return m_mute;
}

void SoundManagement::VolumeUp() {
	if (m_volume < -900) {
		m_volume = -900;
	}
	else
	{
		m_volume += 100;
		if (m_volume > 0) {
			m_volume = 0;
		}
	}
	this->SetVolume(m_volume);
}

void SoundManagement::VolumeDown() {
	
}
SoundManagement::~SoundManagement()
{
}

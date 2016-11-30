#include "SoundManagement.h"

SoundManagement::SoundManagement()
{
	m_volume = 0; m_mute = false;
}

SoundManagement SoundManagement::m_Instance = SoundManagement();

void SoundManagement::AddAll(LPDIRECTSOUND8 m_DS){
	//this->Add(m_DS, SoundName::HIT, "hit.wav");
}
SoundManagement::~SoundManagement()
{
}

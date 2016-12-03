#include "SoundBuffer.h"

SoundBuffer::SoundBuffer()
{
}

SoundBuffer::SoundBuffer(LPDIRECTSOUND8 _DS)
{
	this->m_DS = _DS;
	this->m_soundBuffer = NULL;
}

bool SoundBuffer::LoadWaveToSoundBuffer(std::string wavFileName) {
	CWaveFile *wavFile;
	HRESULT hr;
	wavFile = new CWaveFile();
	wavFile->Open((char*)wavFileName.c_str(),NULL,WAVEFILE_READ);
	if (wavFile->GetSize() == 0) {
		//(Logger::GetLogger("DXSoundBuffer::LoadWaveToSoundBuffer(std::string wavFilename)").Error("Invalid file!"));
		return false;
	}

	DSBUFFERDESC dsbd;
	ZeroMemory(&dsbd, sizeof(DSBUFFERDESC));
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	//dsbd.dwFlags         = 0;
	dsbd.dwFlags = DSBCAPS_CTRLVOLUME;
	dsbd.dwBufferBytes = wavFile->GetSize();
	dsbd.guid3DAlgorithm = GUID_NULL;
	dsbd.lpwfxFormat = wavFile->m_pwfx;

	hr = m_DS->CreateSoundBuffer(&dsbd, &m_soundBuffer, NULL);
	if FAILED(hr)
	{
		//(Logger::GetLogger("DXSoundBuffer::LoadWaveToSoundBuffer(std::string wavFilename)").Error("Unable to create sound buffer!"));
		return false;
	}

	VOID*   pDSLockedBuffer = NULL; // Pointer to locked buffer memory
	DWORD   dwDSLockedBufferSize = 0;    // Size of the locked DirectSound buffer
	DWORD   dwWavDataRead = 0;    // Amount of data read from the wav file 

	hr = m_soundBuffer->Lock(0, wavFile->GetSize(),
		&pDSLockedBuffer, &dwDSLockedBufferSize,
		NULL, NULL, 0L);
	if FAILED(hr)
		return false;

	// Reset the wave file to the beginning 
	wavFile->ResetFile();

	// Read the wave file
	hr = wavFile->Read((BYTE*)pDSLockedBuffer,
		dwDSLockedBufferSize,
		&dwWavDataRead);
	// Check to make sure that this was successful
	if FAILED(hr)
		return false;

	// Check to make sure the wav file is not empty
	if (dwWavDataRead == 0)
	{
		// Wav is blank, so just fill with silence
		FillMemory((BYTE*)pDSLockedBuffer,
			dwDSLockedBufferSize,
			(BYTE)(wavFile->m_pwfx->wBitsPerSample == 8 ? 128 : 0));
	}
	else if (dwWavDataRead < dwDSLockedBufferSize)
	{
		// Don't repeat the wav file, just fill in silence 
		FillMemory((BYTE*)pDSLockedBuffer + dwWavDataRead,
			dwDSLockedBufferSize - dwWavDataRead,
			(BYTE)(wavFile->m_pwfx->wBitsPerSample == 8 ? 128 : 0));
	}

	// Unlock the buffer, we don't need it anymore.
	m_soundBuffer->Unlock(pDSLockedBuffer, dwDSLockedBufferSize, NULL, 0);

	//clean
	delete wavFile;
	return true;
}

void SoundBuffer::Play()
{
	this->m_soundBuffer->Play(0, 0, 0);
}

void SoundBuffer::PlayLoop()
{
	this->m_soundBuffer->Play(0, 0, DSBPLAY_LOOPING);
}

void SoundBuffer::Stop()
{
	this->m_soundBuffer->Stop();
}

LPDIRECTSOUNDBUFFER SoundBuffer::getSoundBuffer() {
	return m_soundBuffer;
}
SoundBuffer::~SoundBuffer()
{
	if (m_soundBuffer != NULL)
	{
		m_soundBuffer->Release();
		m_soundBuffer = NULL;
	}
}

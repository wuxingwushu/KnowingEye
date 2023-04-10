#pragma once
#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_biquadresonantfilter.h"


class SoundEffect
{
public:
	SoundEffect();
	~SoundEffect();

	void Play();
	void Pause();

	

	void PlayFile(const char* path);//读入音频文件


private:
	// Define a couple of variables
	SoLoud::Soloud soloud;  // SoLoud engine core
	SoLoud::Wav gWave;      // One wave file

	int kao;//音效ID

	SoLoud::BiquadResonantFilter gLPFilter;
};
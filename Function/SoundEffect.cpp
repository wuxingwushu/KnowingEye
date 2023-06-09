#include "SoundEffect.h"



SoundEffect::SoundEffect()
{
	// initialize SoLoud.
	soloud.init(SoLoud::Soloud::CLIP_ROUNDOFF | SoLoud::Soloud::ENABLE_VISUALIZATION);
	//soloud.setGlobalVolume(1.0);
	//soloud.setPostClipScaler(10);
}

SoundEffect::~SoundEffect()
{
	// Clean up SoLoud
	soloud.deinit();
}

void SoundEffect::Play()
{
	if (soloud.getActiveVoiceCount() > 0) {//是否在播放
		//soloud.setVolume(kao, 1.0f);//设置音量


		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::FREQUENCY, 500, 1.0f);	//设置 频率
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::BANDPASS, 1, 1.0f);		//设置 带通
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::HIGHPASS, 1, 1.0f);		//设置 高通滤波器
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::LOWPASS, 1, 1.0f);		//设置 低通滤波器
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::BOOL_PARAM, 1, 1.0f);	//设置 BOOL参数
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::FLOAT_PARAM, 1, 1.0f);	//设置 FLOAT参数
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::INT_PARAM, 1, 1.0f);		//设置 INT参数
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::RESONANCE, 1, 1.0f);		//设置 共振
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::TYPE, 1, 1.0f);			//设置 类型
		//soloud.fadeFilterParameter(kao, 0, SoLoud::BiquadResonantFilter::WET, 1, 1.0f);			//设置 潮湿的
	}
	else {
		kao = soloud.play(gWave, 1);//播放这个音频
	}
}

void SoundEffect::Pause()
{
	
	soloud.setPause(kao, 1);//暂停这个音频
	//soloud.setPauseAll(1);//暂停所有音频
}

void SoundEffect::PlayFile(const char* path)
{
	gWave.load(path); //读取音频
	gWave.setLooping(0);//这个音频开启循环播放
	//gLPFilter.setParams(SoLoud::BiquadResonantFilter::LOWPASS, 10000, 0);//开启音效
	//gWave.setFilter(0, &gLPFilter);//绑定音效
	
}

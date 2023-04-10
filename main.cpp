#include "Function/SpeechGeneration.h"
#include "Function/SoundEffect.h"
#include "Function/Tesseract.h"
#include <iostream>






int main(int argc, char* argv[])
{
	Tesseract* mTesseract = new Tesseract("chi_sim");
	mTesseract->RecognizeImage(0, 0, 1010, 380, "1.png");
	std::string textddd = mTesseract->GetText();
	textddd.erase(std::remove_if(textddd.begin(), textddd.end(), [](char ch) {return ch == ' '; }), textddd.end());
	std::cout << "图片的内容 : " << textddd << std::endl;

	SoLoud::Soloud soloud;
	SoLoud::Wav gWave;

	SpeechGeneration* mSpeechGeneration = new SpeechGeneration();

	
	/*
	* rdn:           合成音频数字发音方式
	* volume:        合成音频的音量
	* pitch:         合成音频的音调
	* speed:         合成音频对应的语速
	* voice_name:    合成发音人
	* sample_rate:   合成音频采样率
	* text_encoding: 合成文本编码格式
	*/
	const char* session_begin_params = "engine_type = local, voice_name = xiaofeng, text_encoding = UTF-8, tts_res_path = fo|res\\tts\\xiaofeng.jet;fo|res\\tts\\common.jet, sample_rate = 16000, speed = 50, volume = 50, pitch = 50, rdn = 2";
	const char* filename = "tts_sample.wav"; //合成的语音文件名称
	const char* text = textddd.c_str(); //合成文本
	
	int         ret;
	/* 文本合成 */
	printf("开始合成 ...\n");
	ret = mSpeechGeneration->text_to_speech(text, filename, session_begin_params);
	if (MSP_SUCCESS != ret)
	{
		printf("text_to_speech failed, error code: %d.\n", ret);
	}
	printf("合成完毕\n");

	SoundEffect* mSoundEffect = new SoundEffect();
	mSoundEffect->PlayFile(filename);
	mSoundEffect->Play();

	printf("按任意键退出 ...\n");
	_getch();
	

	return 0;
}

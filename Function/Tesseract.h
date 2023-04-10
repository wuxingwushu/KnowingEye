#pragma once
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class Tesseract
{
public:
	Tesseract(const char* Model);//模型
	
	~Tesseract();

	std::string RecognizeImage(l_int32 x, l_int32 y, l_int32 w, l_int32 h, const char* image);//框的位置宽高，图片路径

	std::string RecognizeImageMemory(l_int32 x, l_int32 y, l_int32 w, l_int32 h, char* data, int Width, int Heigth);//框的位置宽高，图片数据，图片大小

	std::string GetText() { return Text; }//获得识别内容

private:
	std::string Text;//识别的内容
	tesseract::TessBaseAPI* api; //Tesseract 引用
};


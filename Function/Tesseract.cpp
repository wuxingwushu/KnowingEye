#include "tesseract.h"


Tesseract::Tesseract(const char* Model)
{
    api = new tesseract::TessBaseAPI();
    if (api->Init("TessData", Model)) {//初始化， Model 是识别的模型
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
}

Tesseract::~Tesseract()
{
    api->End();
    delete api;
}

std::string Tesseract::RecognizeImage(l_int32 x, l_int32 y, l_int32 w, l_int32 h, const char* imagePath) {
    Pix* Image = pixRead(imagePath);
    BOX* region = boxCreate(x, y, w, h);
    PIX* imgCrop = pixClipRectangle(Image, region, NULL);
    api->SetImage(imgCrop);
    char* outText = api->GetUTF8Text();
    //intf("OCR output:\n%s", outText);
    Text = outText;
    boxDestroy(&region);
    pixDestroy(&imgCrop);
    pixDestroy(&Image);
    delete[] outText;
    return Text;
}

std::string Tesseract::RecognizeImageMemory(l_int32 x, l_int32 y, l_int32 w, l_int32 h, char* data, int Width, int Heigth)
{
    Pix* image = pixCreate(Width, Heigth, 32);
    image->data = new unsigned int[Width, Heigth];
    memcpy((char*)image->data, data, (Width * Heigth * 4));
    BOX* region = boxCreate(x, y, w, h);
    PIX* imgCrop = pixClipRectangle(image, region, NULL);
    api->SetImage(imgCrop);
    char* outText = api->GetUTF8Text();
    //intf("OCR output:\n%s", outText);
    Text = outText;
    boxDestroy(&region);
    pixDestroy(&imgCrop);
    pixDestroy(&image);
    delete[] outText;
    return Text;
}

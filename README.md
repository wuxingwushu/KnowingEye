# KnowingEye
> 引用的技术

+ 图片识别：[Tesseract-OCR](https://tesseract-ocr.github.io/tessdoc/Home.html)
+ 音频播放：[Soloud](http://solhsa.com/soloud/)
+ 语音生成：[MSP(TTS)](https://passport.xfyun.cn/login)

> 文件结构

```
KnowingEye
    └ Environment ┐
    │             Soloud
    │             tesseract-5.2.0-x64-windows
    │             TTS
    └ TessData ┐（tesseract 模型文件）
    │          ...
    └ Function ┐
    │          ...
    └   ...
```

> 环境构建：

> 我的使用的Environment文件下载： [百度网盘](https://pan.baidu.com/s/1HptIclC_ttfMcjlLj7RawA?pwd=trrt)

+ Tesseract-OCR
	> [vcpkg](https://github.com/microsoft/vcpkg)
	> [tesseract-ocr](https://github.com/tesseract-ocr/tesseract/tree/5.2.0)
	> 编译生成动态库 api 命令：
	> ```
	> vcpkg install tesseract:x64-windows
	> ```
#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::jericho()
{
	//타일 크기 16
	_loading->loadFrameImage("crops", "resource/jerichoImage/Crops(256,672,16,42).bmp", 256, 672, 16, 42, true, RGB(255, 0, 255));
	_loading->loadFrameImage("farmBuildings", "resource/jerichoImage/Farm Buildings(913,412).bmp", 913, 412, true, RGB(255, 0, 255));
	_loading->loadFrameImage("farmHouse", "resource/jerichoImage/Farmhouse(192,320,12,20).bmp", 192, 320, 12, 20, true, RGB(255, 0, 255));
	_loading->loadFrameImage("outdoorsSpring", "resource/jerichoImage/Outdoors Spring(400,1264,25,79).bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	_loading->loadImage("trees", "resource/jerichoImage/Trees(176,645).bmp", 176, 645, true, RGB(255, 0, 255));
	_loading->loadFrameImage("townInterior", "resource/jerichoImage/Town Interior(512,1088,32,68).bmp", 512, 1088, 32, 68, true, RGB(255, 0, 255));
	_loading->loadFrameImage("tileSample", "resource/jerichoImage/tileSample(960,960,60,60).bmp", 960, 960, 60, 60, true, RGB(255, 0, 255));
}

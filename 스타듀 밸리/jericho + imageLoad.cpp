#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::jericho()
{
	//Ÿ�� ũ�� 16
	_loading->loadFrameImage("crops", "Crops(256,672,16,42).bmp", 256, 672, 16, 42, true, RGB(255, 0, 255));
	_loading->loadFrameImage("farmBuildings", "Farm Buildings(913,412).bmp", 913, 412, true, RGB(255, 0, 255));
	_loading->loadFrameImage("farmHouse", "Farmhouse(192,320,12,20).bmp", 192, 320, 12, 20, true, RGB(255, 0, 255));
	_loading->loadFrameImage("outdoorsSpring", "Outdoors Spring(400,1264,25,79).bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	//_loading->loadFrameImage("tileSprite", "Outdoors Spring(400,1264,25,79).bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	_loading->loadImage("trees", "Trees(176,645).bmp", 176, 645, true, RGB(255, 0, 255));
	_loading->loadFrameImage("tileSample", "tileSample(960,960,60,60).bmp", 960, 960, 60, 60, true, RGB(255, 0, 255));
}

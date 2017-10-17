#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::jericho()
{
	//타일 크기 16
	IMAGEMANAGER->addFrameImage("crops", "Crops(256,672,16,42).bmp", 256, 672, 16, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("farmBuildings", "Farm Buildings(913,412).bmp", 913, 412, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("farmHouse", "Farmhouse(192,320,12,20).bmp", 192, 320, 12, 20, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("outdoorsSpring", "Outdoors Spring(400,1264,25,79) - 그림자 제거.bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tileSprite", "Outdoors Spring(400,1264,25,79).bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("trees", "Trees(176,645).bmp", 176, 645, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tileSample", "tileSample(960,960,60,60).bmp", 960, 960, 60, 60, true, RGB(255, 0, 255));
}

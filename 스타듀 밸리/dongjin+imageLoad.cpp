#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::dongjin()
{
	
	_loading->loadFrameImage("tree", "resource/���������/�����Ʒ�.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treetop", "resource/���������/������.bmp", 48, 82, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treedie", "resource/effect/����.bmp", 20700, 370, 46, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("land", "resource/���������/������.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("wetland", "resource/���������/����������.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("seed", "resource/���������/�Ĺ�1.bmp", 112, 21, 7, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("seed2", "resource/���������/�Ĺ�2.bmp", 96, 19, 6, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("seed3", "resource/���������/�Ĺ�3.bmp", 112, 24, 7, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("grass", "resource/���������/Ǯ��.bmp", 64, 64, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("stone", "resource/���������/��.bmp", 60, 60, 1, 1, true, RGB(255, 0, 255));

	_loading->loadFrameImage("seed_seed", "resource/item/��.bmp", 56, 56, 1, 1, true, RGB(255, 0, 255));

	_loading->loadImage("����", "resource/���������/����.bmp", 56, 56, true);

}
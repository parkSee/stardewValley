#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::dongjin()
{
	
	_loading->loadFrameImage("tree", "resource/���������/�����Ʒ�.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treetop", "resource/���������/������.bmp", 48, 82, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treedie", "resource/effect/����.bmp", 20700, 370, 46, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("land", "resource/���������/������.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
}
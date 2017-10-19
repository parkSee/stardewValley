#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::dongjin()
{
	
	_loading->loadFrameImage("tree", "resource/시험용파일/나무아래.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treetop", "resource/시험용파일/나무위.bmp", 48, 82, 1, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("treedie", "resource/effect/나무.bmp", 20700, 370, 46, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("land", "resource/시험용파일/경작지.bmp", 16, 16, 1, 1, true, RGB(255, 0, 255));
}
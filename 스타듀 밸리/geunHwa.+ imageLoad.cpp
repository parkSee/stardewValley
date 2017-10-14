#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::geunhwa()
{
	//¼³ÅÁ¹«¾¾¾Ñ
	_loading->loadImage("sugarRadishSeed", "resource/item/sugarRadishSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//°­³¶Äá¾¾¾Ñ
	_loading->loadImage("beanSeed", "resource/item/beanSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//ÄÃ¸®ÇÃ¶ó¿ö¾¾¾Ñ
	_loading->loadImage("cauliFlowerSeed", "resource/item/cauliFlowerSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//°¨ÀÚ¾¾¾Ñ
	_loading->loadImage("potatoSeed", "resource/item/potatoSeed.bmp", 56, 56, true, RGB(255, 0, 255));

}
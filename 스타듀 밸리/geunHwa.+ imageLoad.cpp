#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::geunhwa()
{
	//����������
	_loading->loadImage("sugarRadishSeed", "resource/item/sugarRadishSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//�����ι��
	_loading->loadImage("beanSeed", "resource/item/beanSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//�ø��ö������
	_loading->loadImage("cauliFlowerSeed", "resource/item/cauliFlowerSeed.bmp", 56, 56, true, RGB(255, 0, 255));
	//���ھ���
	_loading->loadImage("potatoSeed", "resource/item/potatoSeed.bmp", 56, 56, true, RGB(255, 0, 255));

}
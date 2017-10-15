#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::soonwoo()
{
	//================================= UI �̹����� ============================================================
	//���콺 Ŀ�� �̹��� 
	_loading->loadFrameImage("mouse", "resource/UI/mouse.bmp", 66, 41, 2,1,true, RGB(255, 0, 255));
	_loading->loadFrameImage("selectMouse", "resource/UI/selectMouse.bmp",82,41,2,1, true, RGB(255, 0, 255));
	//���� ����
	_loading->loadImage("blackBox", "resource/UI/fadeOut.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//��ȭâ ������ �̹��� 
	_loading->loadImage("tokeWindow", "resource/UI/tokeWindow.bmp", 1000, 350, true, RGB(255, 0, 255));
	//��ȭâ �� �̹���
	_loading->loadImage("txtWindowBall", "resource/UI/txtWindowBall.bmp", 28, 28, true, RGB(255, 0, 255));
	//��ȭâ ������ ��ư �̹��� 
	_loading->loadFrameImage("exit", "resource/UI/exit.bmp", 408, 47, 8, 1, true, RGB(255, 0, 255));
	//�Ƿ�(pierre )UI �̹��� �ε�
	_loading->loadImage("pierreProfile", "resource/UI/pierreProfile.bmp", 74, 74, true, RGB(255, 0, 255));
	_loading->loadImage("pierreScroll", "resource/UI/pierreScroll.bmp", 320, 70, true, RGB(255, 0, 255));
	//ĳ�Ѷ���(caroline) UI �̹��� �ε�
	_loading->loadImage("carolineProfile", "resource/UI/carolineProfile.bmp", 74, 74, true, RGB(255, 0, 255));
	_loading->loadImage("carolineScroll", "resource/UI/carolineScroll.bmp", 320, 70, true, RGB(255, 0, 255));
	//���� ���� �̹��� 
	_loading->loadImage("letter", "resource/UI/letter.bmp", 1000, 733, true, RGB(255, 0, 255));
	_loading->loadImage("exit2", "resource/UI/exit2.bmp", 44, 44, true, RGB(255, 0, 255));
	//�ۺ� UI �̹���
	_loading->loadImage("publicUI", "resource/UI/publicUI.bmp", 611, 112, true, RGB(255, 0, 255));
	_loading->loadImage("getItemUI", "resource/UI/getItemUI.bmp", 188, 96, true, RGB(255, 0, 255));
	//�ð� ������ �̹��� 
	_loading->loadImage("timeWindow", "resource/UI/timeWindow.bmp", 288, 236, true, RGB(255, 0, 255));
	_loading->loadFrameImage("timePointer", "resource/UI/timePointer.bmp", 672, 151,7,1, true, RGB(255, 0, 255));

	//===============================�κ��丮 �� ������ �̹�����================================================
	//�����κ��丮 â �̹���
	_loading->loadImage("mainInven1", "resource/UI/mainInven1.bmp", 859, 588, true, RGB(255, 0, 255));
	//���� �κ��丮 �̹���
	_loading->loadImage("subInventory", "resource/UI/mainInventory.bmp", 800, 95, true, RGB(255, 0, 255));
	//������ ������ �̹�����
	_loading->loadImage("����", "resource/item/axe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("����", "resource/item/hoe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("���", "resource/item/pixHoe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("��", "resource/item/sickle.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("���Ѹ���", "resource/item/watering.bmp", 56, 56, true);
	_loading->loadImage("��", "resource/item/sword.bmp", 56, 56, true);


	//�κ��丮 ���� â �̹���
	_loading->loadImage("explainUI", "resource/UI/explainUI.bmp", 258, 233, true, RGB(255, 0, 255));

	
}
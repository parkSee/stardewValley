#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::seeyoung()
{

	//초기화
	_loading->loadFrameImage("player", "resource/player/플레이어.bmp", 3000, 3750, 12, 15, true, RGB(255, 0, 255));

	//애니메이션
	/*
	//앞뒤좌우
	int stand[] = { 20 };
	KEYANIMANAGER->addArrayFrameAnimation("playerStand", "player", stand, 1,0, false);

	int standLeft[] = { 6 };
	KEYANIMANAGER->addArrayFrameAnimation("leftStand", "player", standLeft, 1, 0, false);

	int standRight[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("rightStand", "player", standRight, 1, 0, false);

	int standBack[] = { 20 };
	KEYANIMANAGER->addArrayFrameAnimation("backStand", "player", standBack, 1, 0, false);

	//앞뒤좌우 움직임
	int left[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeft", "player", left, 6, 10, true);

	int up[] = { 12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUp", "player", up, 8, 10, true);

	int right[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRight", "player", right, 6, 10, true);

	int down[] = { 20,21,22,23,24,25,26 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDown", "player", down, 7, 10, true);

	//도끼
	int axeLeft[] = { 38,39,40,41,42 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeLeft", "player", axeLeft, 5, 10, true);

	int axeUp[] = { 43,44,45,46 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeUp", "player", axeUp, 4, 10, true);

	int axeRight[] = { 33,34,35,36,37 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeRight", "player", axeRight, 5, 10, true);

	int axeDown[] = { 27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeDown", "player", axeDown, 6, 10, true);

	//괭이
	int hoeLeft[] = { 60,61,62,63,64 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeLeft", "player", hoeLeft, 5, 10, true);

	int hoeUp[] = { 51,52,53,54 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeUp", "player", hoeUp, 4, 10, true);

	int hoeRight[] = { 55,56,57,58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeRight", "player", hoeRight, 5, 10, true);

	int hoeDown[] = { 48,49,50 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeDown", "player", hoeDown, 3, 10, true);

	//낫
	int sickleLeft[] = { 78,79,80,81,82,83 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleLeft", "player", sickleLeft, 6, 10, true);

	int sickleUp[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleUp", "player", sickleUp, 6, 10, true);

	int sickleRight[] = { 72,73,74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleRight", "player", sickleRight, 6, 10, true);

	int sickleDown[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleDown", "player", sickleDown, 6, 10, true);

	//물뿌리개
	int waterLeft[] = { 108,109,110,111,112 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterLeft", "player", waterLeft, 5, 10, true);

	int waterUp[] = { 113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterUp", "player", waterUp, 3, 10, true);

	int waterRight[] = { 90,91,92,93,94 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterRight", "player", waterRight, 5, 10, true);

	int waterDown[] = { 96,97,98,99,100,101,102,103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterDown", "player", waterDown, 12, 10, true);

	//아이템들기
	int takeLeft[] = { 120,121,122,123,124 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeLeft", "player", takeLeft, 5, 10, true);

	int takeUp[] = { 131,132,133,134,135,136 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeUp", "player", takeUp, 6, 10, true);

	int takeRight[] = { 125,126,127,128,129 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeRight", "player", takeRight, 5, 10, true);

	int takeDown[] = { 116,130,138,139,140,141,142 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeDown", "player", takeDown, 7, 10, true);
	*/
}
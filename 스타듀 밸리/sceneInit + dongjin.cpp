#include "stdafx.h"
#include "townScene.h"
#include "tree1.h"
#include "land.h"
#include "seed.h"
#include "seed2.h"
#include "seed3.h"
#include "grass.h"
#include "stone.h"

void townScene::dongjinInit()
{
	tree1* temp = new tree1;
	temp->init(tagFloat(TOWNWORLD->getTile(4, 10)->getRect().left, TOWNWORLD->getTile(4, 10)->getRect().top));

	EFFECTMANAGER->addEffect("die", "resource/effect/나무.bmp", 20700, 370, 450, 370, 1.0f, 0.4f, 1000);
	EFFECTMANAGER->addEffect("bottom_die", "resource/effect/나무밑.bmp", 5301, 231, 279, 231, 1.0f, 0.6f, 1000);
		

	grass* tlqkf = new grass;
	tlqkf->init(tagFloat(TOWNWORLD->getTile(10, 2)->getRect().left, TOWNWORLD->getTile(10, 2)->getRect().top));

	EFFECTMANAGER->addEffect("grassDie", "resource/effect/풀때기.bmp", 500, 137, 100, 137, 1.0f, 0.3f, 1000);

	stone* _stone = new stone;
	_stone->init(tagFloat(TOWNWORLD->getTile(3, 2)->getRect().left, TOWNWORLD->getTile(3, 2)->getRect().top));

	EFFECTMANAGER->addEffect("stoneDie", "resource/effect/돌시발.bmp", 4400, 120, 200, 120, 1.0f, 0.7f, 1000);
	//tree1 탑이랑 바텀 이닛에서 스스로 타운월드에 집어넣는다
}
#include "stdafx.h"
#include "townScene.h"
#include "tree1.h"
#include "land.h"
#include "seed.h"
#include "grass.h"

void townScene::dongjinInit()
{
	tree1* temp = new tree1;
	temp->init(tagFloat(TOWNWORLD->getTile(4, 10)->getRect().left, TOWNWORLD->getTile(4, 10)->getRect().top));

	EFFECTMANAGER->addEffect("die", "resource/effect/나무.bmp", 20700, 370, 450, 370, 1.0f, 0.4f, 1000);

	land* stom = new land;
	stom->init(tagFloat(TOWNWORLD->getTile(4, 2)->getRect().left, TOWNWORLD->getTile(4, 2)->getRect().top));

	seed* sour = new seed;
	sour->init("seed", "seed", (tagFloat(TOWNWORLD->getTile(8, 2)->getRect().left, TOWNWORLD->getTile(8, 2)->getRect().top)));

	grass* tlqkf = new grass;
	tlqkf->init(tagFloat(TOWNWORLD->getTile(10, 2)->getRect().left, TOWNWORLD->getTile(10, 2)->getRect().top));

	EFFECTMANAGER->addEffect("grassDie", "resource/effect/풀때기.bmp", 500, 137, 100, 137, 1.0f, 0.3f, 1000);
	//tree1 탑이랑 바텀 이닛에서 스스로 타운월드에 집어넣는다
}
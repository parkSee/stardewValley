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

	EFFECTMANAGER->addEffect("die", "resource/effect/����.bmp", 20700, 370, 450, 370, 1.0f, 0.4f, 1000);
	EFFECTMANAGER->addEffect("bottom_die", "resource/effect/������.bmp", 5301, 231, 279, 231, 1.0f, 0.6f, 1000);
		
	land* stom = new land;
	stom->init(tagFloat(TOWNWORLD->getTile(4, 2)->getRect().left, TOWNWORLD->getTile(4, 2)->getRect().top));



	grass* tlqkf = new grass;
	tlqkf->init(tagFloat(TOWNWORLD->getTile(10, 2)->getRect().left, TOWNWORLD->getTile(10, 2)->getRect().top));

	EFFECTMANAGER->addEffect("grassDie", "resource/effect/Ǯ����.bmp", 500, 137, 100, 137, 1.0f, 0.3f, 1000);

	stone* _stone = new stone;
	_stone->init(tagFloat(TOWNWORLD->getTile(3, 2)->getRect().left, TOWNWORLD->getTile(3, 2)->getRect().top));

	EFFECTMANAGER->addEffect("stoneDie", "resource/effect/���ù�.bmp", 4400, 120, 200, 120, 1.0f, 0.7f, 1000);
	//tree1 ž�̶� ���� �̴ֿ��� ������ Ÿ����忡 ����ִ´�
}
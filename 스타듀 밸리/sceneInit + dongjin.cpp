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
	temp->init(tagFloat(TOWNWORLD->getTile(14, 18)->getRect().left, TOWNWORLD->getTile(14, 18)->getRect().top));

	tree1* temp1 = new tree1;
	temp1->init(tagFloat(TOWNWORLD->getTile(20, 22)->getRect().left, TOWNWORLD->getTile(20, 22)->getRect().top));

	

	tree1* temp3 = new tree1;
	temp3->init(tagFloat(TOWNWORLD->getTile(30, 23)->getRect().left, TOWNWORLD->getTile(30, 23)->getRect().top));

	tree1* temp4 = new tree1;
	temp4->init(tagFloat(TOWNWORLD->getTile(36, 10)->getRect().left, TOWNWORLD->getTile(36, 10)->getRect().top));

	tree1* temp5 = new tree1;
	temp5->init(tagFloat(TOWNWORLD->getTile(36, 22)->getRect().left, TOWNWORLD->getTile(36, 22)->getRect().top));
	
	tree1* temp6 = new tree1;
	temp6->init(tagFloat(TOWNWORLD->getTile(40, 10)->getRect().left, TOWNWORLD->getTile(40, 10)->getRect().top));
	
	
	
	tree1* temp8 = new tree1;
	temp8->init(tagFloat(TOWNWORLD->getTile(43, 18)->getRect().left, TOWNWORLD->getTile(43, 18)->getRect().top));


	//tree1* temp5 = new tree1;
	//temp5->init(tagFloat(TOWNWORLD->getTile(100, 10)->getRect().left, TOWNWORLD->getTile(100, 10)->getRect().top));
	//
	//tree1* temp6 = new tree1;
	//temp6->init(tagFloat(TOWNWORLD->getTile(120, 30)->getRect().left, TOWNWORLD->getTile(120, 30)->getRect().top));

	EFFECTMANAGER->addEffect("die", "resource/effect/나무.bmp", 20700, 370, 450, 370, 1.0f, 0.4f, 1000);
	EFFECTMANAGER->addEffect("bottom_die", "resource/effect/나무밑.bmp", 5301, 231, 279, 231, 1.0f, 0.6f, 1000);
		

	grass* _grass = new grass;
	_grass->init(tagFloat(TOWNWORLD->getTile(23, 25)->getRect().left, TOWNWORLD->getTile(23, 25)->getRect().top));

	grass* _grass2 = new grass;
	_grass2->init(tagFloat(TOWNWORLD->getTile(32, 24)->getRect().left, TOWNWORLD->getTile(32, 24)->getRect().top));
	
	grass* _grass3 = new grass;
	_grass3->init(tagFloat(TOWNWORLD->getTile(39, 18)->getRect().left, TOWNWORLD->getTile(39, 18)->getRect().top));
	
	grass* _grass4 = new grass;
	_grass4->init(tagFloat(TOWNWORLD->getTile(36, 30)->getRect().left, TOWNWORLD->getTile(36, 30)->getRect().top));
	
	grass* _grass5 = new grass;
	_grass5->init(tagFloat(TOWNWORLD->getTile(19, 22)->getRect().left, TOWNWORLD->getTile(19, 22)->getRect().top));
	
	grass* _grass6 = new grass;
	_grass6->init(tagFloat(TOWNWORLD->getTile(22, 29)->getRect().left, TOWNWORLD->getTile(22, 29)->getRect().top));
	
	grass* _grass7 = new grass;
	_grass7->init(tagFloat(TOWNWORLD->getTile(19, 24)->getRect().left, TOWNWORLD->getTile(19, 24)->getRect().top));
	
	grass* _grass8 = new grass;
	_grass8->init(tagFloat(TOWNWORLD->getTile(25, 26)->getRect().left, TOWNWORLD->getTile(25, 26)->getRect().top));

	EFFECTMANAGER->addEffect("grassDie", "resource/effect/풀때기.bmp", 500, 137, 100, 137, 1.0f, 0.3f, 1000);

	stone* _stone = new stone;
	_stone->init(tagFloat(TOWNWORLD->getTile(19, 23)->getRect().left, TOWNWORLD->getTile(19, 23)->getRect().top));

	stone* _stone2 = new stone;
	_stone2->init(tagFloat(TOWNWORLD->getTile(20, 30)->getRect().left, TOWNWORLD->getTile(20, 30)->getRect().top));

	stone* _stone3 = new stone;
	_stone3->init(tagFloat(TOWNWORLD->getTile(25, 25)->getRect().left, TOWNWORLD->getTile(25, 25)->getRect().top));

	stone* _stone4 = new stone;
	_stone4->init(tagFloat(TOWNWORLD->getTile(40,18)->getRect().left, TOWNWORLD->getTile(40, 18)->getRect().top));

	stone* _stone5 = new stone;
	_stone5->init(tagFloat(TOWNWORLD->getTile(36, 23)->getRect().left, TOWNWORLD->getTile(36, 23)->getRect().top));

	stone* _stone6 = new stone;
	_stone6->init(tagFloat(TOWNWORLD->getTile(17, 23)->getRect().left, TOWNWORLD->getTile(17, 23)->getRect().top));

	stone* _stone7 = new stone;
	_stone7->init(tagFloat(TOWNWORLD->getTile(33, 19)->getRect().left, TOWNWORLD->getTile(33, 19)->getRect().top));

	stone* _stone8 = new stone;
	_stone8->init(tagFloat(TOWNWORLD->getTile(38, 28)->getRect().left, TOWNWORLD->getTile(38, 28)->getRect().top));

	stone* _stone9 = new stone;
	_stone9->init(tagFloat(TOWNWORLD->getTile(34, 30)->getRect().left, TOWNWORLD->getTile(34, 30)->getRect().top));

	stone* _stone10 = new stone;
	_stone10->init(tagFloat(TOWNWORLD->getTile(53, 25)->getRect().left, TOWNWORLD->getTile(53, 25)->getRect().top));

	stone* _stone11 = new stone;
	_stone11->init(tagFloat(TOWNWORLD->getTile(37, 27)->getRect().left, TOWNWORLD->getTile(37, 27)->getRect().top));

	EFFECTMANAGER->addEffect("stoneDie", "resource/effect/돌시발.bmp", 4400, 120, 200, 120, 1.0f, 0.7f, 1000);
	//tree1 탑이랑 바텀 이닛에서 스스로 타운월드에 집어넣는다
}
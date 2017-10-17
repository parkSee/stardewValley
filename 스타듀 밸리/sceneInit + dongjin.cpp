#include "stdafx.h"
#include "townScene.h"
#include "tree1.h"

void townScene::dongjinInit()
{
	tree1* temp = new tree1;
	temp->init(tagFloat(TOWNWORLD->getTile(4, 10)->getRect().left, TOWNWORLD->getTile(4, 10)->getRect().top));
	//tree1 탑이랑 바텀 이닛에서 스스로 타운월드에 집어넣는다
}
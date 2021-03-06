#include "stdafx.h"
#include "townScene.h"

#include "UI.h"
#include "mouse.h"
#include "publicUI.h"
#include "inventory.h"
#include "dropItem.h"
#include "eProgressBar.h"
#include "pierre.h"
#include "weather.h"
#include "caroline.h"
#include "selectUI.h"
#include "house.h"
#include "createUI.h"
#include "fade.h"

void townScene::soonwooInit()
{
	UI* uiManager = new UI;
	uiManager->init("UI");
	TOWNWORLD->addObject(objectType::INTERFACE, uiManager);

	mouse* mouseManager = new mouse;
	mouseManager->init("mouse");
	TOWNWORLD->addObject(objectType::MOUSE, mouseManager);

	publicUI* publicUi = new publicUI;
	publicUi->init("publicUI");
	TOWNWORLD->addObject(objectType::INTERFACE, publicUi);

	inventory* inven = new inventory;
	inven->init("inventory");
	TOWNWORLD->addObject(objectType::INTERFACE, inven);

	dropItem* item = new dropItem;
	item->init("���Ѹ���", "�����̵� �� �� �ִ�.",tagFloat(300,300));
	TOWNWORLD->addObject(objectType::ITEM, item);

	dropItem* item2 = new dropItem;
	item2->init("����", "�������� ���� ������ ��ä",tagFloat(700, 700));
	TOWNWORLD->addObject(objectType::ITEM, item2);

	for (int i = 0; i < 5; i++)
	{
		dropItem* item3 = new dropItem;
		item3->init("����", "������ �ʹ�, ���� �;� . . ,", tagFloat(1000 +10*RND->getInt(30), 1300+10* RND->getInt(30)));
		TOWNWORLD->addObject(objectType::ITEM, item3);
	}

	dropItem* item4 = new dropItem;
	item4->init("��پ���", "���� ������ �Ѹ��� ��Ȯ�� �� �ִ�.", tagFloat(600, 200));
	TOWNWORLD->addObject(objectType::ITEM, item4);

	dropItem* item3 = new dropItem;
	item3->init("���", "���ְڴ�.......", tagFloat(600,200));
	TOWNWORLD->addObject(objectType::ITEM, item3);

	eProgressBar* energy = new eProgressBar;
	energy->init("energyBar");
	TOWNWORLD->addObject(objectType::INTERFACE, energy);

	pierre*	storeNpc = new pierre;
	storeNpc->init("pierre", "pierre", tagFloat(800, 1000));
	TOWNWORLD->addObject(objectType::HUMAN, storeNpc);

	weather* day = new weather;
	day->init("weather");
	TOWNWORLD->addObject(objectType::WEATHER, day);

	caroline* carolineNpc = new caroline;
	carolineNpc->init("caroline", "caroline", tagFloat(900, 600));
	TOWNWORLD->addObject(objectType::HUMAN, carolineNpc);

	selectUI*select = new selectUI;
	select->init("selectUI");
	TOWNWORLD->addObject(objectType::INTERFACE, select);

	house* home = new house;
	home->init("house", "house", tagFloat((TILESIZE * 19) +(89*SCALE), (TILESIZE * 7) +(67*SCALE)));
	TOWNWORLD->addObject(objectType::OBJ, home);

	createUI* createui = new createUI;
	createui->init("createUI");
	TOWNWORLD->addObject(objectType::INTERFACE, createui);

	fade* fadeOut = new fade;
	fadeOut->init("fade");
	TOWNWORLD->addObject(objectType::WEATHER, fadeOut);
	
}
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
	item->init("물뿌리개", "무엇이든 벨 수 있다.",tagFloat(300,300));
	TOWNWORLD->addObject(objectType::ITEM, item);

	dropItem* item2 = new dropItem;
	item2->init("수액", "나무에서 나온 끈적앤 액채",tagFloat(700, 700));
	TOWNWORLD->addObject(objectType::ITEM, item2);

	for (int i = 0; i < 30; i++)
	{
		dropItem* item3 = new dropItem;
		item3->init("나무", "집가고 싶다, 쉬고 싶어 . . ,", tagFloat(1000 +10*RND->getInt(30), 500+10* RND->getInt(30)));
		TOWNWORLD->addObject(objectType::ITEM, item3);
	}

	dropItem* item3 = new dropItem;
	item3->init("사람", "맛있겠닭.......", tagFloat(600,200));
	TOWNWORLD->addObject(objectType::ITEM, item3);

	eProgressBar* energy = new eProgressBar;
	energy->init("energyBar");
	TOWNWORLD->addObject(objectType::INTERFACE, energy);

	pierre*	storeNpc = new pierre;
	storeNpc->init("pierre", "pierre", tagFloat(480, 500));
	TOWNWORLD->addObject(objectType::HUMAN, storeNpc);

	weather* day = new weather;
	day->init("weather");
	TOWNWORLD->addObject(objectType::WEATHER, day);

	caroline* carolineNpc = new caroline;
	carolineNpc->init("caroline", "caroline", tagFloat(800, 300));
	TOWNWORLD->addObject(objectType::HUMAN, carolineNpc);

	selectUI*select = new selectUI;
	select->init("selectUI");
	TOWNWORLD->addObject(objectType::INTERFACE, select);

	house* home = new house;
	home->init("house", "house", tagFloat((TILESIZE * 9) +(89*SCALE), (TILESIZE * 9) +(67*SCALE)));
	TOWNWORLD->addObject(objectType::OBJ, home);

	createUI* createui = new createUI;
	createui->init("createUI");
	TOWNWORLD->addObject(objectType::INTERFACE, createui);
	
}
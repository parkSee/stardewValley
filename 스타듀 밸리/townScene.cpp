#include "stdafx.h"
#include "townScene.h"

//������Ʈ Ŭ������ ��� �ޱ� 
#include "UI.h"
#include "mouse.h"
#include "publicUI.h"

HRESULT townScene::init()
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


	return S_OK;
}

void townScene::release()
{

}

void townScene::update()
{
	

	TOWNWORLD->update();
}

void townScene::render()
{
	TOWNWORLD->render();
}
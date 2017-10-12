#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	_btnSceneChange->init("º¸Æ°", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	_action = new action;
	_action->init();

	_actionTest = IMAGEMANAGER->findImage("bullet");
	_actionTest->setX(WINSIZEX / 2);
	_actionTest->setY(WINSIZEY / 2);

	_action->moveTo(_actionTest, WINSIZEX / 2, 50, 8.0f, cbAction);

	testAction = _action;
	actionImage = _actionTest;

	_btnAngleUp = new button;
	_btnAngleUp->init("º¸Æ°", WINSIZEX / 2 - 200, WINSIZEY / 2 - 200,
		PointMake(0, 1), PointMake(0, 0), cbAngleUp);

	_btnAngleDown = new button;
	_btnAngleDown->init("º¸Æ°", WINSIZEX / 2 + 200, WINSIZEY / 2 - 200,
		PointMake(0, 1), PointMake(0, 0), cbAngleDown);

	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	_btnSceneChange->update();
	_action->update();
	_btnAngleDown->update();
	_btnAngleUp->update();
}

void selectScene::render() 
{
	_btnSceneChange->render();
	_btnAngleDown->render();
	_btnAngleUp->render();

	char str[128];

	sprintf(str, "¼¿·ºÆ® ¾À");
	TextOut(getMemDC(), WINSIZEX / 2 - 200, WINSIZEY / 2, str, strlen(str));


	_actionTest->render(getMemDC());
}

void selectScene::cbSceneChange(void)
{
	SCENEMANAGER->changeScene("½ºÅ¸¾À");
}

void selectScene::cbAction(void)
{
	testAction->moveTo(actionImage, WINSIZEX / 2, WINSIZEY / 2 + 100, 3.0f);
}

void selectScene::cbAngleUp(void)
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->accelaration += 0.2f);
}

void selectScene::cbAngleDown(void)
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->accelaration -= 0.2f);
}
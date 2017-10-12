#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{

}


playGround::~playGround()
{

}

HRESULT playGround::init(void)
{
	gameNode::init(true);

	SCENEMANAGER->addLoadingScene("�ε���", new loadingScene);
	SCENEMANAGER->addScene("������", new townScene);

	SCENEMANAGER->changeScene("�ε���");
	
    ShowCursor(false);

	return S_OK;
}

void playGround::release(void)
{
	gameNode::release();

	SCENEMANAGER->release();
}

void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

	
}

void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	SCENEMANAGER->render();
	
	//TIMEMANAGER->render(getMemDC());

	//=================== �� �� �� �� ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

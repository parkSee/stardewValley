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

	SCENEMANAGER->addLoadingScene("·Îµù¾À", new loadingScene);
	SCENEMANAGER->addScene("¸¶À»¾À", new townScene);

	SCENEMANAGER->changeScene("·Îµù¾À");
	
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

	//=================== ¼Õ ´ë Áö ¸¶ ===================
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

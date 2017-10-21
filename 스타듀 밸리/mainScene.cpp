#include "stdafx.h"
#include "mainScene.h"


mainScene::mainScene()
{
}


mainScene::~mainScene()
{

}


HRESULT mainScene::init()
{
	IMAGEMANAGER->addImage("backGround", "resource/UI/backGround.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("title", "resource/UI/title.bmp", 700, 400, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("newButton", "resource/UI/newButton.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mapButton", "resource/UI/mapButton.bmp", 300, 150, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mouse", "resource/UI/mouse.bmp", 66, 41, 2, 1, true, RGB(255, 0, 255));
	
	_mouse = IMAGEMANAGER->findImage("mouse");

	_backGround = IMAGEMANAGER->findImage("backGround");

	_title = IMAGEMANAGER->findImage("title");


	_new.img = IMAGEMANAGER->findImage("newButton");
	_new.pos.x = WINSIZEX / 2 - _new.img->getWidth();
	_new.pos.y = WINSIZEY - 250;
	_new.rc = RectMake(_new.pos.x, _new.pos.y, _new.img->getWidth(), _new.img->getHeight());

	_map.img = IMAGEMANAGER->findImage("mapButton");
	_map.pos.x = _new.rc.right + 50;
	_map.pos.y = _new.pos.y;
	_map.rc = RectMake(_map.pos.x, _map.pos.y, _map.img->getWidth(), _map.img->getHeight());
	
	SOUNDMANAGER->play("bgm1", 1.0f);

	return S_OK;
}

void mainScene::release()
{

}

void mainScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_map.rc, _ptMouse))
		{
			SCENEMANAGER->changeScene("¸ÊÅø¾À");
		}
		if (PtInRect(&_new.rc, _ptMouse))
		{
			SCENEMANAGER->changeScene("¸¶À»¾À");
		}
	}


}

void mainScene::render() 
{
	_backGround->render(getMemDC(), 0, 0);

	_title->render(getMemDC(), WINSIZEX / 2 - _title->getWidth() / 2 + 15, 70);

	_new.img->render(getMemDC(), _new.rc.left, _new.rc.top);

	_map.img->render(getMemDC(), _map.rc.left, _map.rc.top);

	_mouse->frameRender(getMemDC(), _ptMouse.x, _ptMouse.y,0,0);
}



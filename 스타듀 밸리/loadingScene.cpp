#include "stdafx.h"
#include "loadingScene.h"


HRESULT loadingScene::init()
{
	_loading = new loading;
	_loading->init();

	//ÆÄÀÏ ·ÎµùÇÏ±â 
	char image[100];
	for (int i = 0; i < 10; i++)
	{
		memset(image, 0, sizeof(image));
		sprintf(image, "mainInventory%d", i);
		_loading->loadImage(image,"resource/UI/mainInventory.bmp" ,800,95,true,RGB(255,0,255));
	}

	this->dongjin();
	this->seeyoung();
	this->geunhwa();
	this->soonwoo();
	this->jericho();
	this->youngjae();


	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loading);
}

void loadingScene::update()
{
	_loading->update();

	if (_loading->loadingDone())
	{
		SCENEMANAGER->changeScene("¸ŞÀÎ¾À");
		//ShowCursor(true);
		//SCENEMANAGER->changeScene("¸ÊÅø¾À");
	}

}

void loadingScene::render()
{
	_loading->render();

}



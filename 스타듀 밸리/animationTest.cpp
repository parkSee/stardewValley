#include "stdafx.h"
#include "animationTest.h"


animationTest::animationTest()
{
}


animationTest::~animationTest()
{

}

HRESULT animationTest::init()
{
	_camel = IMAGEMANAGER->addFrameImage("나윽타", "camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));

	//디폴트 애니메이숀
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani1->setDefPlayFrame(true, true);
	_ani1->setFPS(1);
	//배열 애니메이숀
	int arrAni[] = { 0, 1, 2, 4, 2, 1, 3 };
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani2->setPlayFrame(arrAni, 7, false);
	_ani2->setFPS(1);
	//구간 애니메이숀
	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani3->setPlayFrame(2, 8, true, false);
	_ani3->setFPS(1);

	return S_OK;
}

void animationTest::release()
{

}

void animationTest::update() 
{

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_ani1->start();
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_ani2->start();
	}

	if (KEYMANAGER->isOnceKeyDown('E')) _ani3->start();



	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}

void animationTest::render() 
{

	_camel->aniRender(getMemDC(), 100, 200, _ani1);
	_camel->aniRender(getMemDC(), 200, 200, _ani2);
	_camel->aniRender(getMemDC(), 300, 200, _ani3);
}

#include "stdafx.h"
#include "shadow.h"


HRESULT shadow::init(string objectName, string imagKeyName, tagFloat pos)
{

	gameObject::init(objectName, imagKeyName, tagFloat(pos));

	_shadow.img = IMAGEMANAGER->findImage("shadow");
	_shadow.ani = new animation;
	_shadow.ani->init(_shadow.img->getWidth(), _shadow.img->getHeight(), _shadow.img->getFrameWidth(), _shadow.img->getFrameHeight());
	_shadow.ani->setPlayFrame(0, 1, false , true);
	_shadow.ani->setFPS(1);
	_shadow.ani->start();
	_shadow.rc = RectMakeCenter(_pos.x, _pos.y, _shadow.img->getFrameWidth(),_shadow.img->getFrameHeight());

	_alpha = 90;

	return S_OK;
}
void shadow::release()
{
	gameObject::release();

}
void shadow::update() 
{
	gameObject::update();
	_shadow.ani->frameUpdate(TIMEMANAGER->getElapsedTime());
	_shadow.rc = RectMakeCenter(_pos.x , _pos.y, _shadow.img->getFrameWidth(), _shadow.img->getFrameHeight());

}
void shadow::render() 
{
	//gameObject::render();
	RECT rc = CAMERAMANAGER->getRenderRc();
	_shadow.img->alphaAniRender(getMemDC(), _shadow.rc.left - rc.left, _shadow.rc.top-rc.top, _shadow.ani,_alpha);
	

}

void shadow::startAni()
{
	_shadow.ani->start();
}

void shadow::stopAni()
{
	_shadow.ani->stop();
}

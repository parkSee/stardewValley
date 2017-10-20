#include "stdafx.h"
#include "shadow.h"


HRESULT shadow::init(string objectName, string imagKeyName, tagFloat pos)
{

	gameObject::init(objectName, imagKeyName, tagFloat(pos));

	_shadow.img = IMAGEMANAGER->findImage("shadow");
	_shadow.ani = new animation;
	_shadow.ani->init(_shadow.img->getWidth(), _shadow.img->getHeight(), _shadow.img->getFrameWidth(), _shadow.img->getFrameHeight());
	_shadow.ani->setDefPlayFrame(false,true);
	_shadow.ani->setFPS(1);
	//_shadow.ani->start();
	_shadow.rc = RectMakeCenter(_pos.x, _pos.y, _shadow.img->getFrameWidth(),_shadow.img->getFrameHeight());
	_shadow.ani->start();
	_isChange = false;
	_scale = 1.0f;
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
	
	_shadow.rc = RectMakeCenter(_pos.x , _pos.y, _shadow.img->getFrameWidth(), _shadow.img->getFrameHeight());
	
	//_shadow.ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	
	//if (_isChange)_scale += 0.03;
	//if (!_isChange)_scale -= 0.03f;
	//if (_scale >= 1.3)_isChange = false;
	//if (_scale <= 0.7)_isChange = true;

}
void shadow::render() 
{
	//gameObject::render();
	RECT rc = CAMERAMANAGER->getRenderRc();
	_shadow.img->alphaScaleAniRender(getMemDC(), _shadow.rc.left - rc.left, _shadow.rc.top-rc.top, _shadow.ani,
		_shadow.img->getFrameWidth() * _scale, _shadow.img->getFrameHeight() * _scale,_alpha);
	

}


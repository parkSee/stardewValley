#include "stdafx.h"
#include "house.h"

HRESULT house::init(string name, string imageKey, tagFloat pos)
{
	motherObject::init(name, imageKey, pos);

	_rc = RectMake(_pos.x, _pos.y, _image->getWidth() * SCALE, _image->getHeight()*SCALE);

	return S_OK;
}

void house::release()
{
	motherObject::release();
}

void house::update() 
{
	motherObject::update();
}

void house::render() 
{
	RECT rc = CAMERAMANAGER->getRenderRc();
	_image->scaleRender(getMemDC(), _rc.left-rc.left ,_rc.top-rc.top, _image->getWidth()*SCALE, _image->getHeight()*SCALE);
}

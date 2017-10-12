#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{

}

HRESULT enemy::init(void)
{
	return S_OK;
}

HRESULT enemy::init(const char* imageName, POINT position)
{
	_currentFrameX = _currentFrameY = 0;
	_count = _fireCount = 0;

	_rndFireCount = RND->getFromIntTo(1, 1000);

	_imageName = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(position.x, position.y,
		_imageName->getFrameWidth(),
		_imageName->getFrameHeight());

	return S_OK;
}

void enemy::release(void)
{

}

void enemy::update(void) 
{

	_count++;

	if (_count % 2 == 0)
	{
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0;

		_count = 0;
	}


}

void enemy::render(void) 
{
	draw();
}


void enemy::move(void)
{

}

void enemy::draw(void)
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}


bool enemy::bulletCountFire(void)
{
	_fireCount++;

	if (_fireCount % _rndFireCount == 0)
	{
		_fireCount = 0;
		_rndFireCount = RND->getFromIntTo(1, 1000);

		return true;
	}

	return false;
}

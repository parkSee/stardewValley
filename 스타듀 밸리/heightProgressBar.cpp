#include "stdafx.h"
#include "heightProgressBar.h"

//front의 키값, back의 키값,				bar의 x위치, bar의 y위치, bar의 길이, bar의 높이
HRESULT heightProgressBar::init(string frontBar, string backbar, int x, int y, int width, int height)
{
	gameObject::init("progressBar");

	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->findImage(frontBar);
	_progressBarBottom = IMAGEMANAGER->findImage(backbar);
	_frontimage = frontBar;
	_backimage = backbar;

	_height = height;

	return  S_OK;
}

void heightProgressBar::release()
{
	gameObject::release();


}

void heightProgressBar::update(int imagecenterX, int imagetopY, float current, float max)
{
	gameObject::update();

	_x = imagecenterX;
	_y = imagetopY;

	_rcProgress = RectMakeCenter(_x, _y,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	this->setGauge(current, max);

}

void heightProgressBar::render()
{
	_progressBarBottom->render(getMemDC(), _x - _progressBarBottom->getWidth() / 2,
		_y,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	_progressBarTop->render(getMemDC(), _x - _progressBarBottom->getWidth() / 2,
		_y,
		0, 0,
		_progressBarBottom->getWidth(), _height);

	//IMAGEMANAGER->render(_backimage, getMemDC(),
	//	_x - _progressBarBottom->getWidth() / 2,
	//	_y,
	//	0, 0,
	//	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	//
	//IMAGEMANAGER->render(_frontimage, getMemDC(),
	//	_x - _progressBarBottom->getWidth() / 2,
	//	_y,
	//	0, 0,
	//	_progressBarBottom->getWidth(), _height);
}


void heightProgressBar::setGauge(float currentGauge, float maxGauge)
{
	_height = (currentGauge / maxGauge) * _progressBarBottom->getHeight();
}


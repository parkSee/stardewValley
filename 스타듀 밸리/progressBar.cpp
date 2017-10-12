#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));

	_width = _progressBarTop->getWidth();

	return S_OK;
}

HRESULT progressBar::init(char* topImage, char* bottomImage, float x, float y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	char strTopImageName[128];
	char strBottomImageName[128];

	ZeroMemory(strTopImageName, sizeof(strTopImageName));
	ZeroMemory(strBottomImageName, sizeof(strBottomImageName));

	sprintf(strTopImageName, "%s.bmp", topImage);
	sprintf(strBottomImageName, "%s.bmp", bottomImage);

	_progressBarBottom = IMAGEMANAGER->addImage(bottomImage, strBottomImageName, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarTop = IMAGEMANAGER->addImage(topImage, strTopImageName, x, y, width, height, true, RGB(255, 0, 255));

	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
	_rcProgress = RectMakeCenter(_x, _y,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	_progeressBarRight = _rcProgress.left + _width;

}

void progressBar::render()
{
	/*
	IMAGEMANAGER->render("backBar", getMemDC(),
	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	_y + _progressBarBottom->getHeight() / 2,
	0, 0,
	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render("frontBar", getMemDC(),
	_rcProgress.left + _progressBarBottom->getWidth() / 2,
	_y + _progressBarBottom->getHeight() / 2,
	0, 0,
	_width, _progressBarBottom->getHeight());
	*/

	_progressBarBottom->render(getMemDC(), _rcProgress.left, _y, 0, 0,
		_progressBarBottom->getWidth(),
		_progressBarBottom->getHeight());

	_progressBarTop->render(getMemDC(), _rcProgress.left, _y, 0, 0,
		_width,
		_progressBarTop->getHeight());


}


void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}

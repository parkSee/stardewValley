#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
	:_width(NULL),
	_x(NULL),
	_y(NULL),
	_progressBarBottom(NULL),
	_progressBarTop(NULL)
{
}


progressBar::~progressBar()
{

}
							//front의 키값, back의 키값,		front의 파일명,		back의 파일명,		bar의 x위치, bar의 y위치, bar의 길이, bar의 높이
HRESULT progressBar::init(string frontBar, string  backBar, const char* frontfile, const char* backfile, int x, int y, int width, int height)
{ 
	_x = x;
	_y = y;

	_rcProgress = RectMakeCenter(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage(frontBar, frontfile, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage(backBar, backfile, x, y, width, height, true, RGB(255, 0, 255));
	_frontimage = frontBar;
	_backimage = backBar;

	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()									  
{

}

void progressBar::update(int imagecenterX, int imagetopY, float current, float max)
{
	_x = imagecenterX;
	_y = imagetopY;

	_rcProgress = RectMakeCenter(_x, _y,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	this->setGauge(current, max);

}
						
void progressBar::render()
{
	IMAGEMANAGER->render(_backimage, getMemDC(),
		_x -_progressBarBottom->getWidth()/2,
		_y ,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	IMAGEMANAGER->render(_frontimage, getMemDC(),
		_x - _progressBarBottom->getWidth() / 2,
		_y ,
		0, 0,
		_width, _progressBarBottom->getHeight());
}


void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}

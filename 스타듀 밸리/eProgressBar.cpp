#include "stdafx.h"
#include "eProgressBar.h"

HRESULT eProgressBar::init()
{
	_progressWindow.img = IMAGEMANAGER->findImage("energyWindow");
	_progressWindow.pos = tagFloat(WINSIZEX - 40, WINSIZEY - 150);
	_progressWindow.rc = RectMakeCenter(_progressWindow.pos.x, _progressWindow.pos.y,
		48, 244);

	_eProgressBar = new heightProgressBar;
	_eProgressBar->init("energyBackBar", "energyFrontBar", _progressWindow.pos.x, _progressWindow.pos.y, 24, 210);
	
	_playerEnergy = 0;

	return S_OK;
}
void eProgressBar::release()
{

}
void eProgressBar::update()	
{
	_eProgressBar->update(_progressWindow.pos.x, _progressWindow.pos.y -70, _playerEnergy,100);

	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		_playerEnergy += 10;
	}
}
void eProgressBar::render()	
{
	_progressWindow.img->scaleRender(getMemDC(), _progressWindow.rc.left, _progressWindow.rc.top, 48,244);
	_eProgressBar->render();
}


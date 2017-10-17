#include "stdafx.h"
#include "eProgressBar.h"

HRESULT eProgressBar::init(string name)
{
	gameObject::init(name);

	_progressWindow.img = IMAGEMANAGER->findImage("energyWindow");
	_progressWindow.pos = tagFloat(WINSIZEX - 40, WINSIZEY - 150);
	_progressWindow.rc = RectMakeCenter(_progressWindow.pos.x, _progressWindow.pos.y,
		48, 244);

	_eProgressBar = new heightProgressBar;
	_eProgressBar->init("energyBackBar", "energyFrontBar", _progressWindow.pos.x, _progressWindow.pos.y, 24, 210);
	
	_playerEnergy = 0;

	this->addCallback("consume", [this](tagMessage msg)
	{
		this->consume(msg);
	});

	return S_OK;
}
void eProgressBar::release()
{
	gameObject::release();

	SAFE_DELETE(_eProgressBar);
}

void eProgressBar::update()	
{
	gameObject::update();

	_eProgressBar->update(_progressWindow.pos.x, _progressWindow.pos.y -70, _playerEnergy,100);	
}
void eProgressBar::render()	
{
	_progressWindow.img->scaleRender(getMemDC(), _progressWindow.rc.left, _progressWindow.rc.top, 48,244);
	_eProgressBar->render();
}


void eProgressBar::consume(tagMessage msg)
{
	_playerEnergy += msg.data;
}
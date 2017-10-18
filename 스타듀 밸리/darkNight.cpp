#include "stdafx.h"
#include "darkNight.h"

HRESULT darkNight::init(string name, string imageKey, tagFloat pos, int indexX, int indexY)
{
	gameObject::init(name, imageKey,pos);

	_alpha = LEVEL3;

	_rc = RectMakeCenter(_pos.x, _pos.y, TILESIZE, TILESIZE);

	this->addCallback("changeAlpha", [this](tagMessage msg)
	{
		this->changeAlpha(msg);
	});

	_player = TOWNWORLD->findObject(objectType::HUMAN, "player");

	

	return S_OK;
}

void darkNight::release()
{
	gameObject::release();
}

void darkNight::update() 
{
	gameObject::update();

	

	
}

void darkNight::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();
	_image->alphaRender(getMemDC(), _rc.left - rc.left, _rc.top - rc.top, _alpha);

}


void darkNight::changeAlpha(tagMessage msg)
{
	
}
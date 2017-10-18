#include "stdafx.h"
#include "darkNight.h"

HRESULT darkNight::init(string name, string imageKey, tagFloat pos, int indexX, int indexY)
{
	gameObject::init(name, imageKey,pos);

	_alpha = DARKLEVEL4;

	_rc = RectMakeCenter(_pos.x, _pos.y, TILESIZE, TILESIZE);

	this->addCallback("changeAlpha", [this](tagMessage msg)
	{
		this->changeAlpha(msg);
	});

	_player = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");

	_indexX = indexX;
	_indexY = indexY;
	

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

	if (WORLDTIME->_dayDirection == dayDirection::DEEP_NIGHT)
	{
		_alpha =DARKLEVEL4;
	}
	else if (WORLDTIME->_dayDirection == dayDirection::MID_NIGHT)
	{
		_alpha = DARKLEVEL3;
	}
	else if (WORLDTIME->_dayDirection == dayDirection::EARLY_NIGHT)
	{
		_alpha = DARKLEVEL1;
	}
	else if (WORLDTIME->_dayDirection == dayDirection::BRIGHT)
	{
		_alpha = DARKLEVEL0;
	}


}


void darkNight::changeAlpha(tagMessage msg)
{
	this->_alpha = msg.data;
}
#include "stdafx.h"
#include "fade.h"
#include "player.h"

fade::fade()
{
}


fade::~fade()
{

}


HRESULT fade::init(string name)
{
	gameObject::init(name);

	_image = IMAGEMANAGER->findImage("blackBox");

	_alpha = 0;
	
	_isActiving = false;
	_isMax = false;

	return S_OK;
}

void fade::release()
{
	gameObject::release();
}

void fade::update()
{

	if (_isActiving)
	{
		
		if (!_isMax)
		{
			_alpha+=2;
			if (_alpha >= 255)
			{
				_isMax = true;
				_alpha = 255;
				player* ply = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");
				ply->_pos.x = 14 * (TILESIZE);
				ply->_pos.y = 94 * (TILESIZE);
				WORLDTIME->_dayDirection = dayDirection::BRIGHT;
			}
		}
		else if (_isMax)
		{
			_alpha-=2;
			if (_alpha <= 0)
			{
				_alpha = 0;
				_isMax = false;
				_isActiving = false;
				WORLDTIME->_isTimeFlow = true;
				

			}
		}


	}
}

void fade::render()
{
	_image->alphaRender(getMemDC(), 0, 0, _alpha);
}


void fade::startFadeOut()
{
	_isActiving = true;
}
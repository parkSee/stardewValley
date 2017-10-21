#include "stdafx.h"
#include "fade.h"


fade::fade()
{
}


fade::~fade()
{

}


HRESULT fade::init(string name)
{
	_image = IMAGEMANAGER->findImage("blackBox");

	_alpha = 0;
	
	_isActiving = false;
	_isMax = false;

	return S_OK;
}

void fade::release()
{

}

void fade::update()
{
	if (_isActiving)
	{
		if (!_isMax)
		{
			_alpha++;
		}
		else if (_isMax)
		{
			_alpha--;
			if (_alpha <= 0)
			{
				_alpha = 0;
				_isActiving = false;
			}
		}


	}
}

void fade::render()
{
	_image->alphaRender(getMemDC(), 0, 0, _alpha);
}

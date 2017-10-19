#include "stdafx.h"
#include "land.h"


HRESULT land::init(tagFloat pos)
{
	motherObject::init("land", "land", pos, pivot::LEFT_TOP);

	_isWet = false;
	
	//land* _land = new land;
	//_land->init(pos);
	TOWNWORLD->addObject(objectType::OBJ, this);


	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->hoeAttack();
	});

	return S_OK;
}
void land::release()
{
	motherObject::release();
}
void land::update()
{
	motherObject::update();
}
void land::render()
{

	if (_isWet == false)
	{
		_image->frameScaleRender(getMemDC(), -CAMERAMANAGER->getRenderRc().left + _pos.x, -CAMERAMANAGER->getRenderRc().top + _pos.y, 0, 0, 70, 70);
	}

	if (_isWet == true)
	{

	}
}


void land::hoeAttack()
{
	this->setDestroy();
}
#include "stdafx.h"
#include "grass.h"
#include "mapToolTile.h"

HRESULT grass::init(tagFloat pos)
{
	motherObject::init("grass", "grass", pos, pivot::LEFT_TOP);

	
	_isMovable = true;
	_objEnum = OBJECT::GRASS;
	TOWNWORLD->addObject(objectType::OBJ, this);
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(this);
	

	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->grassAttack();
	});

	this->addCallback("pixHoeAttack", [this](tagMessage msg)
	{
		this->grassAttack();
	});

	this->addCallback("sickleAttack", [this](tagMessage msg)
	{
		this->grassAttack();
	});

	this->addCallback("hoeAttack", [this](tagMessage msg)
	{
		this->grassAttack();
	});

	return S_OK;
}
void grass::release()
{
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(NULL);

	motherObject::release();
}
void grass::update()
{
	motherObject::update();
}
void grass::grassAttack()
{
	
	
		EFFECTMANAGER->play("grassDie", _pos.x + 35, _pos.y);

		this->setDestroy();

		dropItem* d = new dropItem;
		d->init("grass", "asdasdsad", tagFloat(_pos.x + 35, _pos.y));
		TOWNWORLD->addObject(objectType::ITEM, d);
	
}

void grass::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();

	_image->frameScaleRender(getMemDC(), -rc.left + _pos.x, -rc.top + _pos.y, 0, 0, 70, 70);
}
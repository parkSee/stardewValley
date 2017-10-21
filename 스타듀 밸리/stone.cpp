#include "stdafx.h"
#include "stone.h"
#include "mapToolTile.h"

HRESULT stone::init(tagFloat pos)
{
	motherObject::init("stone", "stone", pos, pivot::LEFT_TOP);


	_objEnum = OBJECT::STONE;
	TOWNWORLD->addObject(objectType::OBJ, this);
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(this);
	
	
	
	_isMovable = false;


	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->stoneAttack();
	});

	return S_OK;
}
void stone::release()
{
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(NULL);

	motherObject::release();
}
void stone::update()
{
	motherObject::update();

	if (KEYMANAGER->isOnceKeyDown('B'))
	{
		EFFECTMANAGER->play("stoneDie", _pos.x + 30, _pos.y + 100);
	}
}
void stone::stoneAttack()
{
	EFFECTMANAGER->play("stoneDie", _pos.x + 30, _pos.y);

	this->setDestroy();


	//dropItem* drop = new dropItem;
	//drop->init("stone", "stone");
}
void stone::render()
{

	RECT rc = CAMERAMANAGER->getRenderRc();

	_image->frameScaleRender(getMemDC(), -rc.left + _pos.x, -rc.top + _pos.y, 0, 0, 65, 65);
}

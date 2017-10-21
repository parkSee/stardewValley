#include "stdafx.h"
#include "land.h"
#include "mapToolTile.h"


HRESULT land::init(tagFloat pos)
{
	motherObject::init("land", "land", pos, pivot::LEFT_TOP);

	_isWet = false;
	_isMovable = true;
	
	//land* _land = new land;
	//_land->init(pos);
	_objEnum = OBJECT::FARMLAND;
	TOWNWORLD->addObject(objectType::TILE, this);
	//자신을 타일에게 알린다
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(this);

	



	this->addCallback("pixHoeAttack", [this](tagMessage msg)
	{
		
		this->hoeAttack();
		//exit(0);
	});

	return S_OK;
}
void land::release()
{
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(NULL);

	motherObject::release();
}
void land::update()
{
	motherObject::update();
	
}
void land::render()
{
	RECT rc = CAMERAMANAGER->getRenderRc();

	if (_isWet == false)
	{
		_image->frameScaleRender(getMemDC(), -rc.left + _pos.x , - rc.top + _pos.y , 0, 0, 65, 65);
	}

	if (_isWet == true)
	{

	}
}


void land::hoeAttack()
{

	this->setDestroy();
}
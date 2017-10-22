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

	int indexX = _pos.x / TILESIZE;
	int indexY = _pos.y / TILESIZE;

	mapToolTile* tile = TOWNWORLD->getTile(indexX, indexY);

	_rc = RectMake(tile->getRect().left, tile->getRect().top, _image->getWidth(), _image->getHeight());

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
		_image->frameScaleRender(getMemDC(), -rc.left + _rc.left ,  -rc.top + _rc.top , 0, 0, 65, 65);
	}

	if (_isWet == true)
	{
		_image->frameScaleRender(getMemDC(), -rc.left + _rc.left, -rc.top + _rc.top, 0, 0, 65, 65);
	}
}


void land::hoeAttack()
{

	this->setDestroy();
}
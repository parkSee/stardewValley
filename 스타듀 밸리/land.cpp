#include "stdafx.h"
#include "land.h"


HRESULT land::init(tagFloat pos)
{
	motherObject::init("land", "tileSprite", pos, pivot::LEFT_TOP);

	_object = OBJECT::FARMLAND;
	TOWNWORLD->addObject(objectType::OBJ, this);

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
	motherObject::render();

	if (_isWet == false)
	{

	}

	if (_isWet == true)
	{

	}
}


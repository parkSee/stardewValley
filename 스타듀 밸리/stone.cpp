#include "stdafx.h"
#include "stone.h"

HRESULT stone::init(tagFloat pos)
{
	motherObject::init("stone", "tileSprite", pos, pivot::LEFT_TOP);


	_object = OBJECT::STONE;
	TOWNWORLD->addObject(objectType::OBJ, this);

	EFFECTMANAGER->addEffect("stoneDie", "µ¹.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	

	this->addCallback("pickAttack", [this](tagMessage msg)
	{
		this->stoneAttack();
	});

	return S_OK
}
void stone::release()
{
	motherObject::release();
}
void stone::update()
{
	motherObject::update();
}
void stone::stoneAttack()
{
	EFFECTMANAGER->play("stoneDie", _pos.x, _pos.y);

	this->setDestroy();
}
void stone::render()
{
	motherObject::render();
}

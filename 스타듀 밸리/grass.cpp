#include "stdafx.h"
#include "grass.h"


HRESULT grass::init(tagFloat pos)
{
	motherObject::init("grass", "tileSprite", pos, pivot::LEFT_TOP);

	_hp = 10;

	_object = OBJECT::GRASS;
	TOWNWORLD->addObject(objectType::OBJ, this);

	EFFECTMANAGER->addEffect("grassAttack", "Ç®.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	EFFECTMANAGER->addEffect("grassDie", "Ç®ÅÍÁü.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);

	this->addCallback("sickleAttack", [this](tagMessage msg)
	{
		this->grassAttack();
	});

	return S_OK;
}
void grass::release()
{
	motherObject::release();
}
void grass::update()
{
	motherObject::update();
}
void grass::grassAttack()
{
	if (_hp >= 0)
	{
		EFFECTMANAGER->play("grassAttack", _pos.x, _pos.y);
	}

	if (_hp <= 0)
	{
		EFFECTMANAGER->play("grassDie", _pos.x, _pos.y);

		this->setDestroy();

		dropItem* drop = new dropItem;
		drop->init("grass", "grass");
	}
}

void grass::render()
{
	motherObject::render();
}
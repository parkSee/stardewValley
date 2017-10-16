#include "stdafx.h"
#include "seed.h"


HRESULT seed::init(tagFloat pos) 
{
	motherObject::init("seed", "tileSprite", pos, pivot::LEFT_TOP);

	_object = OBJECT::SEED;
	TOWNWORLD->addObject(objectType::OBJ, this);

	EFFECTMANAGER->addEffect("seed", "��������.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	this->addCallback("pickAttack", [this](tagMessage msg)
	{
		this->growAttack();
	});

	_growNum == 0;

	this->addCallback("up", [this](tagMessage msg)
	{
		this->grow();
	});
	
	return S_OK;
}
 void seed::release()
{
	 motherObject::release();
}
 void seed::update()
{
	 motherObject::update();
}
 void seed::grow()
 {
	
		 _growNum++;
	 

 }
 void seed::growAttack()
 {
	 EFFECTMANAGER->play("seed", _pos.x, _pos.y);

	 this->setDestroy();

	 dropItem* drop = new dropItem;
	 drop->init("seed", "seed");
 }
 void seed::render()
{
	 motherObject::render();

	 switch (_growNum)
	 {	
	 case 0:
		 break;
	 case 1:
		 break;
	 case 2:
		 break;
	 case 3:
		 break;
	 case 4:
		 break;
	 case 5:
		 break;
	 case 6:
		 break;
	 case 7:
		 break;
	 }
}
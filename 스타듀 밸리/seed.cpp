#include "stdafx.h"
#include "seed.h"


HRESULT seed::init(tagFloat pos) 
{
	motherObject::init("seed", "tileSprite", pos, pivot::LEFT_TOP);

	_object = OBJECT::SEED;
	TOWNWORLD->addObject(objectType::OBJ, this);


	_growNum == 0;

	this->addCallback("up", [this](tagMessage msg)
	{
		this->grow();
	});
	
	return S_OK
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
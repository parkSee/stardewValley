#include "stdafx.h"
#include "seed.h"
#include "mapToolTile.h"
#include "land.h"



HRESULT seed::init(string name, string imageKey, tagFloat pos, string explain)
{
	motherObject::init(name,imageKey,pos, pivot::LEFT_TOP);

	_objEnum = OBJECT::SEED;
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(this);

	//EFFECTMANAGER->addEffect("seed", "¾¾¸ÂÀ»¶§.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	this->addCallback("pickAttack", [this](tagMessage msg)
	{
		this->growAttack();
	});

	_growNum = 0;
	_isRight = false;
	_isMovable = true;
	_explain = explain;

	this->addCallback("grow", [this](tagMessage msg)
	{
		this->grow();
	});
	

	TOWNWORLD->addObject(objectType::OBJ,this);
	
	return S_OK;
}
 void seed::release()
{
	 TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(NULL);

	 motherObject::release();
}
 void seed::update()
{
	 motherObject::update();

	
}
 void seed::grow()
 {
	 if (_growNum >= _image->getMaxFrameX())return;
	//if (((land*)TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->getPObj())->getWet() == true)
	//{
	 _growNum++;
	 if (_growNum == _image->getMaxFrameX())
	 {
		 _isRight == true;
	 }
	//}

 }
 void seed::growAttack()
 {
	 EFFECTMANAGER->play("seed", _pos.x, _pos.y);

	 this->setDestroy();

	// dropItem* drop = new dropItem;
	// drop->init("seed", "seed");
 }
 void seed::render()
{
	 motherObject::render();
	 RECT rc = CAMERAMANAGER->getRenderRc();

	 _image->alphaScaleFrameRender(getMemDC(), -rc.left + _pos.x, -rc.top + _pos.y - 10,
		 _growNum, 0, _image->getFrameWidth()*4.0f, _image->getFrameHeight()*4.0f, 255);

	// RectangleMake(getMemDC(), 100-rc.left, 100-rc.top, 100, 100);
}
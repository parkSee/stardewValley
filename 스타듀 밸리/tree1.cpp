#include "stdafx.h"
#include "tree1.h"



HRESULT tree1::init(tagFloat pos)
{
	tree1_bottom* bottom = new tree1_bottom;
	bottom->init(pos);

	tree1_top* top = new tree1_top;
	top->init(pos);

	

	return S_OK;
}
void tree1::release()
{

}
void tree1::update()
{

}
void tree1::render()
{

}


//------------------------------

HRESULT tree1_bottom::init(tagFloat pos)
{
	motherObject::init("tree1_bottom", "tileSprite", pos, pivot::LEFT_TOP);

	_hp = 25;

	_object = OBJECT::TREE1_BOTTOM;
	TOWNWORLD->addObject(objectType::OBJ, this);


	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->bottomAttack();
	});

	EFFECTMANAGER->addEffect("die", "나무쓰러짐.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	EFFECTMANAGER->addEffect("attack", "나무맞을때.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);

	return S_OK;
}
void tree1_bottom::release()
{
	motherObject::release();
}
void tree1_bottom::update()
{
	motherObject::update();

	
}
void tree1_bottom::bottomAttack()
{
	_hp -= 5;

	if (_hp <= 10 && _hp > 0)
	{
		EFFECTMANAGER->play("attack", _pos.x, _pos.y);
	}
	if (_hp == 0)
	{
		EFFECTMANAGER->play("die", _pos.x, _pos.y);

	}

}
void tree1_bottom::render()
{

}

//---------------------------------------------------

HRESULT tree1_top::init(tagFloat pos)
{
	motherObject::init("tree1_top", "tileSprite", pos, pivot::LEFT_TOP);

	_hp = 20;

	_object = OBJECT::TREE1_TOP;
	TOWNWORLD->addObject(objectType::OBJ, this);

	return S_OK;
}
void tree1_top::release()
{

}
void tree1_top::update()
{

}
void tree1_top::render()
{

}

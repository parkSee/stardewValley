#include "stdafx.h"
#include "tree1.h"


HRESULT tree1::init(tagFloat pos)
{
	tree1_bottom* bottom = new tree1_bottom;
	bottom->init(pos);

	tree1_top* top = new tree1_top;
	top->init(pos);

	bottom->setPobj(top);

	_treeNum = 0;

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
	switch (_treeNum)
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
	}
}


//------------------------------

HRESULT tree1_bottom::init(tagFloat pos)
{
	motherObject::init("tree1_bottom", "tileSprite", pos, pivot::LEFT_TOP);

	_hp = 15;

	_object = OBJECT::TREE1_BOTTOM;
	TOWNWORLD->addObject(objectType::OBJ, this);
	EFFECTMANAGER->addEffect("die", "나무쓰러짐.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	EFFECTMANAGER->addEffect("attack", "나무맞을때.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);

	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->bottomAttack();
	});

	

	return S_OK;
}
void tree1_bottom::release()
{
	motherObject::release();
}
void tree1_bottom::update()
{
	motherObject::update();

	if (_hp > 0)
	{
		EFFECTMANAGER->play("attack", _pos.x, _pos.y);
	}
	if (_hp <= 0)
	{
		EFFECTMANAGER->play("die", _pos.x, _pos.y);
		this->setDestroy();

		//dropItem* drop = new dropItem;
		//drop->init("tree_bottom", "tree");

	}

}
void tree1_bottom::bottomAttack()
{
	if (_pObj != NULL)
	{
		_pObj->sendMessage(tagMessage("axeAttack"));
	}
	else
	{
		_hp -= 5;
	}

}
void tree1_bottom::render()
{
	
}

//---------------------------------------------------

HRESULT tree1_top::init(tagFloat pos)
{
	motherObject::init("tree1_top", "tileSprite", pos, pivot::LEFT_TOP);

	_hp = 15;

	_object = OBJECT::TREE1_TOP;
	TOWNWORLD->addObject(objectType::OBJ, this);
	EFFECTMANAGER->addEffect("die", "나무쓰러짐.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	EFFECTMANAGER->addEffect("attack", "나무맞을때.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);


	this->addCallback("axeAttack", [this](tagMessage msg)
	{
		this->topAttack();
	});


	return S_OK;
}
void tree1_top::release()
{
	motherObject::release();
}
void tree1_top::update()
{
	motherObject::update();

	if (_hp > 0)
	{
		EFFECTMANAGER->play("attack", _pos.x, _pos.y);
	}

	if (_hp <= 0)
	{
		EFFECTMANAGER->play("die", _pos.x, _pos.y);

		this->setDestroy();

		//dropItem* drop = new dropItem;
		//drop->init("tree_top","tree",);
	}
}
void tree1_top::topAttack()
{
	_hp -= 5;
}
void tree1_top::render()
{

}

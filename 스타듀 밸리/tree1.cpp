#include "stdafx.h"
#include "tree1.h"
#include "mapToolTile.h"
#include "dropItem.h"

HRESULT tree1::init(tagFloat pos)
{
	tree1_bottom* bottom = new tree1_bottom;
	bottom->init(pos);

	tree1_top* top = new tree1_top;
	top->init(pos);

	bottom->setPObj(top);

	_treeNum = 0;

	return S_OK;
}
void tree1::release()
{

}
void tree1::update()
{
	if (KEYMANAGER->isOnceKeyDown('L'))
	{

	}
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
	motherObject::init("tree1_bottom", "tree", pos, pivot::LEFT_TOP);

	_hp = 15;
	_isMovable = false;

	

	_objEnum = OBJECT::TREE1_BOTTOM;
	TOWNWORLD->addObject(objectType::OBJ, this);
	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(this);
	//EFFECTMANAGER->addEffect("die", "나무.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	//EFFECTMANAGER->addEffect("attack", "나무.bmp", 20700, 370, 450, 370, 1.0f, 1.0f, 1.0f);

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
		
			//EFFECTMANAGER->play("attack", _pos.x / TILESIZE, _pos.y / TILESIZE);
		
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
	
	_image->alphaScaleFrameRender(getMemDC(), -CAMERAMANAGER->getRenderRc().left + _pos.x, -CAMERAMANAGER->getRenderRc().top + _pos.y, 0, 0, 70, 70, 0.0f);
}

void tree1_bottom::setDestroy(float time)
{
	gameObject::setDestroy(time);

	TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->setPObj(NULL);
}

//---------------------------------------------------

HRESULT tree1_top::init(tagFloat pos)
{
	motherObject::init("tree1_top", "treetop", pos, pivot::LEFT_TOP);

	_hp = 15;

	_isDie = false;
	_count = 0;

	_objEnum = OBJECT::TREE1_TOP;
	TOWNWORLD->addObject(objectType::OBJ, this);
	//EFFECTMANAGER->addEffect("die", "나무쓰러짐.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);
	//EFFECTMANAGER->addEffect("attack", "나무맞을때.bmp", 832, 62, 32, 62, 1.0f, 1.0f, 1000);


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

	
	if (_isDie == true)
	{
		_count += TIMEMANAGER->getElapsedTime();

		if (_count >= 2.3f)
		{
			for (int i = 0; i < RND->getFromIntTo(2, 10); i++)
			{
				dropItem* a = new dropItem;
				a->init("수액", "asdadadad", tagFloat(_pos.x + 270, _pos.y));
				TOWNWORLD->addObject(objectType::ITEM, a);
			}

			this->setDestroy();
		}
	}
	

		//dropItem* drop = new dropItem;
		//drop->init("tree_top","tree", tagFloat(_pos.x, _pos.y));
	

	
}
void tree1_top::topAttack()
{
	_hp -= 5;

	if (_hp > 0)
	{
		//EFFECTMANAGER->play("attack", _pos.x - 65, _pos.y - 230);
	}
	if (_hp <= 0)
	{
		if (!_isDie)
		{
			EFFECTMANAGER->play("die", _pos.x + 160, _pos.y - 140);
			_isDie = true;
		}
	}

}
void tree1_top::render()
{
	if (!_isDie)
	{
		_image->alphaScaleFrameRender(getMemDC(), -CAMERAMANAGER->getRenderRc().left + _pos.x - 65, -CAMERAMANAGER->getRenderRc().top + _pos.y - 330, 0, 0, 200, 350, 0.0f);
	}
}

void tree1_top::setDestroy(float time)
{
	gameObject::setDestroy(time);

	((motherObject*)TOWNWORLD->getTile(_pos.x / TILESIZE, _pos.y / TILESIZE)->getPObj())->setPObj(NULL);
}

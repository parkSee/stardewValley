#include "stdafx.h"
#include "inventory.h"

using namespace invenDirection;

HRESULT inventory::init(string name)
{
	gameObject::init(name);

	_subInventory.img = IMAGEMANAGER->findImage("subInventory");
	_subInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY - 80);
	_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y,
		_subInventory.img->getWidth(), _subInventory.img->getHeight());

	_direction = SUB_BOTTOM;

	for (int i = 0; i < 12; i++)
	{
		char str[100] = "";
		sprintf(str, "%d", i);

		tagItem	item = tagItem((string)str, tagFloat(_subInventory.rc.left + 49 + 64*i , _subInventory.pos.y));
		_vInventory.push_back(item);
	}

	_vInventory[0] = tagItem("axe", tagFloat(_vInventory[0].pos.x, _vInventory[0].pos.y), itemType::TOOL);
	_vInventory[1] = tagItem("hoe", tagFloat(_vInventory[1].pos.x, _vInventory[1].pos.y), itemType::TOOL);
	_vInventory[2] = tagItem("pixHoe", tagFloat(_vInventory[2].pos.x, _vInventory[2].pos.y), itemType::TOOL);
	_vInventory[3] = tagItem("sickle", tagFloat(_vInventory[3].pos.x, _vInventory[3].pos.y), itemType::TOOL);
	_vInventory[4] = tagItem("sword", tagFloat(_vInventory[4].pos.x, _vInventory[4].pos.y), itemType::TOOL);

	_targetItem = new tagItem;
	_targetItem = &_vInventory[0];

	//msg.data -> 이거 형변환으로 인벤토리 창 상태 받자 
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState(msg);
	});

	this->addCallback("setTargetItem", [this](tagMessage msg)
	{
		this->setTargetItem(msg);
	});

	return S_OK;
}
void inventory::release()
{
	gameObject::release();
}

void inventory::update()
{
	gameObject::update();

	
}

void inventory::render()
{
	if (_direction == SUB_BOTTOM || _direction == SUB_TOP)
	{
		_subInventory.img->scaleRender(getMemDC(), _subInventory.rc.left, _subInventory.rc.top,
			_subInventory.img->getWidth(), _subInventory.img->getHeight());

		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
	
		for (int i = 0; i < 12; ++i)
		{	
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(255,0,0));
			HPEN oldPen = (HPEN)SelectObject(getMemDC(), GetStockObject(NULL_PEN));

			if (_targetItem == &_vInventory[i])
			{
				HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);
			}

			Rectangle(getMemDC(),_vInventory[i].rc.left, _vInventory[i].rc.top, 
				_vInventory[i].rc.right, _vInventory[i].rc.bottom);

			SelectObject(getMemDC(), oldPen);
			DeleteObject(pen);

			if (_vInventory[i].img != NULL)
			{
				_vInventory[i].img->scaleRender(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
					_vInventory[i].img->getWidth(), _vInventory[i].img->getHeight());
			}
		}
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);
	}
}


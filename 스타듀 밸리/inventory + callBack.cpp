#include "stdafx.h"
#include "inventory.h"

#include "player.h"

using namespace invenDirection;

void inventory::changeState(tagMessage msg)
{
	_direction = (invenDirection::Enum)msg.data;

	if (_direction == SUB_BOTTOM)
	{
		_subInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY - 100);
		_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y,
			_subInventory.img->getWidth(), _subInventory.img->getHeight());
	}

	else if (_direction == SUB_TOP)
	{
		_subInventory.pos = tagFloat(WINSIZEX / 2, 0 + 100);
		_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y,
			_subInventory.img->getWidth(), _subInventory.img->getHeight());
	}

	else if (_direction == HIDE)
	{

	}
	else if (_direction == MAIN)
	{

	}

}

void inventory::setTargetItem(tagMessage msg)
{
	for (int i = 0; i < _vInventory.size(); ++i)
	{
		if (_vInventory[i].name == msg.conversation)
		{
			_targetItem = &_vInventory[i];

			TOWNWORLD->findObject(objectType::HUMAN, "player")
				->sendMessage(tagMessage("changeTargetItem",0.0f,0,0,vector<gameObject*>() , _targetItem->name));
		}
	}
}
#include "stdafx.h"
#include "inventory.h"

#include "player.h"
#include "publicUI.h"

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
		if (_vInventory[i].name != msg.conversation)continue;
		_targetItem = &_vInventory[i];
		TOWNWORLD->findObject(objectType::HUMAN, "player")
			->sendMessage(tagMessage("changeTargetItem",0.0f,0,0,vector<gameObject*>() , _targetItem->name));
		break;
	}
}

void inventory::changeItem()
{
	if (_direction == invenDirection::MAIN)
	{
		for (int i = 0; i < _vInventory.size(); ++i)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				if (PtInRect(&_vInventory[i].rc, _ptMouse))
				{
					if (!_isPicking)
					{
						if (_vInventory[i].type != itemType::NONE)
						{
							if (_targetItem == &_vInventory[i])
							{
								_targetItem = &_tempItem;
							}

							_tempItem = _vInventory[i];
							_pickingItem = _vInventory[i];

							char str[100];
							sprintf(str, "%f", RND->getFloat());
							_vInventory[i] = tagItem((string)str,"", _vInventory[i].pos, 0, itemType::NONE);

							_isPicking = true;
							break;
						}
					}

					else if (_isPicking)
					{
						if (_vInventory[i].type == itemType::NONE)
						{
							if (_targetItem == &_tempItem)
							{
								_targetItem = &_vInventory[i];
							}

							_tempItem.pos = _vInventory[i].pos;
							_tempItem.rc = _vInventory[i].rc;
							_vInventory[i] = _tempItem;

							_pickingItem = tagItem();

							_isPicking = false;

							ZeroMemory(&_tempItem, sizeof(tagItem));

							break;
						}

					}
				}
			}

			if (PtInRect(&_vInventory[i].rc, _ptMouse))
			{
				_vInventory[i].size = 1.2f;
				
				_explain.pos = tagFloat(_ptMouse.x + 30 , _ptMouse.y + 30);
				_explain.rc = RectMake(_explain.pos.x, _explain.pos.y, _explain.img->getWidth() / 2,
					_explain.img->getHeight() / 2);
			
			}

			else if (!PtInRect(&_vInventory[i].rc, _ptMouse))
			{
				_vInventory[i].size = 1.0f;
			}

		}
	}



}



void inventory::addItem(tagMessage msg)
{
	for (int i = 0; i < _vInventory.size(); ++i)
	{
		if (msg.conversation != _vInventory[i].name && _vInventory[i].type != itemType::NONE)continue;
		
		publicUI* ui = (publicUI*)TOWNWORLD->findObject(objectType::INTERFACE, "publicUI");

		if (_vInventory[i].type == itemType::NONE)
		{
			if (this->isFindItem(msg.conversation))continue;

			_vInventory[i] = tagItem(msg.conversation, msg.str, _vInventory[i].pos, 1, this->getItemType(msg.conversation));
			ui->sendMessage(tagMessage("addGetItemUI",0.0f,0,0,vector<gameObject*>(),msg.conversation ));
			break;
		}
		else if (msg.conversation == _vInventory[i].name)
		{
			_vInventory[i].count++;
			ui->sendMessage(tagMessage("addGetItemUI", 0.0f, 0, 0, vector<gameObject*>(), msg.conversation));
			break;
		}
		//인벤토리에 공간이 없다면
		ui->sendMessage(tagMessage("addGetItemUI", 0.0f, 0, 0, vector<gameObject*>(), "공간부족"));
	}
}

itemType::Enum inventory::getItemType(string itemName)
{
	if (itemName == "수액" || itemName == "민들레")
	{
		return itemType::FOOD;
	}
	else if (itemName == "나무" || itemName == "돌")
	{
		return itemType::STONE;
	}
	else if (itemName == "물뿌리개")
	{
		return itemType::TOOL;
	}
}
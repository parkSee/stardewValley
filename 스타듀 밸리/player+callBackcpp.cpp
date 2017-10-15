#include "stdafx.h"
#include "player.h"
#include "inventory.h"


void player::eating()
{

}

void player::lbuttonClick()
{

}

void player::changeTargetItem()
{
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");		//인벤토리에서 보내는 메세지를 받아온다

	_item = inven->getTargetItem();

	if (_item->type == itemType::FOOD || _item->type == itemType::SEED)
	{
		switch (_state)
		{
		case playerState::STAND:
			this->changeState(STAND_TAKE);
			break;
		case playerState::STAND_RIGHT:
			this->changeState(STAND_TAKE_RIGHT);
			break;
		case playerState::STAND_LEFT:
			this->changeState(STAND_TAKE_LEFT);
			break;
		case playerState::STAND_BACK:
			this->changeState(STAND_TAKE_BACK);
			break;
		case playerState::RIGHT_RUN:
			this->changeState(TAKE_RIGHT);
			break;
		case playerState::LEFT_RUN:
			this->changeState(TAKE_LEFT);
			break;
		case playerState::UP_RUN:
			this->changeState(TAKE_UP);
			break;
		case playerState::DOWN_RUN:
			this->changeState(TAKE_DOWN);
			break;
		}
	}
}

RECT player::rectMakeBottom()
{
	RECT rc;

	rc.left = _pos.x - _image->getFrameWidth() / 2;
	rc.right = _pos.x + _image->getFrameWidth() / 2;
	rc.top = _pos.y - _image->getFrameHeight();
	rc.bottom = _pos.y;

	return rc;
}
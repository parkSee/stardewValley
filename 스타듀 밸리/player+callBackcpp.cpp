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
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");

	_item = inven->getTargetItem();

	if (_item->type == itemType::TOOL || _item->type == itemType::SEED)
	{
		switch (_state)
		{
		case playerState::STAND:
			this->changeState(TAKE_DOWN);
			break;
		case playerState::STAND_RIGHT:
			break;
		case playerState::STAND_LEFT:
			break;
		case playerState::STAND_BACK:
			break;
		case playerState::RIGHT_RUN:
			break;
		case playerState::LEFT_RUN:
			break;
		case playerState::UP_RUN:
			break;
		case playerState::DOWN_RUN:
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
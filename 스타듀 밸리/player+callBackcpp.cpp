#include "stdafx.h"
#include "player.h"
#include "inventory.h"


void player::eating()
{
	
}

void player::lbuttonClick()
{

}

void player::changeTargetItem(tagMessage msg)
{
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");		//인벤토리에서 보내는 메세지를 받아온다
																									//타운월드 안에 있는 인벤토리에 접근접근
	_item = inven->getTargetItem();																	//인벤토리 클래스에 있는 getTargetItem의 함수를 데려와 
																									//아이템 변수에다가 삽입!
	//_item = inven->findItem(msg.conversation);

	if (_item->type == itemType::SEED || _item->type == itemType::FOOD)
	{
		_myItem.img = _item->img;
		switch (_state)
		{
		case playerState::STAND:						//들고 서있기
			this->changeState(STAND_TAKE);
			break;
		case playerState::STAND_RIGHT:					//들고 오른쪽으로 서있기
			this->changeState(STAND_TAKE_RIGHT);
			break;
		case playerState::STAND_LEFT:					//들고 왼쪽으로 서있기
			this->changeState(STAND_TAKE_LEFT);
			break;
		case playerState::STAND_BACK:					//들고 뒤로 서있기
			this->changeState(STAND_TAKE_BACK);
			break;
		case playerState::RIGHT_RUN:					//들고 앞으로 달리기
			this->changeState(TAKE_RIGHT);
			break;
		case playerState::LEFT_RUN:						//들고 왼쪽으로 달리기
			this->changeState(TAKE_LEFT);
			break;
		case playerState::UP_RUN:						//들고 위로 달리기
			this->changeState(TAKE_UP);
			break;
		case playerState::DOWN_RUN:						//들고 아래로 달리기
			this->changeState(TAKE_DOWN);
			break;
		}

		if (_item->type == itemType::TOOL)
		{
			switch (_state)
			{
			case playerState::AXE_RIGHT:
				break;
			case playerState::AXE_LEFT:
				break;
			case playerState::AXE_UP:
				break;
			case playerState::AXE_DOWN:
				break;
			case playerState::HOE_RIGHT:
				break;
			case playerState::HOE_LEFT:
				break;
			case playerState::HOE_UP:
				break;
			case playerState::HOE_DOWN:
				break;
			case playerState::SICKLE_RIGHT:
				break;
			case playerState::SICKLE_LEFT:
				break;
			case playerState::SICKLE_UP:
				break;
			case playerState::SICKLE_DOWN:
				break;
			case playerState::WATER_RIGHT:
				break;
			case playerState::WATER_LEFT:
				break;
			case playerState::WATER_UP:
				break;
			case playerState::WATER_DOWN:
				break;
			}
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
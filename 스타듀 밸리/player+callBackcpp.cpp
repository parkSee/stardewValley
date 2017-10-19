#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "eProgressBar.h"


void player::eating(tagMessage msg)
{
	_state == EATING;
	
	_myItem.img = _item->img;						//아이템 이미지를 띄우는 
	_myItem.x = _pos.x;
	_myItem.y -= 3;
	_myItem.gravity = 0.5f;
	_myItem.y += _myItem.gravity;


}

void player::lbuttonClick(tagMessage msg)
{
	if (_state == AXE_DOWN || _state == AXE_LEFT || _state == AXE_UP || _state == AXE_RIGHT || _state == HOE_DOWN || _state == HOE_LEFT || _state == HOE_UP ||
		_state== HOE_RIGHT || _state == SICKLE_DOWN || _state == SICKLE_LEFT || _state == SICKLE_UP || _state == SICKLE_RIGHT || _state == PIXHOE_DOWN || 
		_state == PIXHOE_LEFT || _state == PIXHOE_UP || _state == PIXHOE_RIGHT || _state == WATER_DOWN || _state == WATER_LEFT || _state == WATER_UP || 
		_state == WATER_RIGHT)return;

	eProgressBar* energe = (eProgressBar*)TOWNWORLD->findObject(objectType::INTERFACE, "energyBar");
	energe->sendMessage(tagMessage("consume", 0.0f, 1));

	if (_item->type == itemType::TOOL)
	{
		if (_item->name == "도끼")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(AXE_DOWN);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				this->changeState(AXE_RIGHT);
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(AXE_LEFT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				this->changeState(AXE_UP);
				break;

			}
		}

		if (_item->name == "괭이")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(HOE_DOWN);

				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(HOE_RIGHT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(HOE_LEFT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(HOE_UP);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				break;
			}
		}
		if (_item->name == "낫")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(SICKLE_DOWN);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}

				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(SICKLE_RIGHT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(SICKLE_LEFT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(SICKLE_UP);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				break;
			}

		}

		if (_item->name == "곡괭이")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(PIXHOE_DOWN);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(PIXHOE_RIGHT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(PIXHOE_LEFT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(PIXHOE_UP);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				break;
			}
		}

		if (_item->name == "물뿌리개")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(WATER_DOWN);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(WATER_RIGHT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(WATER_LEFT);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(WATER_UP);
				if (_tile1->getPObj() != NULL)
				{
					_tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				break;
			}
		}
	}
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
			_myItem.img = _item->img;						//아이템 이미지를 띄우는 

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
		}
}

RECT player::rectMakeBottom()
{
	RECT rc;

	rc.left = _pos.x - _image->getFrameWidth() / 2;
	rc.right = _pos.x + _image->getFrameWidth() / 2 ;
	rc.top = _pos.y - _image->getFrameHeight() /2 - 70;
	rc.bottom = _pos.y;

	return rc;
}



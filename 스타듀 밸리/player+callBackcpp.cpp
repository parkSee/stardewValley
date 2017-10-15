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
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");		//�κ��丮���� ������ �޼����� �޾ƿ´�
																									//Ÿ����� �ȿ� �ִ� �κ��丮�� ��������
	_item = inven->getTargetItem();																	//�κ��丮 Ŭ������ �ִ� getTargetItem�� �Լ��� ������ 
																									//������ �������ٰ� ����!
	//_item = inven->findItem(msg.conversation);

	if (_item->type == itemType::SEED || _item->type == itemType::FOOD)
	{
		_myItem.img = _item->img;
		switch (_state)
		{
		case playerState::STAND:						//��� ���ֱ�
			this->changeState(STAND_TAKE);
			break;
		case playerState::STAND_RIGHT:					//��� ���������� ���ֱ�
			this->changeState(STAND_TAKE_RIGHT);
			break;
		case playerState::STAND_LEFT:					//��� �������� ���ֱ�
			this->changeState(STAND_TAKE_LEFT);
			break;
		case playerState::STAND_BACK:					//��� �ڷ� ���ֱ�
			this->changeState(STAND_TAKE_BACK);
			break;
		case playerState::RIGHT_RUN:					//��� ������ �޸���
			this->changeState(TAKE_RIGHT);
			break;
		case playerState::LEFT_RUN:						//��� �������� �޸���
			this->changeState(TAKE_LEFT);
			break;
		case playerState::UP_RUN:						//��� ���� �޸���
			this->changeState(TAKE_UP);
			break;
		case playerState::DOWN_RUN:						//��� �Ʒ��� �޸���
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
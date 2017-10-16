#include "stdafx.h"
#include "player.h"
#include "inventory.h"


void player::eating()
{
	
}

void player::lbuttonClick(tagMessage msg)
{
	if (_item->type == itemType::TOOL)
	{
		if (_item->name == "����")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(AXE_DOWN);

				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(AXE_RIGHT);
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(AXE_LEFT);
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(AXE_UP);
				break;
	
			}
		}

		if (_item->name == "����")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(HOE_DOWN);

				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(HOE_RIGHT);
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(HOE_LEFT);
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(HOE_UP);
				break;
			}

			if (_item->name == "��")
			{
				switch (_state)
				{
				case playerState::STAND: case playerState::DOWN_RUN:
					this->changeState(SICKLE_DOWN);

					break;
				case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
					this->changeState(SICKLE_RIGHT);
					break;
				case playerState::STAND_LEFT: case playerState::LEFT_RUN:
					this->changeState(SICKLE_LEFT);
					break;
				case playerState::STAND_BACK: case playerState::UP_RUN:
					this->changeState(SICKLE_UP);
					break;
				}

			}

			if (_item->name == "���")
			{
				switch (_state)
				{
				case playerState::STAND: case playerState::DOWN_RUN:
					this->changeState(PIXHOE_DOWN);

					break;
				case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
					this->changeState(PIXHOE_RIGHT);
					break;
				case playerState::STAND_LEFT: case playerState::LEFT_RUN:
					this->changeState(PIXHOE_LEFT);
					break;
				case playerState::STAND_BACK: case playerState::UP_RUN:
					this->changeState(PIXHOE_UP);
					break;
				}
			}
		}

	}
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
			_myItem.img = _item->img;						//������ �̹����� ���� 

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
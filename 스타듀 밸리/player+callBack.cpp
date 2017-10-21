#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "eProgressBar.h"


void player::eating(tagMessage msg)
{
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
	_item = inven->getTargetItem();

	if (_item->type == itemType::FOOD)
	{
		eProgressBar*energe = (eProgressBar*)TOWNWORLD->findObject(objectType::INTERFACE, "energyBar");
		energe->sendMessage(tagMessage("consume", 0.0f, -3));


		this->changeState(EATING);
		//this->moveToEat();
		_myItem.img = _item->img;						//������ �̹����� ���� 
	
		
	}

	
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
		if (_item->name == "����")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(AXE_DOWN);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				
				else if (!tile1->getPObj())
				{
					 if (tile2->getPObj())
					{
						 tile2->getPObj()->sendMessage(tagMessage("axeAttack"));
					}
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(AXE_RIGHT);

				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("axeAttack"));
					}
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(AXE_LEFT);

				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("axeAttack"));
					}
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(AXE_UP);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("axeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("axeAttack"));
					}
				}
				break;
			}
			return;
		}

		if (_item->name == "����")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(HOE_DOWN);

				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("hoeAttack"));
					}
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(HOE_RIGHT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("hoeAttack"));
					}
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(HOE_LEFT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("hoeAttack"));
					}
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(HOE_UP);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("hoeAttack"));

				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("hoeAttack"));
					}
				}
				break;
			}
		}
		if (_item->name == "��")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(SICKLE_DOWN);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("sickleAttack"));
					}
				}

				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(SICKLE_RIGHT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("sickleAttack"));
					}
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(SICKLE_LEFT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("sickleAttack"));
					}
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(SICKLE_UP);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("sickleAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("sickleAttack"));
					}
				}
				break;
			}

		}

		if (_item->name == "���")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(PIXHOE_DOWN);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
					}
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(PIXHOE_RIGHT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
					}
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(PIXHOE_LEFT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
					}
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(PIXHOE_UP);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("pixHoeAttack"));
					}
				}
				break;
			}
		}

		if (_item->name == "���Ѹ���")
		{
			switch (_state)
			{
			case playerState::STAND: case playerState::DOWN_RUN:
				this->changeState(WATER_DOWN);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("watering"));
					}
				}
				break;
			case playerState::STAND_RIGHT: case playerState::RIGHT_RUN:
				this->changeState(WATER_RIGHT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("watering"));
					}
				}
				break;
			case playerState::STAND_LEFT: case playerState::LEFT_RUN:
				this->changeState(WATER_LEFT);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("watering"));
					}
				}
				break;
			case playerState::STAND_BACK: case playerState::UP_RUN:
				this->changeState(WATER_UP);
				if (tile1->getPObj())
				{
					tile1->getPObj()->sendMessage(tagMessage("watering"));
				}
				else if (!tile1->getPObj())
				{
					if (tile2->getPObj())
					{
						tile2->getPObj()->sendMessage(tagMessage("watering"));
					}
				}
				break;
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
	rc.right = _pos.x + _image->getFrameWidth() / 2 ;
	rc.top = _pos.y - _image->getFrameHeight() /2 - 70;
	rc.bottom = _pos.y;

	return rc;
}



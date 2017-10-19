#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "eProgressBar.h"
#include "shadow.h"


void player::stateUpdate(playerState::Enum state)
{
	switch (_state)
	{
	case playerState::STAND:									//�÷��̾ �Ʒ���(��������) ��������
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//�������� �̵����·�	�ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//���������� �̵����·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//���ΰ��� �̵����·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//�Ʒ��ΰ��� �̵����·� �ٲ���
		}
		break;

	case playerState::STAND_RIGHT:								//RIGHT_STAND
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//���������� ��Ӱ���~
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//�������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//���ΰ��� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//�Ʒ��� ���� ���·� �ٲ���
		}
		break;
	case playerState::STAND_LEFT:
		if (KEYMANAGER->isOnceKeyDown('A'))					//LEFT_STAND
		{
			this->changeState(LEFT_RUN);						//�������� ��Ӱ���~
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//���������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//���� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//�Ʒ��� ���� ���·� �ٲ���
		}
		break;
	case playerState::STAND_BACK:
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//��� ���� ����
		}

		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//�Ʒ��� ���� ���·� �ٲ���				
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//�������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//���������� ���� ���·� �ٲ���
		}

		break;

		//================================================================================================�޸��� ���
	case playerState::RIGHT_RUN:								//���������� �̵���
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_pos.x += SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//������ �밢�� �Ʒ��� �̵�
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))
			{
				_pos.y -= SPEED;									//������ �밢�� ���� �̵�
			}
			//tileCollision();
		}
		else if (KEYMANAGER->isOnceKeyUp('D'))
		{
			this->changeState(STAND_RIGHT);
		}
		break;
	case playerState::LEFT_RUN:									//�������� �̵���
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_pos.x -= SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//���� �밢�� �Ʒ��� �̵�
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))			//���� �밢�� ���� �̵�
			{
				_pos.y -= SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('A'))
		{
			this->changeState(STAND_LEFT);
		}

		//_shadow->startAni();
		break;
	case playerState::UP_RUN:									//���� �̵���
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_pos.y -= SPEED;
			if (KEYMANAGER->isStayKeyDown('A'))				//�� �밢�� �������� �̵�
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))		//�� �밢�� ���������� �̵�
			{
				_pos.x += SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('W'))
		{
			this->changeState(STAND_BACK);
		}
		break;
	case playerState::DOWN_RUN:
		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_pos.y += SPEED;

			if (KEYMANAGER->isStayKeyDown('A'))
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))
			{
				_pos.x += SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('S'))
		{
			this->changeState(STAND);
		}
		break;

		//=======================================================================================����
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
	case playerState::PIXHOE_RIGHT:
		break;
	case playerState::PIXHOE_LEFT:
		break;
	case playerState::PIXHOE_UP:
		break;
	case playerState::PIXHOE_DOWN:
		break;
	case playerState::SWORD_RIGHT:
		break;
	case playerState::SWORD_LEFT:
		break;
	case playerState::SWORD_UP:
		break;
	case playerState::SWORD_DOWN:
		break;
		//====================================================================================���� ��� �޸���
	
	case playerState::TAKE_RIGHT:				//��� ���������� �޸��� 
		_myItem.x = _pos.x - CARRYX;				//�������� ��ǥ
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_pos.x += SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//������ �밢�� �Ʒ��� �̵�
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))
			{
				_pos.y -= SPEED;									//������ �밢�� ���� �̵�
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('D'))
		{
			this->changeState(STAND_TAKE_RIGHT);
		}
		break;
	case playerState::TAKE_LEFT:				//��� �������� �޸��� 
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;
	
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_pos.x -= SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//���� �밢�� �Ʒ��� �̵�
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))			//���� �밢�� ���� �̵�
			{
				_pos.y -= SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('A'))
		{
			this->changeState(STAND_TAKE_LEFT);
		}
		break;
	case playerState::TAKE_UP:					//��� ���� �޸��� 
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_pos.y -= SPEED;
			if (KEYMANAGER->isStayKeyDown('A'))				//�� �밢�� �������� �̵�
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))		//�� �밢�� ���������� �̵�
			{
				_pos.x += SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('W'))
		{
			this->changeState(STAND_TAKE_BACK);
		}
		break;
	case playerState::TAKE_DOWN:				//��� �Ʒ��� �޸��� 
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isStayKeyDown('S'))
		{
			_pos.y += SPEED;

			if (KEYMANAGER->isStayKeyDown('A'))
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))
			{
				_pos.x += SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('S'))
		{
			this->changeState(STAND_TAKE);
		}
		break;
	case playerState::STAND_TAKE:				//��� ���ֱ�
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//�������� �̵����·�	�ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//���������� �̵����·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//���ΰ��� �̵����·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//�Ʒ��ΰ��� �̵����·� �ٲ���
		}
		break;

		break;
	case playerState::STAND_TAKE_RIGHT:			//��� ���������� ���ֱ�		
		_myItem.x = _pos.x - CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//���������� ��Ӱ���~
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//�������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//���ΰ��� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//�Ʒ��� ���� ���·� �ٲ���
		}
		break;
	case playerState::STAND_TAKE_LEFT:			//��� �������� ���ֱ�
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;
		
		if (KEYMANAGER->isOnceKeyDown('A'))					//LEFT_STAND
		{
			this->changeState(TAKE_LEFT);						//�������� ��Ӱ���~
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//���������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//���� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//�Ʒ��� ���� ���·� �ٲ���
		}

		break;
	case playerState::STAND_TAKE_BACK:			//��� �ڷ� ���ֱ�
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//��� ���� ����
		}

		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//�Ʒ��� ���� ���·� �ٲ���				
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//�������� ���� ���·� �ٲ���
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//���������� ���� ���·� �ٲ���
		}

		break;
	}

	_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);

	tileCollision();
}


void player::changeState(playerState::Enum state)
{
	switch (state)
	{
	case playerState::STAND:
		_player.Motion = KEYANIMANAGER->findAnimation("playerStand");
		break;
	case playerState::STAND_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("rightStand");
		break;
	case playerState::STAND_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("leftStand");
		break;
	case playerState::STAND_BACK:
		_player.Motion = KEYANIMANAGER->findAnimation("backStand");
		break;
	case playerState::RIGHT_RUN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerRight");
		_player.Motion->start();
		break;
	case playerState::LEFT_RUN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerLeft");
		_player.Motion->start();
		break;
	case playerState::UP_RUN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerUp");
		_player.Motion->start();
		break;
	case playerState::DOWN_RUN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerDown");
		_player.Motion->start();
		break;
	case playerState::AXE_RIGHT:																				//���� 
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeRight");
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		_player.Motion->start();
		break;
	case playerState::AXE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::AXE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::AXE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::HOE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeRight");										//����
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		break;
	case playerState::HOE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::HOE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::HOE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::SICKLE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleRight");		//��
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		break;
	case playerState::SICKLE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::SICKLE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::SICKLE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::PIXHOE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerPixhoeRight");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		break;
	case playerState::PIXHOE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerPixhoeLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::PIXHOE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerPixhoeUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::PIXHOE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerPixhoeDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::SWORD_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSwordRight");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		break;
	case playerState::SWORD_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSwordLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::SWORD_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSwordUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::SWORD_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSwordDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::WATER_RIGHT:												//���Ѹ���
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterRight");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_RIGHT));
		break;
	case playerState::WATER_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterLeft");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_LEFT));
		break;
	case playerState::WATER_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterUp");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND_BACK));
		break;
	case playerState::WATER_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterDown");
		_player.Motion->start();
		this->_player.Motion->setEndMessage(this, tagMessage("changeState", 0.0f, playerState::STAND));
		break;
	case playerState::TAKE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeRight");
		_player.Motion->start();
		break;
	case playerState::TAKE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeLeft");
		_player.Motion->start();
		break;
	case playerState::TAKE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeUp");
		_player.Motion->start();
		break;
	case playerState::TAKE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeDown");
		_player.Motion->start();
		break;
	case playerState::STAND_TAKE:
		_player.Motion = KEYANIMANAGER->findAnimation("playerStandTake");
		_player.Motion->start();
		break;
	case playerState::STAND_TAKE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeStandRight");
		_player.Motion->start();
		break;
	case playerState::STAND_TAKE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeStandLeft");
		_player.Motion->start();
		break;
	case playerState::STAND_TAKE_BACK:
		_player.Motion = KEYANIMANAGER->findAnimation("playerTakeStandUp");
		_player.Motion->start();
		break;

	}
	
	_state = state;
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
}


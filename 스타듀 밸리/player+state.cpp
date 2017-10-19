#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "eProgressBar.h"
#include "shadow.h"


void player::stateUpdate(playerState::Enum state)
{
	switch (_state)
	{
	case playerState::STAND:									//플레이어가 아래로(앞을보고) 서있을때
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 이동상태로	바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//위로가는 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//아래로가는 이동상태로 바껴라
		}
		break;

	case playerState::STAND_RIGHT:								//RIGHT_STAND
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//위로가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라
		}
		break;
	case playerState::STAND_LEFT:
		if (KEYMANAGER->isOnceKeyDown('A'))					//LEFT_STAND
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//위로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라
		}
		break;
	case playerState::STAND_BACK:
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(UP_RUN);							//계속 위로 가렴
		}

		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라				
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 가는 상태로 바껴라
		}

		break;

		//================================================================================================달리는 모션
	case playerState::RIGHT_RUN:								//오른쪽으로 이동중
		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_pos.x += SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//오른쪽 대각선 아래로 이동
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))
			{
				_pos.y -= SPEED;									//오른쪽 대각선 위로 이동
			}
			//tileCollision();
		}
		else if (KEYMANAGER->isOnceKeyUp('D'))
		{
			this->changeState(STAND_RIGHT);
		}
		break;
	case playerState::LEFT_RUN:									//왼쪽으로 이동중
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_pos.x -= SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//왼쪽 대각선 아래로 이동
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))			//왼쪽 대각선 위로 이동
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
	case playerState::UP_RUN:									//위로 이동중
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_pos.y -= SPEED;
			if (KEYMANAGER->isStayKeyDown('A'))				//위 대각선 왼쪽으로 이동
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))		//위 대각선 오른쪽으로 이동
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

		//=======================================================================================무기
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
		//====================================================================================물건 들고 달릴떄
	
	case playerState::TAKE_RIGHT:				//들고 오른쪽으로 달리기 
		_myItem.x = _pos.x - CARRYX;				//아이템의 좌표
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isStayKeyDown('D'))
		{
			_pos.x += SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//오른쪽 대각선 아래로 이동
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))
			{
				_pos.y -= SPEED;									//오른쪽 대각선 위로 이동
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('D'))
		{
			this->changeState(STAND_TAKE_RIGHT);
		}
		break;
	case playerState::TAKE_LEFT:				//들고 왼쪽으로 달리기 
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;
	
		if (KEYMANAGER->isStayKeyDown('A'))
		{
			_pos.x -= SPEED;
			if (KEYMANAGER->isStayKeyDown('S'))				//왼쪽 대각선 아래로 이동
			{
				_pos.y += SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('W'))			//왼쪽 대각선 위로 이동
			{
				_pos.y -= SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('A'))
		{
			this->changeState(STAND_TAKE_LEFT);
		}
		break;
	case playerState::TAKE_UP:					//들고 위로 달리기 
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isStayKeyDown('W'))
		{
			_pos.y -= SPEED;
			if (KEYMANAGER->isStayKeyDown('A'))				//위 대각선 왼쪽으로 이동
			{
				_pos.x -= SPEED;
			}
			else if (KEYMANAGER->isStayKeyDown('D'))		//위 대각선 오른쪽으로 이동
			{
				_pos.x += SPEED;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp('W'))
		{
			this->changeState(STAND_TAKE_BACK);
		}
		break;
	case playerState::TAKE_DOWN:				//들고 아래로 달리기 
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
	case playerState::STAND_TAKE:				//들고 서있기
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//왼쪽으로 이동상태로	바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//오른쪽으로 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//위로가는 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//아래로가는 이동상태로 바껴라
		}
		break;

		break;
	case playerState::STAND_TAKE_RIGHT:			//들고 오른쪽으로 서있기		
		_myItem.x = _pos.x - CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//오른쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//위로가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//아래로 가는 상태로 바껴라
		}
		break;
	case playerState::STAND_TAKE_LEFT:			//들고 왼쪽으로 서있기
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;
		
		if (KEYMANAGER->isOnceKeyDown('A'))					//LEFT_STAND
		{
			this->changeState(TAKE_LEFT);						//왼쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//오른쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//위로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//아래로 가는 상태로 바껴라
		}

		break;
	case playerState::STAND_TAKE_BACK:			//들고 뒤로 서있기
		_myItem.x = _pos.x- CARRYX;
		_myItem.y = _pos.y - CARRYY;

		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			this->changeState(TAKE_UP);							//계속 위로 가렴
		}

		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			this->changeState(TAKE_DOWN);						//아래로 가는 상태로 바껴라				
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			this->changeState(TAKE_LEFT);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			this->changeState(TAKE_RIGHT);						//오른쪽으로 가는 상태로 바껴라
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
	case playerState::AXE_RIGHT:																				//도끼 
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
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeRight");										//괭이
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
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleRight");		//낫
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
	case playerState::WATER_RIGHT:												//물뿌리개
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


#include "stdafx.h"
#include "player.h"
#include "inventory.h"


void player::stateUpdate(playerState::Enum state)
{
	switch (_state)
	{
	case playerState::STAND:									//플레이어가 아래로(앞을보고) 서있을때
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 이동상태로	바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			this->changeState(UP_RUN);							//위로가는 이동상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			this->changeState(DOWN_RUN);						//아래로가는 이동상태로 바껴라
		}
		break;

	case playerState::STAND_RIGHT:								//RIGHT_STAND
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			this->changeState(UP_RUN);							//위로가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라
		}
		break;
	case playerState::STAND_LEFT:
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))					//LEFT_STAND
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 계속가라~
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			this->changeState(UP_RUN);							//위로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라
		}
		break;
	case playerState::STAND_BACK:
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			this->changeState(UP_RUN);							//계속 위로 가렴
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			this->changeState(DOWN_RUN);						//아래로 가는 상태로 바껴라				
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			this->changeState(LEFT_RUN);						//왼쪽으로 가는 상태로 바껴라
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			this->changeState(RIGHT_RUN);						//오른쪽으로 가는 상태로 바껴라
		}

		break;
	case playerState::RIGHT_RUN:								//오른쪽으로 이동중
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_pos.x += 5;
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))				//오른쪽 대각선 아래로 이동
			{
				_pos.y += 5;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				_pos.y -= 5;									//오른쪽 대각선 위로 이동
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			this->changeState(STAND_RIGHT);
		}
		break;
	case playerState::LEFT_RUN:									//왼쪽으로 이동중
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_pos.x -= 5;
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))				//왼쪽 대각선 아래로 이동
			{
				_pos.y += 5;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_UP))			//왼쪽 대각선 위로 이동
			{
				_pos.y -= 5;
			}

		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			this->changeState(STAND_LEFT);
		}
		break;
	case playerState::UP_RUN:									//위로 이동중
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_pos.y -= 5;
			if (KEYMANAGER->isStayKeyDown(VK_LEFT))				//위 대각선 왼쪽으로 이동
			{
				_pos.x -= 5;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))		//위 대각선 오른쪽으로 이동
			{
				_pos.x += 5;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			this->changeState(STAND_BACK);
		}
		break;
	case playerState::DOWN_RUN:
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_pos.y += 5;

			if (KEYMANAGER->isStayKeyDown(VK_LEFT))
			{
				_pos.x -= 5;
			}
			else if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
			{
				_pos.x += 5;
			}
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			this->changeState(STAND);
		}
		break;
	case playerState::AXE_RIGHT:
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			this->changeState(STAND_RIGHT);
		}
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
	case playerState::TAKE_RIGHT:
		break;
	case playerState::TAKE_LEFT:
		break;
	case playerState::TAKE_UP:
		break;
	case playerState::TAKE_DOWN:
		break;
	}
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
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
	case playerState::AXE_RIGHT:											//도끼 
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeRight");
		_player.Motion->start();
		break;
	case playerState::AXE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeLeft");
		_player.Motion->start();
		break;
	case playerState::AXE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeUp");
		_player.Motion->start();
		break;
	case playerState::AXE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerAxeDown");
		_player.Motion->start();
		break;
	case playerState::HOE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeRight");	//괭이
		_player.Motion->start();
		break;
	case playerState::HOE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeLeft");
		_player.Motion->start();
		break;
	case playerState::HOE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeUp");
		_player.Motion->start();
		break;
	case playerState::HOE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerHoeDown");
		_player.Motion->start();
		break;
	case playerState::SICKLE_RIGHT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleRight");	//낫
		_player.Motion->start();
		break;
	case playerState::SICKLE_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleLeft");
		_player.Motion->start();
		break;
	case playerState::SICKLE_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleUp");
		_player.Motion->start();
		break;
	case playerState::SICKLE_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerSickleDown");
		_player.Motion->start();
		break;
	case playerState::WATER_RIGHT:											//물뿌리개
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterRight");
		_player.Motion->start();
		break;
	case playerState::WATER_LEFT:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterLeft");
		_player.Motion->start();
		break;
	case playerState::WATER_UP:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterUp");
		_player.Motion->start();
		break;
	case playerState::WATER_DOWN:
		_player.Motion = KEYANIMANAGER->findAnimation("playerWaterDown");
		_player.Motion->start();
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
	}
	_state = state;
}

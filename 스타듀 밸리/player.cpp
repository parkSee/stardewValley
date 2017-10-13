#include "stdafx.h"
#include "player.h"

HRESULT player::init(string objName, tagFloat pos)
{

	//앞뒤좌우
	int stand[] = { 20 };
	KEYANIMANAGER->addArrayFrameAnimation("playerStand", "player", stand, 1, 0, false);

	int standLeft[] = { 6 };
	KEYANIMANAGER->addArrayFrameAnimation("leftStand", "player", standLeft, 1, 0, false);

	int standRight[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("rightStand", "player", standRight, 1, 0, false);

	int standBack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation("backStand", "player", standBack, 1, 0, false);

	//앞뒤좌우 움직임
	int left[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeft", "player", left, 6, 10, true);

	int up[] = { 12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUp", "player", up, 8, 10, true);
	
	int right[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRight", "player", right, 6, 10, true);

	int down[] = { 20,21,22,23,24,25,26 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDown", "player", down, 7, 10, true);

	//도끼
	int axeLeft[] = { 38,39,40,41,42 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeLeft", "player", axeLeft, 5, 10, true);

	int axeUp[] = { 43,44,45,46 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeUp", "player", axeUp, 4, 10, true);

	int axeRight[] = { 33,34,35,36,37 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeRight", "player", axeRight, 5, 10, true);

	int axeDown[] = { 27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeDown", "player", axeDown, 6, 10, true);

	//괭이
	int hoeLeft[] = { 60,61,62,63,64 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeLeft", "player", hoeLeft, 5, 10, true);

	int hoeUp[] = { 51,52,53,54 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeUp", "player", hoeUp, 4, 10, true);

	int hoeRight[] = { 55,56,57,58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeRight", "player", hoeRight, 5, 10, true);

	int hoeDown[] = { 48,49,50 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeDown", "player", hoeDown, 3, 10, true);

	//낫
	int sickleLeft[] = { 78,79,80,81,82,83 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleLeft", "player", sickleLeft, 6, 10, true);

	int sickleUp[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleUp", "player", sickleUp, 6, 10, true);

	int sickleRight[] = { 72,73,74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleRight", "player", sickleRight, 6, 10, true);

	int sickleDown[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleDown", "player", sickleDown, 6, 10, true);

	//물뿌리개
	int waterLeft[] = { 108,109,110,111,112 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterLeft", "player", waterLeft, 5, 10, true);

	int waterUp[] = { 113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterUp", "player", waterUp, 3, 10, true);

	int waterRight[] = { 90,91,92,93,94 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterRight", "player", waterRight, 5, 10, true);

	int waterDown[] = { 96,97,98,99,100,101,102,103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterDown", "player", waterDown, 12, 10, true);

	//아이템들기
	int takeLeft[] = { 120,121,122,123,124 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeLeft", "player", takeLeft, 5, 10, true);

	int takeUp[] = { 131,132,133,134,135,136 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeUp", "player", takeUp, 6, 10, true);

	int takeRight[] = { 125,126,127,128,129 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeRight", "player", takeRight, 5, 10, true);

	int takeDown[] = { 116,130,138,139,140,141,142 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeDown", "player", takeDown, 7, 10, true);
//========================================================================================================
	
	gameObject::init(objName, "player", tagFloat(WINSIZEX / 2, WINSIZEY / 2), pivot::BOTTOM);
	
	_state = STAND;
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
	_player.Motion = KEYANIMANAGER->findAnimation("playerStand");
	
	//콜백
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((playerState::Enum)msg.data);
	});

	//아이템 먹기 
	this->addCallback("eating", [this](tagMessage msg)
	{
		this->eating();
	});

	//아이템 선택
	this->addCallback("LbuttonClick", [this](tagMessage msg)
	{

	});
	this->addCallback("changeTargetItem", [this](tagMessage msg)
	{

	});

	

	return S_OK;
}
void player::release()
{
	gameObject::release();
}
void player::update() 
{
	gameObject::update();
	this->stateUpdate(_state);

	KEYANIMANAGER->update();
	
}
void player::render() 
{
	//gameObject::render();
	Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);

	_image->aniRender(getMemDC(), _player.rc.left, _player.rc.top,_player.Motion);
	
}

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
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			this->changeState(AXE_RIGHT);
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

void player::eating()
{

}



#include "stdafx.h"
#include "NPC.h"

HRESULT NPC::init(string npcName,char* imageKey, int indexX, int indexY)
{
	gameObject::init(npcName, imageKey, tagFloat(100,100), pivot::BOTTOM);

	_state = STAND;
	_npc.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

	_standUp = "npcStandUp_";
	charstandUp;
	sprintf(charstandUp, "npcStandUp_%s", npcName.c_str());
	int standUp[]{ 8 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charstandUp, imageKey, standUp, 1, 0, false);

	_standDown = "npcStandDown_";
	charstandDown;
	sprintf(charstandDown, "npcStandDown_%s", npcName.c_str());
	int standDown[]{ 0 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charstandDown, imageKey, standDown, 1, 0, false);
	
	_standLeft = "npcStandLeft_";
	charstandLeft;
	sprintf(charstandLeft, "npcStandLeft_%s", npcName.c_str());
	int standLeft[]{ 4 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charstandLeft, imageKey, standLeft, 1, 0, false);
	
	_standRight = "npcStandRight_";
	charstandRight;
	sprintf(charstandRight, "npcStandRight_%s", npcName.c_str());
	int standRight[]{ 12 };
	KEYANIMANAGER->addArrayFrameAnimation(charstandRight, imageKey, standRight, 1, 0, false);
	
	_walkUp = "npcWalkUp_";
	charwalkUp;
	sprintf(charwalkUp, "npcWalkUp_%s", npcName.c_str());
	int walkUp[]{ 8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charwalkUp, imageKey, walkUp, 4, 10, true);
	
	_walkDown = "npcWalkDown_";
	charwalkDown;
	sprintf(charwalkDown, "npcWalkDown_%s", npcName.c_str());
	int walkDown[]{ 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charwalkDown, imageKey, walkDown, 4, 10, true);
	
	_walkLeft = "npcWalkLeft_";
	charwalkLeft;
	sprintf(charwalkLeft, "npcWalkLeft_%s", npcName.c_str());
	int walkLeft[]{ 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charwalkLeft, imageKey, walkLeft, 4, 10, true);
	
	_walkRight = "npcWalkRight_";
	char charwalkRight[sizeof(_walkRight)];
	sprintf(charwalkRight, "npcWalkRight_%s", npcName.c_str());
	int walkRight[]{ 12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation((string)charwalkRight, imageKey, walkRight, 4, 10, true);

	_animation->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());

	_npc.Motion = new animation;

	return S_OK;
}

void NPC::release()
{
	gameObject::release();	
}

void NPC::update()
{
	gameObject::update();

	this->stateUpdate(_state);
}

void NPC::render()
{
	RECT rc = this->getRect();
	_image->scaleAniRender(getMemDC(), rc.left, rc.top, _animation , _image->getFrameWidth() * 4, _image->getFrameHeight() * 4);
}

void NPC::stateUpdate(npcState::Enum state)
{
	//switch (_state)
	//{
	//	case npcState::STAND:								//NPC가 정면(아래)를 보고 서있을 때
	//		if (KEYMANAGER->isOnceKeyDown('W'))
	//		{
	//			this->changeState(WALK_UP);					//위로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('S'))
	//		{
	//			this->changeState(WALK_DOWN);				//아래로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('A'))
	//		{
	//			this->changeState(WALK_LEFT);				//왼쪽으로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('D'))
	//		{
	//			this->changeState(WALK_RIGHT);				//오른쪽으로 움직여라
	//		}
	//		break;
	//		
	//	case npcState::STAND_UP:							//NPC가 위를 보고 서있을 때
	//		if (KEYMANAGER->isOnceKeyDown('W'))
	//		{
	//			this->changeState(WALK_UP);					//위로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('S'))
	//		{
	//			this->changeState(WALK_DOWN);				//아래로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('A'))
	//		{
	//			this->changeState(WALK_LEFT);				//왼쪽으로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('D'))
	//		{
	//			this->changeState(WALK_RIGHT);				//오른쪽으로 움직여라
	//		}
	//		break;
	//
	//	case npcState::STAND_LEFT:							//NPC가 왼쪽을 보고 서있을 때
	//		if (KEYMANAGER->isOnceKeyDown('W'))
	//		{
	//			this->changeState(WALK_UP);					//위로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('S'))
	//		{
	//			this->changeState(WALK_DOWN);				//아래로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('A'))
	//		{
	//			this->changeState(WALK_LEFT);				//왼쪽으로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('D'))
	//		{
	//			this->changeState(WALK_RIGHT);				//오른쪽으로 움직여라
	//		}
	//		break;
	//
	//	case npcState::STAND_RIGHT:							//NPC가 오른쪽을 보고 서있을 때
	//		if (KEYMANAGER->isOnceKeyDown('W'))
	//		{
	//			this->changeState(WALK_UP);					//위로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('S'))
	//		{
	//			this->changeState(WALK_DOWN);				//아래로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('A'))
	//		{
	//			this->changeState(WALK_LEFT);				//왼쪽으로 움직여라
	//		}
	//		if (KEYMANAGER->isOnceKeyDown('D'))
	//		{
	//			this->changeState(WALK_RIGHT);				//오른쪽으로 움직여라
	//		}
	//		break;
	//
	//	case npcState::WALK_UP:								//위로 이동 중일때
	//		if (KEYMANAGER->isStayKeyDown('W'))
	//		{
	//			_pos.y -= 5;
	//
	//			if (KEYMANAGER->isStayKeyDown('A'))
	//			{
	//				_pos.x -= 5;							//왼쪽 대각선 위로 이동
	//			}
	//			if (KEYMANAGER->isStayKeyDown('D'))
	//			{
	//				_pos.x += 5;							//오른쪽 대각선 위로 이동
	//			}
	//		}
	//		else if (KEYMANAGER->isOnceKeyUp('W'))
	//		{
	//			this->changeState(STAND_UP);
	//		}
	//		break;
	//
	//	case npcState::WALK_DOWN:							//아래로 이동 중일때
	//		if (KEYMANAGER->isStayKeyDown('S'))
	//		{
	//			_pos.y += 5;
	//
	//			if (KEYMANAGER->isStayKeyDown('A'))
	//			{
	//				_pos.x -= 5;							//왼쪽 대각선 아래로 이동
	//			}
	//			if (KEYMANAGER->isStayKeyDown('D'))
	//			{
	//				_pos.x += 5;							//오른쪽 대각선 아래로 이동
	//			}
	//		}
	//		else if (KEYMANAGER->isOnceKeyUp('S'))
	//		{
	//			this->changeState(STAND);
	//		}
	//		break;
	//
	//	case npcState::WALK_LEFT:							//왼쪽으로 이동 중일때
	//		if (KEYMANAGER->isStayKeyDown('A'))
	//		{
	//			_pos.x -= 5;
	//
	//			if (KEYMANAGER->isStayKeyDown('W'))
	//			{
	//				_pos.y -= 5;							//왼쪽 대각선 위로 이동
	//			}
	//			if (KEYMANAGER->isStayKeyDown('S'))
	//			{
	//				_pos.y += 5;							//왼쪽 대각선 아래로 이동
	//			}
	//		}
	//		else if (KEYMANAGER->isOnceKeyUp('A'))
	//		{
	//			this->changeState(STAND_LEFT);
	//		}
	//		break;
	//
	//	case npcState::WALK_RIGHT:							//오른쪽으로 이동 중일때
	//		if (KEYMANAGER->isStayKeyDown('D'))
	//		{
	//			_pos.x += 5;
	//
	//			if (KEYMANAGER->isStayKeyDown('W'))
	//			{
	//				_pos.y -= 5;							//오른쪽 대각선 위로 이동
	//			}
	//			if (KEYMANAGER->isStayKeyDown('S'))
	//			{
	//				_pos.y += 5;							//오른쪽 대각선 아래로 이동
	//			}
	//		}
	//		else if (KEYMANAGER->isOnceKeyUp('D'))
	//		{
	//			this->changeState(STAND_RIGHT);
	//		}
	//		break;
	//}
	//_npc.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
}

void NPC::changeState(npcState::Enum state)
{
	//switch (state)
	//{
	//case npcState::STAND:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charstandDown);
	//	break;
	//case npcState::STAND_UP:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charstandUp);
	//	break;
	//case npcState::STAND_LEFT:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charstandLeft);
	//	break;
	//case npcState::STAND_RIGHT:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charstandRight);
	//	break;
	//case npcState::WALK_UP:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charwalkUp);
	//	_npc.Motion->start();
	//	break;
	//case npcState::WALK_DOWN:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charwalkDown);
	//	_npc.Motion->start();
	//	break;
	//case npcState::WALK_LEFT:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charwalkLeft);
	//	_npc.Motion->start();
	//	break;
	//case npcState::WALK_RIGHT:
	//	_npc.Motion = KEYANIMANAGER->findAnimation(charwalkRight);
	//	_npc.Motion->start();
	//	break;
	//}
	//_state = state;
}
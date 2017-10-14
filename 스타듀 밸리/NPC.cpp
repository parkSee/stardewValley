#include "stdafx.h"
#include "NPC.h"

HRESULT NPC::init(string npcName,char* imageKey, int indexX, int indexY)
{
	gameObject::init(npcName, imageKey);

	_state = STAND;
	_npc.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

	_standUp = "npcStandUp_";
	strcat(_standUp, npcName.c_str());
	int standUp[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_standUp, imageKey, standUp, 1, 10, false);

	_standDown = "npcStandDown_";
	strcat(_standDown, npcName.c_str());
	int standDown[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_standDown, imageKey, standDown, 1, 10, false);

	_standLeft = "npcStandLeft_";
	strcat(_standLeft, npcName.c_str());
	int standLeft[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_standLeft, imageKey, standLeft, 1, 10, false);

	_standRight = "npcStandRight_";
	strcat(_standRight, npcName.c_str());
	int standRight[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_standRight, imageKey, standRight, 1, 10, false);

	_walkUp = "npcWalkUp_";
	strcat(_walkUp, npcName.c_str());
	int walkUp[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_walkUp, imageKey, walkUp, 1, 10, false);

	_walkDown = "npcWalkDown_";
	strcat(_walkDown, npcName.c_str());
	int walkDown[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_walkDown, imageKey, walkDown, 1, 10, false);

	_walkLeft = "npcWalkLeft_";
	strcat(_walkLeft, npcName.c_str());
	int walkLeft[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_walkLeft, imageKey, walkLeft, 1, 10, false);

	_walkRight = "npcWalkRight_";
	strcat(_walkRight, npcName.c_str());
	int walkRight[]{ 10 };
	KEYANIMANAGER->addArrayFrameAnimation((string)_walkRight, imageKey, walkRight, 1, 10, false);

	return S_OK;
}

void NPC::release()
{
	gameObject::release();
}

void NPC::update(int indexX, int indexY)
{
	gameObject::update();

}

void NPC::render()
{

}

void NPC::stateUpdate(npcState::Enum state)
{
	switch (state)
	{
		case npcState::STAND:								//NPC가 정면(아래)를 보고 서있을 때
		{
			if ()
			{
				this->changeState(WALK_UP);					//위로 움직여라
			}
			if ()
			{
				this->changeState(WALK_DOWN);				//아래로 움직여라
			}
			if ()
			{
				this->changeState(WALK_LEFT);				//왼쪽으로 움직여라
			}
			if ()
			{
				this->changeState(WALK_RIGHT);				//오른쪽으로 움직여라
			}
			break;
		}
	}
}

void NPC::changeState(npcState::Enum state)
{
	switch (state)
	{
		case npcState::STAND:
			_npc.Motion = KEYANIMANAGER->findAnimation("npcStand");
			break;
		case npcState::STAND_UP:
			_npc.Motion = KEYANIMANAGER->findAnimation("upStand");
			break;
		case npcState::STAND_LEFT:
			_npc.Motion = KEYANIMANAGER->findAnimation("leftStand");
			break;
		case npcState::STAND_RIGHT:
			_npc.Motion = KEYANIMANAGER->findAnimation("rightStand");
			break;
		case npcState::WALK_UP:
			_npc.Motion = KEYANIMANAGER->findAnimation("upWalk");
			_npc.Motion->start();
			break;
		case npcState::WALK_DOWN:
			_npc.Motion = KEYANIMANAGER->findAnimation("downWalk");
			_npc.Motion->start();
			break;
		case npcState::WALK_LEFT:
			_npc.Motion = KEYANIMANAGER->findAnimation("leftWalk");
			_npc.Motion->start();
			break;
		case npcState::WALK_RIGHT:
			_npc.Motion = KEYANIMANAGER->findAnimation("rightWalk");
			_npc.Motion->start();
			break;
	}
}
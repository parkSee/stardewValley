#include "stdafx.h"
#include "npc.h"

void npc::changeState(npcDirection::Enum direction)
{
	switch (direction)
	{
	case npcDirection::STAND_DOWN:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.standDown);
		_animation->start();
	}
		break;
	case npcDirection::STAND_UP:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.standUp);
		_animation->start();
	}
		break;
	case npcDirection::STAND_LEFT:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.standLeft);
		_animation->start();
	}
		break;
	case npcDirection::STAND_RIGHT:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.standRight);
		_animation->start();
	}
		break;
	case npcDirection::MOVE_DOWN:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.moveDown);
		_animation->start();
	}
		break;
	case npcDirection::MOVE_UP:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.moveUp);
		_animation->start();
	}
		break;
	case npcDirection::MOVE_RIGHT:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.moveRight);
		_animation->start();
	}
		break;
	case npcDirection::MOVE_LEFT:
	{
		_animation = KEYANIMANAGER->findAnimation(_keyAniString.moveLeft);
		_animation->start();
	}
		break;
	default:
		break;
	}
	_direction = direction;
}

void npc::stateUpdate()
{
	switch (_direction)
	{
	case npcDirection::STAND_DOWN:
		break;
	case npcDirection::STAND_UP:
		break;
	case npcDirection::STAND_LEFT:
		break;
	case npcDirection::STAND_RIGHT:
		break;
	case npcDirection::MOVE_DOWN:
		break;
	case npcDirection::MOVE_UP:
		break;
	case npcDirection::MOVE_RIGHT:
		break;
	case npcDirection::MOVE_LEFT:
		break;
	default:
		break;
	}
}
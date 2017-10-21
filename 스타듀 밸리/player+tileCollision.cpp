#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "shadow.h"


void player::tileCollision()
{
	int centerX, centerY;


	switch (_state)
	{
	case playerState::STAND:

		//centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().left + TILESIZE / 2;
		//
		//_tile1 = TOWNWORLD->getTile(_indexX, _indexY + 1);
		//
		//if (centerX < _tilePos.x)
		//{
		//	_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
		//}
		//else if (centerX > _tilePos.x)
		//{
		//	_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY + 1);
		//}

		break;
	case playerState::STAND_RIGHT:
		break;
	case playerState::STAND_LEFT:
		break;
	case playerState::STAND_BACK:
		break;
	case playerState::TAKE_DOWN: case playerState::DOWN_RUN:

		//centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().left + TILESIZE / 2;
		//
		//_tile1 = TOWNWORLD->getTile(_indexX, _indexY + 1);
		//
		//if (centerX < _tilePos.x)
		//{
		//	_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY + 1);
		//}
		//else if (centerX > _tilePos.x)
		//{
		//	_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
		//}
		break;

	case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:
	
		break;
	case playerState::TAKE_LEFT: case playerState::LEFT_RUN:

		
		break;
	case playerState::TAKE_UP: case playerState::UP_RUN:

		
		break;

	}

		RECT _rc1;				//충돌 확인할 렉트
		RECT _rc2;				// 이하동문


}


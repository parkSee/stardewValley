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

		centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().left + TILESIZE / 2;

		_tile1 = TOWNWORLD->getTile(_indexX, _indexY + 1);

		if (centerX < _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
		}
		else if (centerX > _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY + 1);
		}

		break;
	case playerState::STAND_RIGHT:
		break;
	case playerState::STAND_LEFT:
		break;
	case playerState::STAND_BACK:
		break;
	case playerState::TAKE_DOWN: case playerState::DOWN_RUN:

		centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().left + TILESIZE / 2;

		_tile1 = TOWNWORLD->getTile(_indexX, _indexY + 1);

		if (centerX < _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
		}
		else if (centerX > _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY + 1);
		}
		break;
	case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:
		centerY = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;

		_tile1 = TOWNWORLD->getTile(_indexX + 1, _indexY);
		if (centerY < _tilePos.y)
		{
			_tile2 = TOWNWORLD->getTile(_indexX + 1, +_indexY + 1);
		}
		else if (centerY > _tilePos.y)
		{
			_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY - 1);
		}
		break;
	case playerState::TAKE_LEFT: case playerState::LEFT_RUN:

		centerY = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;

		_tile1 = TOWNWORLD->getTile(_indexX - 1, _indexY);

		if (centerY < _tilePos.y)
		{
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
		}
		else if (centerY > _tilePos.y)
		{
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY - 1);
		}
		break;
	case playerState::TAKE_UP: case playerState::UP_RUN:

		centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;

		_tile1 = TOWNWORLD->getTile(_indexX, _indexY - 1);

		if (centerX < _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY - 1);
		}
		else if (centerX > _tilePos.x)
		{
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY - 1);
		}
		break;

	}


	RECT _rc1;				//충돌 확인할 렉트
	RECT _rc2;				// 이하동문

							//if (_tile1->getPObj() != NULL)
							//{
							//	exit(0);
							//	if (_state == AXE_LEFT)
							//	{
							//		tree1_bottom* _target = (tree1_bottom*)TOWNWORLD->findObject(objectType::OBJ, "tree1_bottom");
							//		_target->sendMessage(tagMessage("treeTarget"));
							//	
							//	}
							//	
							//
							//}

	if (IntersectRect(&_rc1, &_tile1->getRect(), &_rcCollision))
	{
		if (!_tile1->getIsMovable())							//타일이 갈수 없는 타일이면
		{
			if (!_tile1->getPObj())								//오브젝트가 없다면
			{
				switch (_state)
				{
				case playerState::TAKE_UP: case playerState::UP_RUN:

					_pos.y += SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x -= SPEED;
					}
					break;
				case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

					_pos.x -= SPEED;
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y += SPEED;
					}
					break;
				case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
					
					_pos.x += SPEED;
					
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y += SPEED;
					}
					break;
				case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
					_pos.y -= SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x -= SPEED;
					}
					break;
				}
			}

			else if (_tile1->getPObj())							// 타일위에 오브젝트가 있으면
			{

			}
		}
		else if (_tile1->getIsMovable())						//타일이 갈수 있는 타일이면	
		{
			if (!_tile1->getPObj())								//타일위에 오브젝트가 없으면
			{
				switch (_state)
				{
				case playerState::TAKE_UP: case playerState::UP_RUN:

					_pos.y -= SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x += SPEED;
					}
					break;
				case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

					_pos.x += SPEED;
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y -= SPEED;
					}
					break;
				case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
					_pos.x -= SPEED;
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y -= SPEED;
					}
					break;
				case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
					_pos.y += SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x += SPEED;
					}
					break;
				}
			}

			else if (_tile1->getPObj())								//타일 위에 오브젝트가 있으면
			{
				switch (_state)
				{
				case playerState::TAKE_UP: case playerState::UP_RUN:

					_pos.y += SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x -= SPEED;
					}
					break;
				case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

					_pos.x -= SPEED;
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y += SPEED;
					}
					break;
				case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
					_pos.x += SPEED;
					if (KEYMANAGER->isStayKeyDown('S'))
					{
						_pos.y -= SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('W'))
					{
						_pos.y += SPEED;
					}
					break;
				case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
					_pos.y -= SPEED;
					if (KEYMANAGER->isStayKeyDown('A'))
					{
						_pos.x += SPEED;
					}
					else if (KEYMANAGER->isStayKeyDown('D'))
					{
						_pos.x -= SPEED;
					}
					break;
				}
			}
		}
	}

		if (IntersectRect(&_rc2, &_tile2->getRect(), &_rcCollision))
		{
			if (_tile1->getIsMovable())
			{
				if (!_tile2->getIsMovable())					//타일이 갈수 없는 타일이고
				{
					if (!_tile2->getPObj())								//오브젝트가 없다면
					{
						switch (_state)
						{
						case playerState::TAKE_UP: case playerState::UP_RUN:

							_pos.y += SPEED;
							if (KEYMANAGER->isStayKeyDown('A'))
							{
								_pos.x += SPEED;
							}
							else if (KEYMANAGER->isStayKeyDown('D'))
							{
								_pos.x -= SPEED;
							}
							break;
						case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

							_pos.x -= SPEED;
							if (KEYMANAGER->isStayKeyDown('S'))
							{
								_pos.y -= SPEED;
							}
							else if (KEYMANAGER->isStayKeyDown('W'))
							{
								_pos.y += SPEED;
							}
							break;
						case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
							_pos.x += SPEED;
							if (KEYMANAGER->isStayKeyDown('S'))
							{
								_pos.y -= SPEED;
							}
							else if (KEYMANAGER->isStayKeyDown('W'))
							{
								_pos.y += SPEED;
							}
							break;
						case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
							_pos.y -= SPEED;
							if (KEYMANAGER->isStayKeyDown('A'))
							{
								_pos.x += SPEED;
							}
							else if (KEYMANAGER->isStayKeyDown('D'))
							{
								_pos.x -= SPEED;
							}
							break;
						}
					}

					else if (_tile2->getPObj())							// 타일위에 오브젝트가 있으면
					{

					}
				}
			}
			else if (_tile2->getIsMovable())						//타일이 갈수 있는 타일이면	
			{
				if (!_tile2->getPObj())								//타일위에 오브젝트가 없으면
				{
					switch (_state)
					{
					case playerState::TAKE_UP: case playerState::UP_RUN:

						_pos.y -= SPEED;
						if (KEYMANAGER->isStayKeyDown('A'))
						{
							_pos.x -= SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('D'))
						{
							_pos.x += SPEED;
						}
						break;
					case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

						_pos.x += SPEED;
						if (KEYMANAGER->isStayKeyDown('S'))
						{
							_pos.y += SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('W'))
						{
							_pos.y -= SPEED;
						}
						break;
					case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
						_pos.x -= SPEED;
						if (KEYMANAGER->isStayKeyDown('S'))
						{
							_pos.y += SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('W'))
						{
							_pos.y -= SPEED;
						}
						break;
					case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
						_pos.y += SPEED;
						if (KEYMANAGER->isStayKeyDown('A'))
						{
							_pos.x -= SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('D'))
						{
							_pos.x += SPEED;
						}
						break;
					}
				}

				else if (_tile2->getPObj())								//타일 위에 오브젝트가 있으면
				{
					switch (_state)
					{
					case playerState::TAKE_UP: case playerState::UP_RUN:

						_pos.y += SPEED;
						if (KEYMANAGER->isStayKeyDown('A'))
						{
							_pos.x += SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('D'))
						{
							_pos.x -= SPEED;
						}
						break;
					case playerState::TAKE_RIGHT: case playerState::RIGHT_RUN:

						_pos.x -= SPEED;
						if (KEYMANAGER->isStayKeyDown('S'))
						{
							_pos.y -= SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('W'))
						{
							_pos.y += SPEED;
						}
						break;
					case playerState::TAKE_LEFT: case playerState::LEFT_RUN:
						_pos.x += SPEED;
						if (KEYMANAGER->isStayKeyDown('S'))
						{
							_pos.y -= SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('W'))
						{
							_pos.y += SPEED;
						}
						break;
					case playerState::TAKE_DOWN: case playerState::DOWN_RUN:
						_pos.y -= SPEED;
						if (KEYMANAGER->isStayKeyDown('A'))
						{
							_pos.x += SPEED;
						}
						else if (KEYMANAGER->isStayKeyDown('D'))
						{
							_pos.x -= SPEED;
						}
						break;
					}
				}
			}
			}
	
		}

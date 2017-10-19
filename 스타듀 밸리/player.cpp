#include "stdafx.h"
#include "player.h"
#include "inventory.h"

HRESULT player::init(string objName, tagFloat pos)
{


	//�յ��¿�
	int stand[] = { 20 };
	KEYANIMANAGER->addArrayFrameAnimation("playerStand", "player", stand, 1, 0, false);

	int standLeft[] = { 6 };
	KEYANIMANAGER->addArrayFrameAnimation("leftStand", "player", standLeft, 1, 0, false);

	int standRight[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("rightStand", "player", standRight, 1, 0, false);

	int standBack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation("backStand", "player", standBack, 1, 0, false);

	//�յ��¿� ������
	int left[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeft", "player", left, 6, 10, true);

	int up[] = { 12,13,14,15,16,17,18,19 };
	KEYANIMANAGER->addArrayFrameAnimation("playerUp", "player", up, 8, 10, true);
	
	int right[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRight", "player", right, 6, 10, true);

	int down[] = { 20,21,22,23,24,25,26 };
	KEYANIMANAGER->addArrayFrameAnimation("playerDown", "player", down, 7, 10, true);

	//����
	int axeLeft[] = { 38,39,40,41,42 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeLeft", "player", axeLeft, 5, 10, false);

	int axeUp[] = { 43,44,45,46 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeUp", "player", axeUp, 4, 10, false);

	int axeRight[] = { 33,34,35,36,37 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeRight", "player", axeRight, 5, 10, false);

	int axeDown[] = { 27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeDown", "player", axeDown, 6, 10, false);

	//����
	int hoeLeft[] = { 60,61,62,63,64 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeLeft", "player", hoeLeft, 5, 10, false);

	int hoeUp[] = { 51,52,53,54 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeUp", "player", hoeUp, 4, 10, false);

	int hoeRight[] = { 55,56,57,58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeRight", "player", hoeRight, 5, 10, false);

	int hoeDown[] = { 48,49,50 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeDown", "player", hoeDown, 3, 10, false);

	//��
	int sickleLeft[] = { 78,79,80,81,82,83 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleLeft", "player", sickleLeft, 6, 15, false);

	int sickleUp[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleUp", "player", sickleUp, 6, 15, false);

	int sickleRight[] = { 72,73,74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleRight", "player", sickleRight, 6, 15, false);

	int sickleDown[] = { 65,66,67,68,69,70,71 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleDown", "player", sickleDown, 6, 15, false);

	//���Ѹ���
	int waterLeft[] = { 108,109,110,111,112 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterLeft", "player", waterLeft, 5, 7, false);

	int waterUp[] = { 113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterUp", "player", waterUp, 3, 7, false);

	int waterRight[] = { 90,91,92,93,94 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterRight", "player", waterRight, 5, 7, false);

	int waterDown[] = { 96,97,98,99,100,101,102,103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterDown", "player", waterDown, 12, 20, false);

	//���
	int pixhoeDown[] = { 168,169,170,171,172,173,174 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeDown", "player", pixhoeDown, 7, 10, false);

	int pixhoeUP[] = { 175,176,177,178 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeUp", "player", pixhoeUP, 4, 10, false);

	int pixhoeRight[] = { 180,181,182,183,184 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeRight", "player", pixhoeRight, 5, 10, false);

	int pixhoeLeft[] = { 189,188,187,186,185 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeLeft", "player", pixhoeLeft, 5, 10, false);

	//��
	int swordDown[] = { 143,144,145,146,147,148 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordDown", "player", swordDown, 6, 10, false);
	
	int swordRight[] = { 149,150,151,152,153,154 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordRight", "player", swordRight, 6, 10, false);

	int swordLeft[] = { 155,156,157,158,159,160 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordLeft", "player", swordLeft, 6, 10, false);

	int swordUp[] = { 161,162,163 };
	KEYANIMANAGER->addArrayFrameAnimation("playerswordUp", "player", swordUp, 3, 10, false);

	//������ ��� �޸���
	int takeLeft[] = { 120,121,122,123,124 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeLeft", "player", takeLeft, 5, 10, true);

	int takeUp[] = { 132,133,134,135,136,137 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeUp", "player", takeUp, 6, 10, true);

	int takeRight[] = { 125,126,127,128,129 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeRight", "player", takeRight, 5, 10, true);

	int takeDown[] = { 130,131,139,140,141,142,143 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeDown", "player", takeDown, 7, 10, true);

	//������ ��� ���ֱ�
	int standTake[] = { 116 };
	KEYANIMANAGER->addArrayFrameAnimation("playerStandTake", "player", standTake, 1, 0, false);

	int standTakeLeft[] = { 120 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandLeft", "player", standTakeLeft, 1, 0, false);

	int standTakeRight[] = { 125 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandRight", "player", standTakeRight, 1, 0, false);

	int standTakeUp[] = { 134 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandUp", "player", standTakeUp, 1, 0, false);

//========================================================================================================
	
	gameObject::init(objName, "player", tagFloat(WINSIZEX / 2, WINSIZEY / 2), pivot::BOTTOM);
	
	_state = STAND;
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth() /2, _image->getFrameHeight()/2);	
	_player.Motion = KEYANIMANAGER->findAnimation("playerStand");

	_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);										//�÷��̾� �߹� �浹��Ʈ

	_tilePos.x = _rcCollision.left + (_rcCollision.right - _rcCollision.left) / 2;					//Ÿ��pos�� ���� ���� ������ ?
	_tilePos.y = _rcCollision.bottom;

	_indexX = (int)(_tilePos.x / (TILESIZE));														//���� �ε��� ��ȣ�� ���Ҷ� ���� �����ϰ� �������ؼ��� �ִ�.
	_indexY = (int)(_tilePos.y / (TILESIZE));


	tem = tagItem("����", "������ �� �� �ִ�", tagFloat(1000000,10000000), 1, itemType::TOOL);		//������ �ʱⰪ
	_item = &tem;

	_tile1 = NULL;
	_tile2 = NULL;

	_myItem.x = 0;
	_myItem.y = 0;

	//�ݹ�
	this->addCallback("changeState", [this](tagMessage msg)											//Ư���������� �� ���� ���� ���������� ���ƿͶ�! ����ϴ� �ݹ�
	{
		this->changeState((playerState::Enum)msg.data);
	});

	//������ �Ա� 
	this->addCallback("eating", [this](tagMessage msg)												//�ָ�������?
	{
		this->eating();
	});

	//��� Ŭ��
	this->addCallback("lbuttonClick", [this](tagMessage msg)										//���콺���� �޼����� ������ Ư�� Ÿ���� ���ý� �Ǵ� Ư�� ���·� ��ȯ�ϰ�
	{																								//����� ��, ���콺�� ����ϱ����� �ݹ�1
		this->lbuttonClick(msg);
	});


	this->addCallback("changeTargetItem", [this](tagMessage msg)									//���콺�� ���� ������ �Ǵ� ������ �����ϸ� �׿� �´� ���·� ��ȯ��Ű�� 
	{																								//���콺�� ����ϱ� ���� �ݹ�2
		this->changeTargetItem(msg);
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

	_tilePos.x = _rcCollision.left + (_rcCollision.right - _rcCollision.left) / 2;					
	_tilePos.y = _rcCollision.bottom;

	_indexX = (int)(_tilePos.x / (TILESIZE));			//���� �ε��� ��ȣ X						//�ǽð����� ���� ���Ÿ�Ͽ� �ִ��� ��ġ�� ã���ְ� �־����
	_indexY = (int)(_tilePos.y / (TILESIZE));			//���� �ε��� ��ȣ Y


	if (WORLDTIME->_isTimeFlow)																	//UI�� ������ �������� �ʴ´�. 
	{																							//(���ӻ� �ð��� �帧 - UI�� ������ �ð��� ���߸鼭 Ű�� �ð��� �����.)
		this->stateUpdate(_state);
	}
	
	if (KEYMANAGER->isOnceKeyDown('Y'))															//���콺Ŭ���� ���� �������� ����� ���� Ű
	{
		this->sendMessage(tagMessage("lbuttonClick"));
	}

	KEYANIMANAGER->update();

	_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

}
void player::render()
{
	//gameObject::render();
	
	RECT rc = CAMERAMANAGER->getRenderRc();

	_image->aniRender(getMemDC(), this->rectMakeBottom().left - rc.left,										// �̹��� ���� 
		this->rectMakeBottom().top - rc.top, _player.Motion);
	//Rectangle(getMemDC(), _player.rc.left -rc.left , _player.rc.top-rc.top, 
	//	_player.rc.right-rc.left, _player.rc.bottom-rc.top);				//���� �÷��̾� ��Ʈ
	//Rectangle(getMemDC(), this->rectMakeBottom().left - rc.left, this->rectMakeBottom().top - rc.top,			//_pos ��ǥ ������Ʈ �� �÷��̾� �� ��Ʈ
	//	this->rectMakeBottom().right - rc.left, this->rectMakeBottom().bottom - rc.top);

	//RectangleMakeCenter(getMemDC(), _pos.x - rc.left, _pos.y - rc.top, 30, 30);									//_pos ��ǥ

	Rectangle(getMemDC(), _rcCollision.left - rc.left, _rcCollision.top - rc.top,								//Ÿ�� �浹��Ʈ
		_rcCollision.right - rc.left, _rcCollision.bottom - rc.top);

	//Rectangle(getMemDC(), _tilePos.x - rc.left, _tilePos.y - rc.top, 50, 50);

	

	if (_state == STAND_TAKE || _state == STAND_TAKE_LEFT || _state == STAND_TAKE_RIGHT ||						//�������� ����ִ� �����϶��� �׸���.
		_state == STAND_TAKE_BACK || _state == TAKE_UP || _state == TAKE_LEFT || _state == TAKE_RIGHT || _state == TAKE_DOWN)
	{
		_myItem.img->render(getMemDC(), _myItem.x - rc.left, _myItem.y - rc.top);								//������ ����
	}
	
	if (_tile1 != NULL && _tile2 != NULL)
	{
		RECT rc1 = _tile1->getRect();
		RECT rc2 = _tile2->getRect();

		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);

		Rectangle(getMemDC(), rc1.left - rc.left, rc1.top-rc.top, rc1.right-rc.left, rc1.bottom-rc.top);		//�÷��̾� �ٷ� �� Ÿ��
		Rectangle(getMemDC(), rc2.left - rc.left, rc2.top - rc.top, rc2.right - rc.left, rc2.bottom - rc.top);	//�÷��̾� �� Ÿ��

		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);

		char str[100];
		sprintf(str, "%d,%d", _indexX, _indexY);
		TextOut(getMemDC(), 10, 300, str, strlen(str));
	}
	//EllipseMakeCenter(getMemDC(), _pos.x-rc.left, _pos.y-rc.top, 10, 10);
}

void player::tileCollision()
{
	int centerX, centerY;


	switch (_state)
	{
	case playerState::STAND:

		centerX = TOWNWORLD->getTile(_indexX,_indexY)->getRect().left + TILESIZE / 2;

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
			_tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY+1);
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
	

	RECT _rc1;				//�浹 Ȯ���� ��Ʈ
	RECT _rc2;				// ���ϵ���
	
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

	if (_tile1 != NULL)
	{
		if (IntersectRect(&_rc1, &_tile1->getRect(), &_rcCollision))
		{
			if (_tile1->getTerrain() == TERRAIN::WATER)
			{
				switch (_state)
				{
				case playerState::STAND:
					break;
				case playerState::STAND_RIGHT:

					break;
				case playerState::STAND_LEFT:
					break;
				case playerState::STAND_BACK:
					break;
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
		return;
	}

	if (_tile2 != NULL)
	{
		if (IntersectRect(&_rc2, &_tile2->getRect(), &_rcCollision))
		{
			if (_tile1->getTerrain() != TERRAIN::WATER)
			{
				if (_tile2->getTerrain() == TERRAIN::WATER)
				{
					switch (_state)
					{
					case playerState::STAND:
						break;
					case playerState::STAND_RIGHT:
						break;
					case playerState::STAND_LEFT:
						break;
					case playerState::STAND_BACK:
						break;
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
		return;
	}


}





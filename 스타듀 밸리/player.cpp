#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include "shadow.h"
#include "selectUI.h"

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
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleLeft", "player", sickleLeft, 6, 10, false);

	int sickleUp[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleUp", "player", sickleUp, 6, 10, false);

	int sickleRight[] = { 72,73,74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleRight", "player", sickleRight, 6, 10, false);

	int sickleDown[] = { 65,66,67,68,69,70,71 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleDown", "player", sickleDown, 6, 10, false);

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

	//���� �ȳ�
	int qustionEat[] = { 192 };
	KEYANIMANAGER->addArrayFrameAnimation("playerQustionEat", "player", qustionEat, 1, 0, false);

	int eating[] = { 193,194,195,196,197,198,199,200,201, };
	KEYANIMANAGER->addArrayFrameAnimation("playerEating", "player", eating, 9, 8, false);

//========================================================================================================
	
	gameObject::init(objName, "player", tagFloat(WINSIZEX / 2, WINSIZEY / 2), pivot::BOTTOM);
	
	_state = STAND;
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth() /2, _image->getFrameHeight()/2);	
	_player.Motion = KEYANIMANAGER->findAnimation("playerStand");

	_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);										//�÷��̾� �߹� �浹��Ʈ
	_eatingRc = RectMakeCenter(_pos.x, _pos.y - 80, 20, 20);

	_tilePos.x = _rcCollision.left + (_rcCollision.right - _rcCollision.left) / 2;					//Ÿ��pos�� ���� ���� ������ ?
	_tilePos.y = _rcCollision.bottom;

	_indexX = (int)(_tilePos.x / (TILESIZE));														//���� �ε��� ��ȣ�� ���Ҷ� ���� �����ϰ� �������ؼ��� �ִ�.
	_indexY = (int)(_tilePos.y / (TILESIZE));

	_shadow = new shadow;
	_shadow->init(objName, "shadow",tagFloat( this->_pos.x - 30, this->_pos.y));

	tem = tagItem("����", "������ �� �� �ִ�", tagFloat(1000000, 10000000), 1, itemType::TOOL);
	_item = &tem;

	tile1 =TOWNWORLD->getTile(_indexX,_indexY);
	tile2 = TOWNWORLD->getTile(_indexX-1,_indexY);


	_myItem.img = _item->img;
	_myItem.x = 0;
	_myItem.y = 0;
	_myItem.gravity = 0.5f;
	_myItem.jumpPower = 5.0f;

	_eatCenter.x = _pos.x;
	_eatCenter.y = _pos.y - 60;

	//�ݹ�
	this->addCallback("changeState", [this](tagMessage msg)											//Ư���������� �� ���� ���� ���������� ���ƿͶ�! ����ϴ� �ݹ�
	{
		this->changeState((playerState::Enum)msg.data);
	});

	//������ �Ա� 
	this->addCallback("eating", [this](tagMessage msg)												//�ָ�������?
	{
		this->eating(msg);
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
	_shadow->release();
}
void player::update() 
{
	gameObject::update();

	_tilePos.x = _rcCollision.left + (_rcCollision.right - _rcCollision.left) / 2;					
	_tilePos.y = _rcCollision.bottom;

	_indexX = (int)(_tilePos.x / (TILESIZE));			//���� �ε��� ��ȣ X						//�ǽð����� ���� ���Ÿ�Ͽ� �ִ��� ��ġ�� ã���ְ� �־����
	_indexY = (int)(_tilePos.y / (TILESIZE));			//���� �ε��� ��ȣ Y

	_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);

	this->playerRun();

	if (WORLDTIME->_isTimeFlow)																	//UI�� ������ �������� �ʴ´�. 
	{																							//(���ӻ� �ð��� �帧 - UI�� ������ �ð��� ���߸鼭 Ű�� �ð��� �����.)
		this->stateUpdate(_state);
	}
	
	if (KEYMANAGER->isOnceKeyDown('Y'))															//���콺Ŭ���� ���� �������� ����� ���� Ű
	{
		this->sendMessage(tagMessage("lbuttonClick"));
	}
	

	KEYANIMANAGER->update();

	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
	_eatingRc = RectMakeCenter(_pos.x, _pos.y-80, 20,20);
	_shadow->_pos.x = this->_pos.x;
	_shadow->_pos.y = this->_pos.y -20;

	_shadow->update();

	if (_indexX == 15 && _indexY == 93 && WORLDTIME->_isTimeFlow ==true)
	{
		selectUI* select = (selectUI*)TOWNWORLD->findObject(objectType::INTERFACE, "selectUI");
		select->sendMessage(tagMessage("selectEat", 0, 0, 0, vector<gameObject*>(), "�����?"));
		select->setCb([]() 
		{
			WORLDTIME->dayGone();

		});
	}
}

void player::render()
{
	//gameObject::render();
	
	RECT rc = CAMERAMANAGER->getRenderRc();

	_image->aniRender(getMemDC(), this->rectMakeBottom().left - rc.left,										// �̹��� ���� 
		this->rectMakeBottom().top - rc.top, _player.Motion);
	//Rectangle(getMemDC(), _eatingRc.left - rc.left, _eatingRc.top - rc.top, _eatingRc.right - rc.left, _eatingRc.bottom-rc.top);

	//Rectangle(getMemDC(), _player.rc.left -rc.left , _player.rc.top-rc.top, 
	//	_player.rc.right-rc.left, _player.rc.bottom-rc.top);				//���� �÷��̾� ��Ʈ
	//Rectangle(getMemDC(), this->rectMakeBottom().left - rc.left, this->rectMakeBottom().top - rc.top,			//_pos ��ǥ ������Ʈ �� �÷��̾� �� ��Ʈ
	//	this->rectMakeBottom().right - rc.left, this->rectMakeBottom().bottom - rc.top);

	//RectangleMakeCenter(getMemDC(), _pos.x - rc.left, _pos.y - rc.top, 30, 30);									//_pos ��ǥ

	//Rectangle(getMemDC(), _rcCollision.left - rc.left, _rcCollision.top - rc.top,								//Ÿ�� �浹��Ʈ
	//	_rcCollision.right - rc.left, _rcCollision.bottom - rc.top);

	//Rectangle(getMemDC(), _tilePos.x - rc.left, _tilePos.y - rc.top, 50, 50);

	//RectangleMake(getMemDC(), (_myItem.x-10) - rc.left, (_myItem.y +40)- rc.top, 20, 20);

	
	if (_myItem.img != NULL)
	{
		if (_state == STAND_TAKE || _state == STAND_TAKE_LEFT || _state == STAND_TAKE_RIGHT ||						//�������� ����ִ� �����϶��� �׸���.
			_state == STAND_TAKE_BACK || _state == TAKE_UP || _state == TAKE_LEFT || _state == TAKE_RIGHT || _state == TAKE_DOWN ||
			_state == EATING)
		{
			_myItem.img->render(getMemDC(), _myItem.x - (_myItem.img->getWidth()/2-10) - rc.left, _myItem.y - (_myItem.img->getHeight()/2 -20) - rc.top);								//������ ����
		}
	}
	
	//if (tile1 != NULL && tile2 != NULL)
	//{
	//	RECT rc1 = tile1->getRect();
	//	RECT rc2 = tile2->getRect();
	//
	//	HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
	//	HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
	//
	//	Rectangle(getMemDC(), rc1.left - rc.left, rc1.top-rc.top, rc1.right-rc.left, rc1.bottom-rc.top);		//�÷��̾� �ٷ� �� Ÿ��
	//	Rectangle(getMemDC(), rc2.left - rc.left, rc2.top - rc.top, rc2.right - rc.left, rc2.bottom - rc.top);	//�÷��̾� �� Ÿ��
	//
	//	SelectObject(getMemDC(), oldBrush);
	//	DeleteObject(brush);
	//
	//	char str[100];
	//	sprintf(str, "%d,%d", _indexX, _indexY);
	//	TextOut(getMemDC(), 10, 300, str, strlen(str));
	//
	//	sprintf_s(str, "%f,%f",_myItem.x, _myItem.y);
	//	TextOut(getMemDC(), 10, 400, str, strlen(str));
	//}
	_shadow->render();

}

void player::playerRun()
{
	switch (_state)
	{

	case playerState::RIGHT_RUN:	case playerState::TAKE_RIGHT:
	case playerState::LEFT_RUN:		case playerState::TAKE_LEFT:
	case playerState::UP_RUN:		case playerState::TAKE_UP:
	case playerState::DOWN_RUN:		case playerState::TAKE_DOWN:
		int centerX, centerY;

		RECT temp;
		if (KEYMANAGER->isStayKeyDown('W'))
		{
			centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;
			
			tile1 = TOWNWORLD->getTile(_indexX, _indexY - 1);
			
			if (centerX < _tilePos.x)
			{
				tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY - 1);
			}
			else if (centerX > _tilePos.x)
			{
				tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY - 1);
			}
			
			if (IntersectRect(&temp, &tile1->getRect(), &_rcCollision))
			{
				if (!tile1->getIsMovable())							//Ÿ���� ���� ���� Ÿ���̸�
				{
					//�Ȱ���
				}
				else if (tile1->getIsMovable())						//Ÿ���� ���� �ִ� Ÿ���̸�	
				{
					if (!tile1->getPObj())								//Ÿ������ ������Ʈ�� ������
					{
						//����
						_pos.y -= SPEED;
					}
			
					else if (tile1->getPObj())								//Ÿ�� ���� ������Ʈ�� ������
					{
						if (!tile1->getPObj()->getIsMovable())
						{

						}
						else if (tile1->getIsMovable())
						{
							_pos.y -= SPEED;
						}
					}
				}
			}
			else if (IntersectRect(&temp, &tile2->getRect(), &_rcCollision))
			{
				if (!tile2->getIsMovable())							//Ÿ���� ���� ���� Ÿ���̸�
				{
					//�Ȱ���
				}
				else if (tile2->getIsMovable())						//Ÿ���� ���� �ִ� Ÿ���̸�	
				{
					if (!tile2->getPObj())								//Ÿ������ ������Ʈ�� ������
					{
						//����
						_pos.y -= SPEED;
					}
			
					else if (tile2->getPObj())								//Ÿ�� ���� ������Ʈ�� ������
					{
						if (!tile2->getPObj()->getIsMovable())
						{

						}
						else if (tile2->getIsMovable())
						{
							_pos.y -= SPEED;
						}
					}
				}
			}
			else
			{
				_pos.y -= SPEED;
			}
		}

		if (KEYMANAGER->isStayKeyDown('A'))
		{
			centerY = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;

			tile1 = TOWNWORLD->getTile(_indexX - 1, _indexY);

			if (centerY < _tilePos.y)
			{
				tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY + 1);
			}
			else if (centerY > _tilePos.y)
			{
				tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY - 1);
			}

			if (IntersectRect(&temp, &tile1->getRect(), &_rcCollision))
			{
				if (!tile1->getIsMovable())						//�������� Ÿ���̸�
				{

				}
				else if (tile1->getIsMovable())					//�����ִ� Ÿ���̸�
				{

					if (!tile1->getPObj())						//������Ʈ�� ������
					{
						_pos.x -= SPEED;
					}
					else if (tile1->getPObj())					//������Ʈ�� ������
					{

						if (!tile1->getPObj()->getIsMovable())
						{

						}
						else if (tile1->getIsMovable())
						{
							_pos.x -= SPEED;
						}
					}
				}
			}
			else if (IntersectRect(&temp, &tile2->getRect(), &_rcCollision))
			{
				if (!tile2->getIsMovable())						//�������� Ÿ���̸�
				{

				}
				else if (tile2->getIsMovable())					//�����ִ� Ÿ���̸�
				{

					if (!tile2->getPObj())						//������Ʈ�� ������
					{
						_pos.x -= SPEED;
					}
					else if (tile2->getPObj())					//������Ʈ�� ������
					{
						if (!tile2->getPObj()->getIsMovable())
						{

						}
						else if (tile1->getIsMovable())
						{
							_pos.x -= SPEED;
						}

					}
				}
			}
			else
			{
				_pos.x -= SPEED;
			}
		}

		if (KEYMANAGER->isStayKeyDown('S'))
		{
			centerX = TOWNWORLD->getTile(_indexX, _indexY)->getRect().left + TILESIZE / 2;

			tile1 = TOWNWORLD->getTile(_indexX, _indexY);

			if (centerX < _tilePos.x)
			{
				tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY );
			}
			else if (centerX > _tilePos.x)
			{
				tile2 = TOWNWORLD->getTile(_indexX - 1, _indexY );
			}

			if (IntersectRect(&temp, &tile1->getRect(), &_rcCollision))
			{
				if (!tile1->getIsMovable())							//Ÿ���� ���� ���� Ÿ���̸�
				{
					//�Ȱ���
					//exit(0);
				}
				else if (tile1->getIsMovable())						//Ÿ���� ���� �ִ� Ÿ���̸�	
				{
					if (!tile1->getPObj())								//Ÿ������ ������Ʈ�� ������
					{
						//����
						_pos.y += SPEED;
					}

					else if (tile1->getPObj())								//Ÿ�� ���� ������Ʈ�� ������
					{
						if (!tile1->getPObj()->getIsMovable())							//�װ� �������� Ÿ������
						{

						}
						else if (tile1->getIsMovable())						//�����ִ� Ÿ������
						{
							_pos.y += SPEED;
						}
					}
				}
			}
		    else if (IntersectRect(&temp, &tile2->getRect(), &_rcCollision))
			{
				if (!tile2->getIsMovable())							//Ÿ���� ���� ���� Ÿ���̸�
				{
					//�Ȱ���
				}
				else if (tile2->getIsMovable())						//Ÿ���� ���� �ִ� Ÿ���̸�	
				{
					if (!tile2->getPObj())								//Ÿ������ ������Ʈ�� ������
					{
						//����
						_pos.y += SPEED;
					}

					else if (tile2->getPObj())								//Ÿ�� ���� ������Ʈ�� ������
					{
						if (!tile2->getPObj()->getIsMovable())
						{

						}
						else if (tile2->getIsMovable())
						{
							_pos.y += SPEED;
						}
					}
				}
			}
			else
			{
				_pos.y += SPEED;
			}
		}

		if (KEYMANAGER->isStayKeyDown('D'))
		{
			centerY = TOWNWORLD->getTile(_indexX, _indexY)->getRect().top + TILESIZE / 2;
			
			tile1 = TOWNWORLD->getTile(_indexX + 1, _indexY);
			if (centerY < _tilePos.y)
			{
				tile2 = TOWNWORLD->getTile(_indexX + 1, +_indexY + 1);
			}
			else if (centerY > _tilePos.y)
			{
				tile2 = TOWNWORLD->getTile(_indexX + 1, _indexY - 1);
			}
			if (IntersectRect(&temp, &tile1->getRect(), &_rcCollision))
			{
				if (!tile1->getIsMovable())
				{

				}
				else if (tile1->getIsMovable())
				{
					if (!tile1->getPObj())
					{
						_pos.x += SPEED;
					}
					else if (tile1->getPObj())
					{
						if (!tile1->getPObj()->getIsMovable())							//�װ� �������� Ÿ������
						{

						}
						else if (tile1->getIsMovable())						//�����ִ� Ÿ������
						{
							_pos.x += SPEED;
						}
					}
				}

			}
			else
			{
				_pos.x += SPEED;
			}
			
		}

		}

		//tileCollision();
		_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
		_rcCollision = RectMakeCenter(_pos.x, _pos.y - 20, 50, 20);
	}
	



#include "stdafx.h"
#include "player.h"
#include "inventory.h"

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
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeLeft", "player", axeLeft, 5, 10, false);

	int axeUp[] = { 43,44,45,46 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeUp", "player", axeUp, 4, 10, false);

	int axeRight[] = { 33,34,35,36,37 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeRight", "player", axeRight, 5, 10, false);

	int axeDown[] = { 27,28,29,30,31,32 };
	KEYANIMANAGER->addArrayFrameAnimation("playerAxeDown", "player", axeDown, 6, 10, false);

	//괭이
	int hoeLeft[] = { 60,61,62,63,64 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeLeft", "player", hoeLeft, 5, 10, false);

	int hoeUp[] = { 51,52,53,54 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeUp", "player", hoeUp, 4, 10, false);

	int hoeRight[] = { 55,56,57,58,59 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeRight", "player", hoeRight, 5, 10, false);

	int hoeDown[] = { 48,49,50 };
	KEYANIMANAGER->addArrayFrameAnimation("playerHoeDown", "player", hoeDown, 3, 10, false);

	//낫
	int sickleLeft[] = { 78,79,80,81,82,83 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleLeft", "player", sickleLeft, 6, 15, false);

	int sickleUp[] = { 84,85,86,87,88,89 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleUp", "player", sickleUp, 6, 15, false);

	int sickleRight[] = { 72,73,74,75,76,77 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleRight", "player", sickleRight, 6, 15, false);

	int sickleDown[] = { 65,66,67,68,69,70,71 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSickleDown", "player", sickleDown, 6, 15, false);

	//물뿌리개
	int waterLeft[] = { 108,109,110,111,112 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterLeft", "player", waterLeft, 5, 7, false);

	int waterUp[] = { 113,114,115 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterUp", "player", waterUp, 3, 7, false);

	int waterRight[] = { 90,91,92,93,94 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterRight", "player", waterRight, 5, 7, false);

	int waterDown[] = { 96,97,98,99,100,101,102,103,104,105,106,107 };
	KEYANIMANAGER->addArrayFrameAnimation("playerWaterDown", "player", waterDown, 12, 20, false);

	//곡괭이
	int pixhoeDown[] = { 168,169,170,171,172,173,174 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeDown", "player", pixhoeDown, 7, 10, false);

	int pixhoeUP[] = { 175,176,177,178 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeUp", "player", pixhoeUP, 4, 10, false);

	int pixhoeRight[] = { 180,181,182,183,184 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeRight", "player", pixhoeRight, 5, 10, false);

	int pixhoeLeft[] = { 189,188,187,186,185 };
	KEYANIMANAGER->addArrayFrameAnimation("playerPixhoeLeft", "player", pixhoeLeft, 5, 10, false);

	//검
	int swordDown[] = { 143,144,145,146,147,148 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordDown", "player", swordDown, 6, 10, false);
	
	int swordRight[] = { 149,150,151,152,153,154 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordRight", "player", swordRight, 6, 10, false);

	int swordLeft[] = { 155,156,157,158,159,160 };
	KEYANIMANAGER->addArrayFrameAnimation("playerSwordLeft", "player", swordLeft, 6, 10, false);

	int swordUp[] = { 161,162,163 };
	KEYANIMANAGER->addArrayFrameAnimation("playerswordUp", "player", swordUp, 3, 10, false);

	//아이템 들고 달리기
	int takeLeft[] = { 120,121,122,123,124 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeLeft", "player", takeLeft, 5, 10, true);

	int takeUp[] = { 131,132,133,134,135,136 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeUp", "player", takeUp, 6, 10, true);

	int takeRight[] = { 125,126,127,128,129 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeRight", "player", takeRight, 5, 10, true);

	int takeDown[] = { 116,130,138,139,140,141,142 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeDown", "player", takeDown, 7, 10, true);

	//아이템 들고 서있기
	int standTake[] = { 116 };
	KEYANIMANAGER->addArrayFrameAnimation("playerStandTake", "player", standTake, 1, 0, false);

	int standTakeLeft[] = { 120 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandLeft", "player", standTakeLeft, 1, 0, false);

	int standTakeRight[] = { 125 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandRight", "player", standTakeRight, 1, 0, false);

	int standTakeUp[] = { 131 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTakeStandUp", "player", standTakeUp, 1, 0, false);

//========================================================================================================
	
	gameObject::init(objName, "player", tagFloat(WINSIZEX / 2, WINSIZEY / 2), pivot::BOTTOM);
	
	_state = STAND;
	_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
	_player.Motion = KEYANIMANAGER->findAnimation("playerStand");

	
	tem = tagItem("도끼", "나무를 밸 수 있다", tagFloat(1000000,10000000), 1, itemType::TOOL);		//아이템 초기값
	_item = &tem;

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

	//대상 클릭
	this->addCallback("lbuttonClick", [this](tagMessage msg)
	{
		this->lbuttonClick(msg);
	});


	this->addCallback("changeTargetItem", [this](tagMessage msg)
	{
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

	_indexX = (int)_pos.x / TILESIZE;			//나의 인덱스 번호 X
	_indexY = (int)_pos.y / TILESIZE;			//나의 인덱스 번호 Y
	
	if (WORLDTIME->_isTimeFlow)				//UI가 켜지면 움직이지 않는다. (게임상 시간의 흐름 - UI가 켜지면 시간이 멈추면서 키와 시간만 멈춘다.)
	{
		this->stateUpdate(_state);
	}
	
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		this->sendMessage(tagMessage("lbuttonClick"));
	}

	KEYANIMANAGER->update();
	
}
void player::render()
{
	//gameObject::render();
	//Rectangle(getMemDC(), _player.rc.left, _player.rc.top, _player.rc.right, _player.rc.bottom);
	//Rectangle(getMemDC(), this->rectMakeBottom().left, this->rectMakeBottom().top, this->rectMakeBottom().right, this->rectMakeBottom().bottom);
	_image->scaleAniRender(getMemDC(), this->rectMakeBottom().left, this->rectMakeBottom().top, _player.Motion, _player.Motion->getFrameWidth() * 0.7, _player.Motion->getFrameHeight() *0.7);

	if (_state == STAND_TAKE && _state ==STAND_TAKE_LEFT && _state == STAND_TAKE_RIGHT &&_state == STAND_TAKE_BACK &&		//아이템을 들고있는 상태일때만 그린다.
		_state == TAKE_UP && _state == TAKE_LEFT && _state == TAKE_RIGHT && _state == TAKE_DOWN)
	{
		_myItem.img->render(getMemDC(), _myItem.x, _myItem.y);										
	}
	
}

void player::tileCollision()
{
	int _tileIndex[4];							//타일 검출용
	RECT _rcCollision;							//충돌체크용 가상 렉트				

	_rcCollision = _player.rc;

	_map->getTile(_indexX, _indexY + 1);
	_map->getTile(_indexX - 1, _indexY);
	_map->getTile(_indexX, _indexY-1);
	_map->getTile(_indexX + 1, _indexY);
	

	RECT _rc1;				//충돌 확인할 렉트
	RECT _rc2;				// 이하동문


	if ((IntersectRect(&_rc1, &_rcCollision, &_map->getTile(_indexX, _indexY + 1)->getRect())))
	{
		//if (_map->getTile(_indexX, _indexY + 1)->getPObj() )
		//{
			exit(0);
			//메세지
		//}
	}
}





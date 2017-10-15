#include "stdafx.h"
#include "inventory.h"

using namespace invenDirection;

HRESULT inventory::init(string name)
{
	gameObject::init(name);
	//기본 인벤토리 창 구조체 초기화
	_subInventory.img = IMAGEMANAGER->findImage("subInventory");
	_subInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY - 80);
	_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y,
		_subInventory.img->getWidth(), _subInventory.img->getHeight());
	//인벤토리 상태 초기화
	_direction = SUB_BOTTOM;
	//먼저 인벤토리 12칸 아무것도 없는 상태로 초기화 해준다
	for (int i = 0; i < 12; i++)
	{
		char str[100] = "";
		sprintf(str, "%d", i);

		tagItem	item = tagItem((string)str, tagFloat(_subInventory.rc.left + 49 + 64*i , _subInventory.pos.y));
		_vInventory.push_back(item);
	}
	//아이템 채워넣어 준다
	_vInventory[0] = tagItem("axe", tagFloat(_vInventory[0].pos.x, _vInventory[0].pos.y),0, itemType::TOOL);
	_vInventory[1] = tagItem("hoe", tagFloat(_vInventory[1].pos.x, _vInventory[1].pos.y),0, itemType::TOOL);
	_vInventory[2] = tagItem("pixHoe", tagFloat(_vInventory[2].pos.x, _vInventory[2].pos.y),0, itemType::TOOL);
	_vInventory[3] = tagItem("sickle", tagFloat(_vInventory[3].pos.x, _vInventory[3].pos.y),0, itemType::TOOL);
	_vInventory[4] = tagItem("sword", tagFloat(_vInventory[4].pos.x, _vInventory[4].pos.y),0, itemType::TOOL);
	//플레이어가 현재 들고있는 아이템 (포인터 형태이므로 new해준다)
	_targetItem = new tagItem;
	_targetItem = &_vInventory[0];		//현재 아이템 도끼로 초기화

	//msg.data -> 이거 형변환으로 인벤토리 창 상태 받자 
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState(msg);
	});
	//마우스 클릭에 따라 타겟 아이템이 바뀌는 콜백 함수 
	this->addCallback("setTargetItem", [this](tagMessage msg)
	{
		this->setTargetItem(msg);
	});

	return S_OK;
}

void inventory::release()
{
	gameObject::release();
}

void inventory::update()
{
	gameObject::update();

	
}

void inventory::render()
{
	//상태가 서브 인벤토리 상태일때 서브 인벤토리 그려주자. 
	if (_direction == SUB_BOTTOM || _direction == SUB_TOP)
	{
		//서브 인벤토리 윈도우 이미지 그려주고 
		_subInventory.img->scaleRender(getMemDC(), _subInventory.rc.left, _subInventory.rc.top,
			_subInventory.img->getWidth(), _subInventory.img->getHeight());
		//브러쉬는 NULL_BRUSH로 렉트다 투명으로 바꿔주자 
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);
	
		for (int i = 0; i < 12; ++i)
		{	
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(255,0,0));
			//전부다 렉트 테두리도 투명으로 바꿔준다
			HPEN oldPen = (HPEN)SelectObject(getMemDC(), GetStockObject(NULL_PEN));
			//타겟 아이템만 붉은색 선을 칠해준다.
			if (_targetItem == &_vInventory[i])
			{
				HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);
			}
			//타겟 아이템에 렉트 그려주자
			Rectangle(getMemDC(),_vInventory[i].rc.left, _vInventory[i].rc.top, 
				_vInventory[i].rc.right, _vInventory[i].rc.bottom);
		
			SelectObject(getMemDC(), oldPen);
			DeleteObject(pen);
			//인벤토리창에 있는 아이템이 이미지가 있다면 그려줘라 
			if (_vInventory[i].img != NULL)
			{
				_vInventory[i].img->scaleRender(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
					_vInventory[i].img->getWidth(), _vInventory[i].img->getHeight());
			}
		}
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);
	}
}


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

		tagItem	item = tagItem((string)str,"", tagFloat(_subInventory.rc.left + 49 + 64*i , _subInventory.pos.y),i);
		_vInventory.push_back(item);
	}
	//아이템 채워넣어 준다
	_vInventory[0] = tagItem("도끼","나무를 밸 수 있다", tagFloat(_vInventory[0].pos.x, _vInventory[0].pos.y),1, itemType::TOOL);
	_vInventory[1] = tagItem("괭이","땅을 개간할 수 있다", tagFloat(_vInventory[1].pos.x, _vInventory[1].pos.y),1, itemType::TOOL);
	_vInventory[2] = tagItem("곡괭이","돌을 부술 수 있다", tagFloat(_vInventory[2].pos.x, _vInventory[2].pos.y), 1, itemType::TOOL);
	_vInventory[3] = tagItem("낫","평범한 낫이다", tagFloat(_vInventory[3].pos.x, _vInventory[3].pos.y),1, itemType::TOOL);
	_vInventory[4] = tagItem("검","무엇이든 벨 수 있는 전설의 명검이다", tagFloat(_vInventory[4].pos.x, _vInventory[4].pos.y),1, itemType::TOOL);
	//플레이어가 현재 들고있는 아이템 (포인터 형태이므로 new해준다)
	_targetItem = new tagItem;
	_targetItem = &_vInventory[0];		//현재 아이템 도끼로 초기화

	_mainInventory.img = IMAGEMANAGER->findImage("mainInven1");
	_mainInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY / 2);
	_mainInventory.rc = RectMakeCenter(_mainInventory.pos.x, _mainInventory.pos.y, _mainInventory.img->getWidth(),
		_mainInventory.img->getHeight());

	//설명 창 구조체 초기화
	ZeroMemory(&_explain, sizeof(tagExplain));
	_explain.img = IMAGEMANAGER->findImage("explainUI");
	_explain.isPicking = false;

	_isPicking = false;

	_layer.img = IMAGEMANAGER->findImage("blackBox");
	_layer.isDark = false;

	//msg.data -> 이거 형변환으로 인벤토리 창 상태 받자 
	//인벤토리 상태 바뀌는거  
	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState(msg);
	});
	//마우스 클릭에 따라 타겟 아이템이 바뀌는 콜백 함수 
	this->addCallback("setTargetItem", [this](tagMessage msg)
	{
		this->setTargetItem(msg);
	});
	//아이템 추가 콜백함수 
	this->addCallback("addItem", [this](tagMessage msg)
	{
		this->addItem(msg);
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

	this->keyContoroll();

	this->changeItem();
}

void inventory::keyContoroll()
{
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		if (_direction != MAIN)
		{
			_direction = MAIN;
			_layer.isDark = true;
			WORLDTIME->_isTimeFlow = false;
			for (int i = 0; i < _vInventory.size(); ++i)
			{
				_vInventory[i].pos = tagFloat(_mainInventory.rc.left + 79 + 64 * i, _mainInventory.rc.top + 74);
				_vInventory[i].rc = RectMakeCenter(_vInventory[i].pos.x, _vInventory[i].pos.y, 56, 56);
			}
		}
		else if (_direction == MAIN)
		{
			_direction = SUB_BOTTOM;
			_layer.isDark = false;
			WORLDTIME->_isTimeFlow = true;
			for (int i = 0; i < _vInventory.size(); ++i)
			{
				_vInventory[i].pos = tagFloat(_subInventory.rc.left + 49 + 64 * i, _subInventory.pos.y);
				_vInventory[i].rc = RectMakeCenter(_vInventory[i].pos.x, _vInventory[i].pos.y, 56, 56);

				_vInventory[i].size = 1.0f;
			}
		}
	}

	//1~23,-,= 버튼 아이템 선택 키 커맨드
	if (this->_direction == invenDirection::SUB_BOTTOM ||
		this->_direction == invenDirection::SUB_TOP)
	{
		if (KEYMANAGER->isOnceKeyDown('1'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[0].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('2'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[1].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('3'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[2].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('4'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[3].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('5'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[4].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('6'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[5].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('7'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[6].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('8'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[7].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('9'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[8].name));
		}
		else if (KEYMANAGER->isOnceKeyDown('0'))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[9].name));
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_OEM_MINUS))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[10].name));
		}
		else if (KEYMANAGER->isOnceKeyDown(VK_OEM_PLUS))
		{
			this->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), _vInventory[11].name));
		}
	}

}

void inventory::render()
{
	if (_layer.isDark)
	{
		_layer.img->alphaRender(getMemDC(), 0, 0, 150);
	}


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
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			//전부다 렉트 테두리도 투명으로 바꿔준다
			HPEN oldPen = (HPEN)SelectObject(getMemDC(),GetStockObject(NULL_PEN));
			//타겟 아이템만 붉은색 선을 칠해준다.
			if (_targetItem == &_vInventory[i])
			{
				HPEN oldPen = (HPEN)SelectObject(getMemDC(), pen);
			}
			//인벤토리창에 있는 아이템이 이미지가 있다면 그려줘라 
			if (_vInventory[i].img != NULL)
			{
				_vInventory[i].img->scaleRender(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
					_vInventory[i].img->getWidth() *_vInventory[i].size, _vInventory[i].img->getHeight() * _vInventory[i].size);

			}

			//타겟 아이템에 렉트 그려주자
			Rectangle(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
				_vInventory[i].rc.right, _vInventory[i].rc.bottom);

			if (_vInventory[i].type != itemType::NONE &&_vInventory[i].type != itemType::TOOL)
			{
				char str[10];
				sprintf(str, "%d", _vInventory[i].count);

				RECT rc = RectMake(_vInventory[i].rc.right - 10, _vInventory[i].rc.bottom - 10, 50, 50);

				HFONT font = CreateFont(15, 0, 0, 0, 800, false, false, false,
					DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
					PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
				HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
				//텍스트 색을 설정해준다.
				SetTextColor(getMemDC(), RGB(86, 22, 12));
				//텍스트 그려주고
				DrawText(getMemDC(), str, strlen(str), &rc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);


				SelectObject(getMemDC(), oldFont);
				DeleteObject(font);

			}

			SelectObject(getMemDC(), oldPen);
			DeleteObject(pen);
		}
		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);
	
	}


	//인벤토리 상태 메인 인벤토리 일때 
	if (_direction == MAIN)
	{
		_mainInventory.img->render(getMemDC(), _mainInventory.rc.left, _mainInventory.rc.top);

		for (int i = 0; i < _vInventory.size(); ++i)
		{
			//인벤토리창에 있는 아이템이 이미지가 있다면 그려줘라 
			if (_vInventory[i].img != NULL)
			{
				_vInventory[i].img->scaleRender(getMemDC(), _vInventory[i].rc.left, _vInventory[i].rc.top,
					_vInventory[i].img->getWidth() *_vInventory[i].size, _vInventory[i].img->getHeight() * _vInventory[i].size);

				if (_vInventory[i].type != itemType::NONE &&_vInventory[i].type != itemType::TOOL)
				{
					char str[10];
					sprintf(str, "%d", _vInventory[i].count);

					RECT rc = RectMake(_vInventory[i].rc.right - 10, _vInventory[i].rc.bottom - 10, 50, 50);

					HFONT font = CreateFont(15, 0, 0, 0, 800, false, false, false,
						DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
						PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
					HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
					//텍스트 색을 설정해준다.
					SetTextColor(getMemDC(), RGB(10, 0, 0));
					//텍스트 그려주고
					DrawText(getMemDC(), str, strlen(str), &rc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

					SelectObject(getMemDC(), oldFont);
					DeleteObject(font);

				}
			}
		}

		if (_isPicking && _pickingItem.img != NULL)
		{
			_pickingItem.img->render(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20);
		}
		
		for(int i=0;i<_vInventory.size();++i)
		{
			if (PtInRect(&_vInventory[i].rc, _ptMouse))
			{
				if (_vInventory[i].type == itemType::NONE)continue;

				_explain.img->render(getMemDC(), _explain.rc.left, _explain.rc.top);

				_explain.itemName = _vInventory[i].name;
				_explain.itemExplain = _vInventory[i].explain;

				char nameStr[100];
				sprintf(nameStr, "%s", _explain.itemName.c_str());

				char itemType[100];
				sprintf(itemType, "%s", this->getStringItemType(&_vInventory[i]).c_str());

				char explainStr[100];
				sprintf(explainStr, "%s", _explain.itemExplain.c_str());

				RECT itemNameRc = RectMake(_explain.rc.left + 20, _explain.rc.top + 20,
					_explain.img->getWidth(), 100);

				RECT itemTypeRc = RectMake(_explain.rc.left + 20, _explain.rc.top + 50,
					_explain.img->getWidth(), 100);

				RECT itemExplainRc = RectMake(_explain.rc.left + 20, _explain.rc.top + 115,
					_explain.img->getWidth() - 50, 100);

				HFONT font = CreateFont(25, 0, 0, 0, 800, false, false, false,
					DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
					PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
				HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);

				//텍스트 색을 설정해준다.
				SetTextColor(getMemDC(), RGB(86, 22, 12));
				DrawText(getMemDC(), nameStr, strlen(nameStr), &itemNameRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

				HFONT font2 = CreateFont(15, 0, 0, 0, 600, false, false, false,
					DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
					PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
				HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

				SetTextColor(getMemDC(), RGB(0,0,0));

				DrawText(getMemDC(), itemType, strlen(itemType), &itemTypeRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);
				
				DrawText(getMemDC(), explainStr, strlen(explainStr), &itemExplainRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

				SelectObject(getMemDC(), oldFont2);
				DeleteObject(font2);

				SelectObject(getMemDC(), oldFont);
				DeleteObject(font);

				break;
			}
			
		}

	}


	char strTarget[100];
	sprintf(strTarget, "%s", _targetItem->name.c_str());
	TextOut(getMemDC(), 10, 100, strTarget, strlen(strTarget));
	
}



string inventory::getStringItemType(tagItem* item)
{
	switch (item->type)
	{
	case TOOL:
	{
		return "TOOL";
	}
	break;
	case FOOD:
	{
		return "FOOD";
	}
	break;
	case SEED:
	{
		return "SEED";
	}
	case WOOD:
	{
		return "WOOD";
	}
	break;
	case STONE:
	{
		return "STONE";
	}
	break;
	default:
		break;
	}
}

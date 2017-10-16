#include "stdafx.h"
#include "publicUI.h"
#include "inventory.h"


HRESULT publicUI::init(string name)
{
	gameObject::init(name);
	
	this->addCallback("addGetItemUI", [this](tagMessage msg)
	{
		this->addGetItemUI(msg);
	});

	this->addCallback("addGuideUI", [this](tagMessage msg)
	{
		this->addGuideUI(msg);
	});

	return S_OK;
}

void publicUI::release()
{
	gameObject::release();
}

void publicUI::update()
{
	gameObject::update();

	//gideUI벡터 처리 
	if (_vGuideUI.size() > 0)
	{
		for (int i = 0; i < _vGuideUI.size(); ++i)
		{
			if (_vGuideUI[i].liveTime > 0.0f)
			{
				_vGuideUI[i].liveTime -= TIMEMANAGER->getElapsedTime();
			}
			if (_vGuideUI[i].liveTime <= 0.0f)
			{
				inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
				inven->setDirection(invenDirection::SUB_BOTTOM);
				_vGuideUI.erase(_vGuideUI.begin() + i);
				--i;
			}
		}
	}


	//겟아이템 벡터 처리 
	for (int i = 0; i < _vGetItemUI.size(); ++i)
	{
		if (_vGetItemUI[i].sizeUp)_vGetItemUI[i].size += 0.05f;
		if (_vGetItemUI[i].size >= 1.0f)
		{
			_vGetItemUI[i].size = 1.0f;
			_vGetItemUI[i].sizeUp = false;
		}

		_vGetItemUI[i].liveTime -= TIMEMANAGER->getElapsedTime();

		if (_vGetItemUI[i].liveTime <= 0.0f)
		{
			_vGetItemUI[i].txt = "";
			_vGetItemUI[i].size -= 0.05;
			if (_vGetItemUI[i].size <= 0.3)
			{
				_vGetItemUI.erase(_vGetItemUI.begin() + i);
				--i;
			}
		}
	}

	
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		string str = "9:00 ~ 22:00까지만 영업합니다";
		this->sendMessage(tagMessage("addGuideUI", 0, 0, 0, vector<gameObject*>(),str));
	}

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		this->sendMessage(tagMessage("addGetItemUI", 0, 0, 0, vector<gameObject*>(), "다금바리"));
	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		sendMessage(tagMessage("addGetItemUI", 0.0f, 0, 0, vector<gameObject*>(), "공간부족"));
	}
}

void publicUI::render()
{
	this->guideItemUIRender();

	this->getItemUIRender();
}

void publicUI::getItemUIRender()
{
	for (int i = 0; i < _vGetItemUI.size(); ++i)
	{
		_vGetItemUI[i].img->scaleRender(getMemDC(), _vGetItemUI[i].rc.left, _vGetItemUI[i].rc.top,
			_vGetItemUI[i].img->getWidth() * _vGetItemUI[i].size, _vGetItemUI[i].img->getHeight() * _vGetItemUI[i].size);

		if (_vGetItemUI[i].item != NULL)
		{
			_vGetItemUI[i].item->scaleRender(getMemDC(), _vGetItemUI[i].rc.left + 14, _vGetItemUI[i].rc.top + 18,
				_vGetItemUI[i].item->getWidth()* _vGetItemUI[i].size, _vGetItemUI[i].item->getHeight()*_vGetItemUI[i].size);
		}

		//86,37
		RECT drawRc = RectMake(_vGetItemUI[i].rc.left + 86, _vGetItemUI[i].rc.top, 100, 100);

		char str[100];
		sprintf(str, "%s", _vGetItemUI[i].txt.c_str());

		//폰트 성정
		HFONT font = CreateFont(15, 0, 0, 0, 800, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
		HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
		//텍스트 색을 설정해준다.
		SetTextColor(getMemDC(), RGB(86, 22, 12));
		if (_vGetItemUI[i].sizeUp == false)
		{
			//텍스트 그려주고
			DrawText(getMemDC(), str, strlen(str), &drawRc, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		}
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		
	}

	if (_vGetItemUI.size() != 0)
	{
		char str[100];
		sprintf(str, "%d, %d", _ptMouse.x-_vGetItemUI[0].rc.left, +_ptMouse.y-_vGetItemUI[0].rc.top );
		TextOut(getMemDC(), 10, 10, str, strlen(str));
	}
}

void publicUI::guideItemUIRender()
{
	if (_vGuideUI.size() != 0)
	{
		char str[100];
		sprintf(str, "%s", _vGuideUI[0].txt.c_str());

		float charWidth = 25;
		float width = ((charWidth * strlen(str)) * 2) / 3;

		_vGuideUI[0].count += TIMEMANAGER->getElapsedTime();
		if (_vGuideUI[0].count >= 0.05f)
		{
			_vGuideUI[0].index += 2;
			_vGuideUI[0].count = 0;
			if (_vGuideUI[0].index >= strlen(_vGuideUI[0].txt.c_str()))
			{
				_vGuideUI[0].index = strlen(_vGuideUI[0].txt.c_str());
			}
		}

		RECT drawRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, width, 100);

		//폰트 성정
		HFONT font = CreateFont(charWidth, 0, 0, 0, 800, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
		HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
		//텍스트 색을 설정해준다.
		SetTextColor(getMemDC(), RGB(86, 22, 12));

		//guideUI 이미지 그려준다
		_vGuideUI[0].img->scaleRender(getMemDC(), drawRc.left - 40, drawRc.top - 7, width + 40, _vGuideUI[0].img->getHeight());
		//텍스트 그려주고
		DrawText(getMemDC(), str, _vGuideUI[0].index, &drawRc, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
}




void publicUI::addGetItemUI(tagMessage msg)
{
	for (int i = 0; i < _vGetItemUI.size(); ++i)
	{
		if (_vGetItemUI[i].txt == msg.conversation)return;
	}
	
	tagUI ui;
	ZeroMemory(&ui, sizeof(tagUI));

	ui.img = IMAGEMANAGER->findImage("getItemUI");
	ui.item = IMAGEMANAGER->findImage(msg.conversation);
	ui.liveTime = 3.0f;
	ui.txt = msg.conversation;
	ui.size = 0.1f;
	ui.sizeUp = true;
	ui.rc = RectMake(50, WINSIZEY - 200 - (120 * _vGetItemUI.size()), ui.img->getWidth(), ui.img->getHeight());

	_vGetItemUI.push_back(ui);
	
}

void publicUI::addGuideUI(tagMessage msg)
{
	if (_vGuideUI.size() != 0)return;

	tagUI ui;
	ZeroMemory(&ui, sizeof(tagUI));

	ui.img = IMAGEMANAGER->findImage("publicUI");
	ui.count = 0;
	ui.index = 0;
	ui.liveTime = 3.0f;
	ui.txt = msg.conversation;
	
	_vGuideUI.push_back(ui);

	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
	inven->setDirection(invenDirection::HIDE);
}
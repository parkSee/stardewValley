#include "stdafx.h"
#include "publicUI.h"


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
				_vGuideUI.erase(_vGuideUI.begin() + i);
				--i;
			}
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		string str = "9:00 ~ 22:00까지만 영업합니다";
		this->sendMessage(tagMessage("addGuideUI", 0, 0, 0, vector<gameObject*>(),str));
	}
}

void publicUI::render()
{
	for (int i = 0; i < _vGuideUI.size(); ++i)
	{
		char str[100];
		sprintf(str, "%s", _vGuideUI[i].txt.c_str());
		
		float charWidth = 25;
		float width = ((charWidth * strlen(str))*2)/3;

		RECT drawRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - 100, width, 100);
		
		//폰트 성정
		HFONT font = CreateFont(charWidth, 0, 0, 0, 800, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
		HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
		//텍스트 색을 설정해준다.
		SetTextColor(getMemDC(), RGB(86, 22, 12));

		//guideUI 이미지 그려준다
		_vGuideUI[i].img->scaleRender(getMemDC(), drawRc.left - 40, drawRc.top -7, width +40,_vGuideUI[i].img->getHeight());
		//텍스트 그려주고
		DrawText(getMemDC(), str, strlen(str), &drawRc, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);		
	}
}

void publicUI::addGetItemUI(tagMessage msg)
{
	tagUI ui;
	ZeroMemory(&ui, sizeof(tagUI));

	
}

void publicUI::addGuideUI(tagMessage msg)
{
	tagUI ui;
	ZeroMemory(&ui, sizeof(tagUI));

	ui.img = IMAGEMANAGER->findImage("publicUI");
	ui.count = 0;
	ui.index = 0;
	ui.liveTime = 3.0f;
	ui.txt = msg.conversation;

	_vGuideUI.push_back(ui);
}
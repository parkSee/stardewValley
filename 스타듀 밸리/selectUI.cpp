#include "stdafx.h"
#include "selectUI.h"
#include "inventory.h"
#include "player.h"

using namespace selectUIDirection;

HRESULT selectUI::init(string name)
{
	gameObject::init(name);

	_window = IMAGEMANAGER->findImage("selectUI");
	
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY - 30 - _window->getHeight()/2;

	_windowRc = RectMakeCenter(_pos.x, _pos.y, _window->getWidth(), _window->getHeight());

	_yes.rc = RectMake(_windowRc.left + 30, _windowRc.top + 100, _window->getWidth() - 80, 50);
	
	_no.rc = RectMake(_yes.rc.left, _yes.rc.bottom + 15, _yes.rc.right - _yes.rc.left, _yes.rc.bottom - _yes.rc.top);

	_direction = NONE_ACTIVE;

	_txt = "먹을까요?";

	_cb = NULL;

	this->addCallback("selectEat", [this](tagMessage msg)
	{
		this->setSelectUI(msg);
	});

	return S_OK;
}

void selectUI::release()
{
	gameObject::release();
}

void selectUI::update()
{
	gameObject::update();

	if (_direction == ACTIVE)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			inventory*	inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
			player*	ply = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");
			
			if (PtInRect(&_yes.rc, _ptMouse))
			{
				_direction = NONE_ACTIVE;

				if (_cb != NULL)
				{
					_cb();
					_cb = NULL;
				}

				inven->setDirection(invenDirection::SUB_BOTTOM);
			}
			else if (PtInRect(&_no.rc, _ptMouse))
			{
				inven->setDirection(invenDirection::SUB_BOTTOM);
				_direction = NONE_ACTIVE;

				_cb = NULL;
				WORLDTIME->_isTimeFlow = true;
			}
		}
	}
}

void selectUI::render()
{
	if (_direction == ACTIVE)
	{
		_window->scaleRender(getMemDC(), _windowRc.left, _windowRc.top, _window->getWidth(), _window->getHeight());

		HPEN nullPen = (HPEN)GetStockObject(NULL_PEN);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), brush);

		if (PtInRect(&_yes.rc, _ptMouse))
		{
			HPEN oldPen = (HPEN)SelectObject(getMemDC(), redPen);
			Rectangle(getMemDC(), _yes.rc.left, _yes.rc.top, _yes.rc.right, _yes.rc.bottom);
			SelectObject(getMemDC(), oldPen);
		}
		else if (PtInRect(&_no.rc, _ptMouse))
		{
			HPEN oldPen = (HPEN)SelectObject(getMemDC(), redPen);
			Rectangle(getMemDC(), _no.rc.left, _no.rc.top, _no.rc.right, _no.rc.bottom);
			SelectObject(getMemDC(), oldPen);
		}
		char str[100];
		sprintf(str, "%s", _txt.c_str());
		RECT drawRc = RectMake(_windowRc.left + 30, _windowRc.top + 50, 300, 50);

		HFONT font = CreateFont(30, 0, 0, 0, 800, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
		HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);

		HFONT font2 = CreateFont(23, 0, 0, 0, 600, false, false, false,
			DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
			PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
		HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

		//텍스트 색을 설정해준다.
		SetTextColor(getMemDC(), RGB(86, 22, 12));
		//텍스트 그려주고
		DrawText(getMemDC(), str, strlen(str), &drawRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

		//텍스트 색을 설정해준다.
		SetTextColor(getMemDC(), RGB(40, 50, 40));
		char str2[100];
		sprintf(str2, "네.");
		//텍스트 그려주고
		DrawText(getMemDC(), str2, strlen(str2), &_yes.rc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

		char str3[100];
		sprintf(str3, "아니오.");
		//텍스트 그려주고
		DrawText(getMemDC(), str3, strlen(str3), &_no.rc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

		DeleteObject(redPen);
		DeleteObject(nullPen);

		SelectObject(getMemDC(), oldBrush);
		DeleteObject(brush);

		SelectObject(getMemDC(), oldFont2);
		DeleteObject(font2);

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
}


void selectUI::setSelectUI(tagMessage msg)
{

	_direction = ACTIVE;

	inventory*	inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
	inven->setDirection(invenDirection::HIDE);

	_txt = msg.conversation;

	WORLDTIME->_isTimeFlow = false;
}
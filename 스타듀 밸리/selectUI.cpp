#include "stdafx.h"
#include "selectUI.h"

HRESULT selectUI::init(string name)
{
	gameObject::init(name);

	_window = IMAGEMANAGER->findImage("publicUI");
	
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY - 50 - _window->getHeight();

	_windowRc = RectMakeCenter(_pos.x, _pos.y, _window->getWidth(), _window->getHeight());

	_yes = RectMake(_windowRc.left + 30, _windowRc.top + 20, _window->getWidth() - 30, _window->getHeight() - 20);
	
	_no = RectMake(_yes.left, _yes.top + 50, _yes.right - _yes.left, _yes.bottom - _yes.top);


	this->addCallback("setSelectUI", [this](tagMessage msg)
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
}

void selectUI::render()
{
	_window->scaleRender(getMemDC(), _windowRc.left, _windowRc.top, _window->getWidth(), _window->getHeight());
}


void selectUI::setSelectUI(tagMessage msg)
{
	
}
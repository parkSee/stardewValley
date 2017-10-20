#include "stdafx.h"
#include "createUI.h"



HRESULT createUI::init(string name)
{
	gameObject::init(name);

	_window = IMAGEMANAGER->findImage("createItem");
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY -_window->getHeight();
	_windowRc = RectMakeCenter(_pos.x, _pos.y, _window->getWidth(), _window->getHeight());

	_chest.img = IMAGEMANAGER->findImage("chest_obj");
	_chest.alpha = 100;
	_chest.isCreate = false;
	_chest.scale = 1.0f;
	_chest.rc = RectMake(_windowRc.left + 30, _windowRc.top + 30, _chest.img->getWidth(), _chest.img->getHeight());

	_fence.img = IMAGEMANAGER->findImage("fence_obj");
	_fence.alpha = 100;
	_fence.isCreate = false;
	_fence.scale = 1.0f;
	_fence.rc = RectMake(_chest.rc.right + 30, _chest.rc.top, _fence.img->getWidth(), _fence.img->getHeight());

	_exit.img = IMAGEMANAGER->findImage("exit2");
	_exit.rc = RectMake(_windowRc.right, _windowRc.top, _exit.img->getWidth(),_exit.img->getHeight());

	_inventory = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");

	_isActiveUI = false;

	return S_OK;
}

void createUI::release()		   
{
	gameObject::release();
}

void createUI::update()			   
{
	gameObject::update();
	if (_isActiveUI)
	{
		this->createChest();

		this->createFence();

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&_exit.rc, _ptMouse))
			{
				this->_isActiveUI = false;
			}
		}
	}
	
}

void createUI::render()			   
{
	if (_isActiveUI)
	{
		_window->render(getMemDC(), _windowRc.left, _windowRc.top);

		_chest.img->alphaScaleFrameRender(getMemDC(), _windowRc.left + 30, _windowRc.top + 30, 0, 0,
			_chest.img->getWidth() * _chest.scale, _chest.img->getHeight()*_chest.scale, _chest.alpha);

		_fence.img->alphaScaleFrameRender(getMemDC(), _fence.rc.left, _fence.rc.top, 0, 0,
			_fence.img->getWidth() * _fence.scale, _fence.img->getHeight() * _fence.scale, _fence.alpha);

		_exit.img->render(getMemDC(), _exit.rc.left, _exit.rc.top);

	}
}


void createUI::createChest()
{
	tagItem* wood;
	if (_inventory->findItem("나무") != NULL)
	{
		wood = _inventory->findItem("나무");

		if (wood->count >= 10)
		{
			_chest.isCreate = true;
		}
		else
		{
			_chest.isCreate = false;
		}
	}
	else
	{
		_chest.isCreate = false;
	}

	if (_chest.isCreate == true)
	{
		_chest.alpha = 255;

		if (PtInRect(&_chest.rc, _ptMouse))
		{
			_chest.scale = 1.3f;

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				wood = _inventory->findItem("나무");
				_inventory->addItem(tagMessage("addItem", 0.0f, 0, 0, vector<gameObject*>(), "상자", "무엇이든 담을 수 있다."));
				wood->count -= 10;

				if (wood->count < 10)_chest.scale = 1.0f;
			}
		}
		else
		{
			_chest.scale = 1.0f;
		}
	}
	else _chest.alpha = 100;

}

void createUI::createFence()
{
	tagItem* wood;
	if (_inventory->findItem("나무") != NULL)
	{
		wood = _inventory->findItem("나무");

		if (wood->count >= 3)
		{
			_fence.isCreate = true;
		}
		else
		{
			_fence.isCreate = false;
		}
	}
	else
	{
		_fence.isCreate = false;
	}

	if (_fence.isCreate == true)
	{
		_fence.alpha = 255;

		if (PtInRect(&_fence.rc, _ptMouse))
		{
			_fence.scale = 1.3f;

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				wood = _inventory->findItem("나무");
				_inventory->addItem(tagMessage("addItem", 0.0f, 0, 0, vector<gameObject*>(), "울타리", "다 막아버려!"));
				wood->count -= 3;

				if (wood->count < 3)_fence.scale = 1.0f;
			}
		}
		else
		{
			_fence.scale = 1.0f;
		}
	}
	else _fence.alpha = 100;
}
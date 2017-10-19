#include "stdafx.h"
#include "mouse.h"

#include "UI.h"
#include "inventory.h"
#include "item.h"
#include "player.h"

HRESULT mouse::init(string name)
{
	gameObject::init(name ,"mouse");

	_image = IMAGEMANAGER->findImage("mouse");
	_alpha = 255;
	_scale = 1.0f;

	_selectAnimation = new animation;
	_selectAnimation->init(IMAGEMANAGER->findImage("selectMouse")->getWidth(), IMAGEMANAGER->findImage("selectMouse")->getHeight(),
		IMAGEMANAGER->findImage("selectMouse")->getFrameWidth(), IMAGEMANAGER->findImage("selectMouse")->getFrameHeight());
	_normalAnimation = new animation;
	_normalAnimation->init(IMAGEMANAGER->findImage("mouse")->getWidth(), IMAGEMANAGER->findImage("mouse")->getHeight(),
		IMAGEMANAGER->findImage("mouse")->getFrameWidth(), IMAGEMANAGER->findImage("mouse")->getFrameHeight());

	_animation->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void mouse::release()
{
	gameObject::release();
	
	SAFE_DELETE(_normalAnimation);
	SAFE_DELETE(_selectAnimation);
}

void mouse::update() 
{
	gameObject::update();

	this->mouseControll();
	
}

void mouse::render() 
{
	_image->alphaScaleAniRender(getMemDC(), _ptMouse.x, _ptMouse.y, _animation,
		_image->getFrameWidth() * _scale,
		_image->getFrameHeight() * _scale, _alpha);

}


void mouse::mouseControll()
{
	UI* uiManager = (UI*)TOWNWORLD->findObject(objectType::INTERFACE, "UI");

	//UI��ȭâ ������ ��ư ������ ó��
	if (uiManager->_direction == uiDirection::CONVERSATION)
	{
		if (PtInRect(&uiManager->_exit.rc, _ptMouse))
		{
			_image = IMAGEMANAGER->findImage("selectMouse");		//���콺 �̹����� �̰ɷ�
			_animation = _selectAnimation;							//�ִϸ��̼ǵ� �������ְ� 

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{				
				uiManager->sendMessage(tagMessage("exit"));

				_image = IMAGEMANAGER->findImage("mouse");
				_animation = _normalAnimation;
			}
		}
		else
		{
			_image = IMAGEMANAGER->findImage("mouse");
			_animation = _normalAnimation;
		}
	}
	//UI����â ������ ó�� 
	else if (uiManager->_direction == uiDirection::LETTER)
	{
		if (PtInRect(&uiManager->_letter.rc, _ptMouse))
		{
			_image = IMAGEMANAGER->findImage("selectMouse");		//���콺 �̹����� �̰ɷ�
			_animation = _selectAnimation;							//�ִϸ��̼ǵ� �������ְ� 

			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				uiManager->sendMessage(tagMessage("exit"));

				_image = IMAGEMANAGER->findImage("mouse");
				_animation = _normalAnimation;
			}
		}
		else
		{
			_image = IMAGEMANAGER->findImage("mouse");
			_animation = _normalAnimation;
		}
	}

	//===================�κ��丮 â ����==================
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
	//�κ��丮 â ���� â�϶� 
	if (inven->getDirection() == invenDirection::SUB_BOTTOM || inven->getDirection() == invenDirection::SUB_TOP)
	{
		vector<tagItem*> vItem = inven->getItems();
		for (int i = 0; i < vItem.size(); ++i)
		{
			if (PtInRect(&vItem[i]->rc, _ptMouse))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					inven->sendMessage(tagMessage("setTargetItem", 0.0f, 0, 0, vector<gameObject*>(), vItem[i]->name));
				}
			}
		}
	}

	if (inven->getTargetItem()->type == itemType::FOOD)
	{

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//if(PtInRect(&))
		}
	}
	

	//�ִϸ��̼��� ����Ʈ ���ϸ��̼� ���¶�� 
	if (_animation == _selectAnimation)
	{
		//������ �� Ŀ���� �۾����� �ϰ� ������ 
		if (_isScaleUp)
		{
			_scale += 0.008;
		}
		if (!_isScaleUp)
		{
			_scale -= 0.008;
		}
		if (_scale >= 1.2)_isScaleUp = false;
		if (_scale <= 0.9)_isScaleUp = true;
	}

}
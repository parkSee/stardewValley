#include "stdafx.h"
#include "mouse.h"

#include "UI.h"
#include "inventory.h"
#include "item.h"
#include "player.h"
#include "selectUI.h"
#include "caroline.h"
#include "createUI.h"

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

	//UI대화창 나가는 버튼 누르는 처리
	if (uiManager->_direction == uiDirection::CONVERSATION)
	{
		if (PtInRect(&uiManager->_exit.rc, _ptMouse))
		{
			_image = IMAGEMANAGER->findImage("selectMouse");		//마우스 이미지는 이걸로
			_animation = _selectAnimation;							//애니메이션도 세팅해주고 

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
	//UI편지창 나가는 처리 
	else if (uiManager->_direction == uiDirection::LETTER)
	{
		if (PtInRect(&uiManager->_letter.rc, _ptMouse))
		{
			_image = IMAGEMANAGER->findImage("selectMouse");		//마우스 이미지는 이걸로
			_animation = _selectAnimation;							//애니메이션도 세팅해주고 

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

	//===================인벤토리 창 관련==================
	inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
	//인벤토리 창 서브 창일때 
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
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			selectUI* select = (selectUI*)TOWNWORLD->findObject(objectType::INTERFACE,"selectUI");
			select->sendMessage(tagMessage("selectEat",0,0,0,vector<gameObject*>(),"먹을까요?"));
			select->setCb([]() 
			{
				player* ply = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");
				inventory*	inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");

				ply->sendMessage(tagMessage("eating"));
				inven->setDirection(invenDirection::SUB_BOTTOM);
				inven->getTargetItem()->count -= 1;

				WORLDTIME->_isTimeFlow = true;
			});
		}
	}

	RECT rc = CAMERAMANAGER->getRenderRc();
	player* ply = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");
	int indexX = (_ptMouse.x + rc.left) / TILESIZE;
	int indexY = (_ptMouse.y + rc.top) / TILESIZE;

	if (ply->getIndexX() ==24 && ply->getIndexY() == 14)
	{
		if ((indexX == 24 && indexY == 13) || (indexX == 24 && indexY == 12))
		{
			_image = IMAGEMANAGER->findImage("selectMouse");
			_animation = _selectAnimation;
		}
		else
		{
			_image = IMAGEMANAGER->findImage("mouse");
			_animation = _normalAnimation;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (inven->getDirection() != invenDirection::MAIN)
		{
			//집들어가는거
			caroline* carol = (caroline*)TOWNWORLD->findObject(objectType::HUMAN, "caroline");
			RECT rc = CAMERAMANAGER->getRenderRc();

			if (ply->getIndexX() == 24 && ply->getIndexY() == 14)
			{
				if ((indexX == 24 && indexY == 13) || (indexX == 24 && indexY == 12))
				{
					
					ply->_pos.x = (TILESIZE * 8) + TILESIZE / 2;
					ply->_pos.y = (TILESIZE * 95) + TILESIZE / 2;
					_image = IMAGEMANAGER->findImage("mouse");
					_animation = _normalAnimation;

					WORLDTIME->_playerPos = playerPos::HOUSE;
				}
			}

			else if (abs(ply->getIndexX() - carol->getIndexX()) < 2 && abs(ply->getIndexY() - carol->getIndexY()) < 2)
			{
				if (PtInRect(&carol->getCollisionRect(), PointMake(_ptMouse.x + rc.left, _ptMouse.y + rc.top)))
				{
					createUI* createui = (createUI*)TOWNWORLD->findObject(objectType::INTERFACE, "createUI");
					if (createui->_isActiveUI == false)
					{
						createui->_isActiveUI = true;
					}
				}
			}

			else
			{
				ply->sendMessage(tagMessage("lbuttonClick"));
			}

		}
	}

	if (ply->getIndexX() == 8 && ply->getIndexY() == 96)
	{
		ply->_pos.x = (TILESIZE * 24) + TILESIZE / 2;
		ply->_pos.y = (TILESIZE * 14) + TILESIZE / 2;

		WORLDTIME->_playerPos = playerPos::OUTSIDE;
	}
	
	//애니메이션이 셀렉트 에니메이션 상태라면 
	if (_animation == _selectAnimation)
	{
		//사이즈 가 커졌다 작아졌다 하게 만들어라 
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
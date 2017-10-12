#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{

}

HRESULT spaceShip::init(void)
{
	_ship = IMAGEMANAGER->addImage("快林急", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2 - _ship->getWidth() / 2);
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(10, 400);

	_jericho = new jericho;
	_jericho->init(300, 300);

	_currentHP = _maxHP = 100;

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX() - 25, _ship->getY() - 10, 53, 5);
	_hpBar->setGauge(_currentHP, _maxHP);

	_alphaValue = 255;

	return S_OK;
}

void spaceShip::release(void)
{

}

void spaceShip::update(void) 
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_missile->fire(_ship->getX() + _ship->getWidth() / 2,
			_ship->getY() - 20);
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_jericho->fire(_ship->getX() + _ship->getWidth() / 2,
			_ship->getY() - 20);
	}

	//技捞何
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("OmicronTeam.txt", vStr);
	}

	//肺滴
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("OmicronTeam.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_maxHP = (atoi(vStr[1].c_str()));
		_ship->setX(atoi(vStr[2].c_str()));
		_ship->setY(atoi(vStr[3].c_str()));
	}


	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 10);
	_hpBar->setGauge(_currentHP, _maxHP);

	_hpBar->update();
	//collision();

	_missile->update();
	_jericho->update();

	_alphaValue--;

	if (_alphaValue <= 0) _alphaValue = 255;

}

void spaceShip::render(void) 
{
	_ship->alphaRender(getMemDC(), _alphaValue);
	_missile->render();
	_jericho->render();

	_hpBar->render();
}

void spaceShip::removeMissile(int arrNum)
{
	_jericho->removeMissile(arrNum);
}

void spaceShip::collision()
{
	for (int i = 0; i < _jericho->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_jericho->getVBullet()[i].rc,
				&_em->getVMinion()[j]->getRect()))
			{
				_jericho->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;
}
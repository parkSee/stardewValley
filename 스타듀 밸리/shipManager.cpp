#include "stdafx.h"
#include "shipManager.h"


shipManager::shipManager()
{
}


shipManager::~shipManager()
{

}

HRESULT shipManager::init()
{
	_ship[SHIPKIND_BATTLE1] = new battle;
	_ship[SHIPKIND_BATTLE1]->init("battle1", 0, 0);

	_ship[SHIPKIND_BATTLE2] = new battle2;
	_ship[SHIPKIND_BATTLE2]->init("battle2", 100, 100);

	_focusShip = _ship[SHIPKIND_BATTLE1];

	_space = new space;
	_space->init();
	_space->setShip(_focusShip);


	return S_OK;
}

void shipManager::release()
{

}

void shipManager::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_focusShip = _ship[SHIPKIND_BATTLE1];
		_space->setShip(_focusShip);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_focusShip = _ship[SHIPKIND_BATTLE2];
		_space->setShip(_focusShip);
	}

	for (int i = 0; i < SHIPKIND_END; i++)
	{
		_ship[i]->update();
	}

	_focusShip->keyControl();
}

void shipManager::render() 
{
	_space->render();

	for (int i = 0; i < SHIPKIND_END; i++)
	{
		if (_focusShip == _ship[i])
		{
			_focusShip->focusDraw();
		}
		else
		{
			_ship[i]->defaultDraw(_focusShip->getRect());
		}
	}
}

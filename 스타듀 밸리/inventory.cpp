#include "stdafx.h"
#include "inventory.h"

HRESULT inventory::init(string name)
{
	gameObject::init(name);

	_subInventory.pos = tagFloat(WINSIZEX / 2, WINSIZEY - 150);
	_subInventory.img = IMAGEMANAGER->findImage("subInventory");
	_subInventory.rc = RectMakeCenter(_subInventory.pos.x, _subInventory.pos.y, _subInventory.img->getWidth(), _subInventory.img->getHeight());

	//item* axe = new item;
	//axe->init("axe", itemType::AXE);
	//axe->_isPlayerHave = true;
	//axe->_pos = tagFloat(_subInventory.rc.left + 5 + 30 , _subInventory.rc.top + 10);
	//_vTotalItem.push_back(axe);

	return S_OK;	
}

void inventory::release()
{
	gameObject::release();
}

void inventory::update() 
{
	gameObject::update();


}

void inventory::render()
{

	for (int i = 0; i < _vTotalItem.size(); ++i)
	{
		_vTotalItem[i]->render();
	}
}
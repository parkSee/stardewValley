#include "stdafx.h"
#include "item.h"

HRESULT item::init(string itemName,string  imageKey, itemType::Enum type)
{
	gameObject::init(itemName , imageKey);

	_itemType = type;

	return S_OK;
}

void item::release()
{
	gameObject::release();
}

void item::update()	
{
	gameObject::update();
}

void item::render()	
{
	
}
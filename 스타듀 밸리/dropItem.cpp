#include "stdafx.h"
#include "dropItem.h"
#include "inventory.h"

HRESULT dropItem::init(string name , string explain,tagFloat pos)
{
	gameObject::init(name, name,pos);

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());

	_targetPlayer = TOWNWORLD->findObject(objectType::HUMAN, "player");

	_explain = explain;

	return S_OK;
}
void dropItem::release()
{
	gameObject::release();
}
void dropItem::update()
{
	gameObject::update();

	float distance = getDistance(_targetPlayer->_pos.x, _targetPlayer->_pos.y -100, this->_pos.x, this->_pos.y);
	if ( distance < 150)
	{
		float angle = getAngle(_pos.x, _pos.y, _targetPlayer->_pos.x, _targetPlayer->_pos.y-100);
		_pos.x += cosf(angle) * ITEMSPEED;
		_pos.y -= sinf(angle) * ITEMSPEED;

		if (distance < 30)
		{	
			inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
			inven->sendMessage(tagMessage("addItem", 0.0f, 0, 0, vector<gameObject*>(), _name,_explain));

			this->setDestroy();
		}
	}

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());
}
void dropItem::render()
{
	_image->scaleRender(getMemDC(), _rc.left, _rc.top, _image->getWidth(), _image->getHeight());
}
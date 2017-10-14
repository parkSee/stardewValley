#include "stdafx.h"
#include "dropItem.h"

HRESULT dropItem::init(string name , string keyName)
{
	gameObject::init(name, keyName);

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());

	_targetPlayer = TOWNWORLD->findObject(objectType::HUMAN, "player");

	return S_OK;
}
void dropItem::release()
{
	gameObject::release();
}
void dropItem::update()
{
	gameObject::update();

	if (getDistance(_targetPlayer->_pos.x, _targetPlayer->_pos.y, this->_pos.x, this->_pos.y) < 50)
	{
		float angle = getAngle(_targetPlayer->_pos.x, _targetPlayer->_pos.y, _pos.x, _pos.y);
		_pos.x += cosf(angle) * 5;
		_pos.y -= sinf(angle) * 5;
	}

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());
}
void dropItem::render()
{
	_image->scaleRender(getMemDC(), _rc.left, _rc.top, _image->getWidth(), _image->getHeight());
}
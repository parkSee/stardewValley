#include "stdafx.h"
#include "dropItem.h"
#include "inventory.h"

HRESULT dropItem::init(string name , string explain,tagFloat pos)
{
	gameObject::init(name, name,pos);

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());

	_targetPlayer = TOWNWORLD->findObject(objectType::HUMAN, "player");

	_explain = explain;

	_isBounce = false;
	_jumpPower = 5.0f;
	_gravity = 0.2f;
	_jumpCount = 0;
	_speed = RND->getFromFloatTo(-1.5f,1.5f);
	
	_savePos = _pos;

	return S_OK;
}
void dropItem::release()
{
	gameObject::release();
}
void dropItem::update()
{
	gameObject::update();

	if (!_isBounce)
	{
		_pos.y -= _jumpPower;
		_pos.x -= _speed;
		_jumpPower -= _gravity;

		if (_pos.y >= _savePos.y)
		{
			if (_jumpCount == 0)
			{
				_jumpPower = 3.0f;
				_jumpCount++;
			}
			else if (_jumpCount == 1)
			{
				_jumpPower = 2.0f;
				_jumpCount++;
			}
			else if (_jumpCount == 2)
			{
				_isBounce = true;
			}
		}
	}


	else if (_isBounce)
	{
		float distance = getDistance(_targetPlayer->_pos.x, _targetPlayer->_pos.y - 100, this->_pos.x, this->_pos.y);
		if (distance < 150)
		{
			float angle = getAngle(_pos.x, _pos.y, _targetPlayer->_pos.x, _targetPlayer->_pos.y - 100);
			_pos.x += cosf(angle) * ITEMSPEED;
			_pos.y -= sinf(angle) * ITEMSPEED;

			if (distance < 30)
			{
				inventory* inven = (inventory*)TOWNWORLD->findObject(objectType::INTERFACE, "inventory");
				inven->sendMessage(tagMessage("addItem", 0.0f, 0, 0, vector<gameObject*>(), _name, _explain));

				this->setDestroy();
			}
		}
	}
	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getWidth(), _image->getHeight());
}
void dropItem::render()
{
	_image->scaleRender(getMemDC(), _rc.left, _rc.top, _image->getWidth(), _image->getHeight());
}
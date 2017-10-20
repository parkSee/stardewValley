#include "stdafx.h"
#include "npc.h"

using namespace npcDirection;

void npc::setMoveRoute(tagMessage msg)
{
	_vMoveTile.clear();

	for (int i = 0; i < msg.targetList.size(); ++i)
	{
		_vMoveTile.push_back((mapToolTile*)msg.targetList[i]);
	}

	_vMoveTile.erase(_vMoveTile.begin());
	changeState(this->getAngleDirection(_angle));
	_isMove = true;
}

void npc::move()
{
	float distance = getDistance(_pos.x, _pos.y, _vMoveTile[0]->_pos.x, _vMoveTile[0]->_pos.y);
	_angle = getAngle(_pos.x, _pos.y, _vMoveTile[0]->_pos.x, _vMoveTile[0]->_pos.y);

	if (distance < 10)
	{
		_vMoveTile.erase(_vMoveTile.begin());

		//��� ���� �ߴٴ� ��
		if (_vMoveTile.size() == 1)
		{
			if (_direction == MOVE_DOWN)changeState(STAND_DOWN);
			else if (_direction == MOVE_RIGHT)changeState(STAND_RIGHT);
			else if (_direction == MOVE_UP)changeState(STAND_UP);
			else if (_direction == MOVE_LEFT)changeState(STAND_LEFT);

			if (_cb != NULL)
			{
				_cb();
				_cb = NULL;
			}

			_isMove = false;
			return;
		}
	}
	//������ �ٲ��ٴ� ���̹Ƿ� �ִϸ��̼� �ٽ� �ɾ�����.
	if (abs(_saveAngle - _angle) >(PI/4)-0.1)
	{
		changeState(this->getAngleDirection(_angle));
	}

	_pos.x += cosf(_angle)*NPCSPEED;
	_pos.y -= sinf(_angle)*NPCSPEED;

	//������ �� ������ ���̺� �ޱ۰� ���̺� �𷺼��� �ʱ�ȭ 
	_saveAngle = _angle;
	_saveDirection = _direction;
}


npcDirection::Enum npc::getAngleDirection(float angle)
{
	if (angle >= (PI / 4) && angle < (PI / 2) + (PI/4))return MOVE_UP;
	else if (angle >= (PI / 2) + (PI / 4) && angle < PI + (PI / 4))return MOVE_LEFT;
	else if (angle >= PI + (PI / 4) && angle < (PI * 2) - (PI / 4))return MOVE_DOWN;
	else if (angle >= (PI * 2) - (PI / 4) || angle < (PI / 4))return MOVE_RIGHT;
}
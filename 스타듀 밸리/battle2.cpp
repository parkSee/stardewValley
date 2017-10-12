#include "stdafx.h"
#include "battle2.h"


battle2::battle2()
{
}


battle2::~battle2()
{
}

void battle2::keyControl(void)
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		if (_angle >= PI2) _angle -= PI2;
		_angle += 0.06f;

	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		if (_angle <= 0) _angle += PI2;
		_angle -= 0.06f;
	}

	if (KEYMANAGER->isStayKeyDown('W')) _speed += 0.02f;
	if (KEYMANAGER->isStayKeyDown('S')) _speed -= 0.02f;


}
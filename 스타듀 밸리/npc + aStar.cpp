#include "stdafx.h"
#include "npc.h"

void npc::setMoveRoute(tagMessage msg)
{
	_vMoveTile.clear();
	for (int i = 0; i < msg.targetList.size(); ++i)
	{
		_vMoveTile.push_back(msg.targetList[i]);
		_isMove = true;
	}
}

void npc::move()
{

}
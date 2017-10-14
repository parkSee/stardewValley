#pragma once
#include "worldNode.h"

class gameObject;

namespace itemType
{
	enum Enum
	{
		FOOD, SEED, TOOL, STONE, WOOD, NONE
	};
}

struct tagItem
{
	image*				img;
	itemType::Enum		type;
	tagFloat			pos;
	RECT				rc;
	int					count;

	tagItem() 
	{
		img = NULL;
		type = itemType::NONE;
		pos = tagFloat(WINSIZEX / 2, WINSIZEY / 2);
		rc = RectMakeCenter(pos.x, pos.y, 56, 56);
		count = 0;
	}

};

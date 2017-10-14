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
	string				name;
	image*				img;
	itemType::Enum		type;
	tagFloat			pos;
	RECT				rc;
	int					count;

	tagItem();
	tagItem(string Name, tagFloat position = tagFloat(), int Count = 0 , itemType::Enum typ = itemType::NONE);
	void addCount() { count++; }
};

#include "stdafx.h"
#include "item.h"

tagItem::tagItem()
{
	name = "none";
	img = NULL;
	type = itemType::NONE;
	pos = tagFloat(WINSIZEX / 2, WINSIZEY / 2);
	rc = RectMakeCenter(pos.x, pos.y, 56, 56);
	count = 0;
	size = 1.0f;
}

tagItem::tagItem(string Name, string Explain, tagFloat position, int Count, itemType::Enum typ)
{
	name = Name;
	img = IMAGEMANAGER->findImage(Name);
	type = typ;
	pos = position;
	rc = RectMakeCenter(pos.x, pos.y, 56, 56);
	count = Count;
	size = 1.0f;
	explain = Explain;
}

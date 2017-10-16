#include "stdafx.h"
#include "townScene.h"
#include "dropItem.h"

HRESULT townScene::init()
{
	seeyoungInit();
	jerichoInit();
	guenhwaInit();
	youngjaeInit();
	dongjinInit();
	soonwooInit();

	return S_OK;
}

void townScene::release()
{

}

void townScene::update()
{
	TOWNWORLD->update();
	WORLDTIME->update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		dropItem* item = new dropItem;
		item->init("물뿌리개", "무엇이든 벨 수 있다.", tagFloat(_ptMouse.x, _ptMouse.y));
		TOWNWORLD->addObject(objectType::ITEM, item);
	}
}

void townScene::render()
{
	TOWNWORLD->render();
}
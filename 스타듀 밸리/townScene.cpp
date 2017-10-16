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

	_map = new tileMap;
	_map->init();

	CAMERAMANAGER->_pos.x = WINSIZEX / 2;
	CAMERAMANAGER->_pos.y = WINSIZEY / 2;

	CAMERAMANAGER->setMapSize(3000, 3000);

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
	_map->render();
	TOWNWORLD->render();
}
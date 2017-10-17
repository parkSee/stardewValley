#include "stdafx.h"
#include "townScene.h"
#include "dropItem.h"

HRESULT townScene::init()
{
	jerichoInit();

	_map = new tileMap;
	TOWNWORLD->setMapAddress(_map);
	_map->init();

	CAMERAMANAGER->setMapSize(3000, 3000);

	CAMERAMANAGER->_pos.x = WINSIZEX / 2;
	CAMERAMANAGER->_pos.y = WINSIZEY / 2;

	seeyoungInit();
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
	_map->render();
	TOWNWORLD->render();
	
}
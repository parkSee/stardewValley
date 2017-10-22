#include "stdafx.h"
#include "townScene.h"
#include "dropItem.h"

HRESULT townScene::init()
{
	jerichoInit();

	_map = new tileMap;
	TOWNWORLD->setMapAddress(_map);
	_map->init();
	_map->mapLoadNew("mapSave.map");

	CAMERAMANAGER->setMapSize(TILESIZE * TILEX + WINSIZEX, TILESIZE * TILEY + WINSIZEY);

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
		//dropItem* item = new dropItem;
		//item->init("물뿌리개", "무엇이든 벨 수 있다.", tagFloat(_ptMouse.x, _ptMouse.y));
		//TOWNWORLD->addObject(objectType::ITEM, item);
	}

	//에이스타 실험용
	if (KEYMANAGER->isOnceKeyDown('N'))
	{
		int idx = (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE;
		int idy = (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE;
		_vRoute = TOWNWORLD->getMap()->getShortestAStar(2, 3, idx,idy, true);
	}
}

void townScene::render()
{
	_map->render();
	TOWNWORLD->render();


	//에이스타 실험용
	for (int i = 0; i < _vRoute.size(); ++i)
	{
		RECT rc = _vRoute[i]->getRect();
		EllipseMakeCenter(getMemDC(),
			-CAMERAMANAGER->getRenderRc().left + rc.left + (rc.right - rc.left) / 2,
			-CAMERAMANAGER->getRenderRc().top + rc.top + (rc.bottom - rc.top) / 2,
			10, 10);
	}
}

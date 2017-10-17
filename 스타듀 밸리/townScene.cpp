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

	
}

void townScene::render()
{
	_map->render();
	TOWNWORLD->render();
}
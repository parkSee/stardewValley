#include "stdafx.h"
#include "townScene.h"
#include "player.h"

void townScene::seeyoungInit()
{
	player* playerManager = new player;
	playerManager->init("player", tagFloat(WINSIZEX / 2+900, WINSIZEY / 2+800));
	TOWNWORLD->addObject(objectType::HUMAN, playerManager);

	CAMERAMANAGER->connectTarget(playerManager);
}
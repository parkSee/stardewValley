#include "stdafx.h"
#include "townScene.h"
#include "player.h"

void townScene::seeyoungInit()
{
	player* playerManager = new player;
	playerManager->init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));
	TOWNWORLD->addObject(objectType::HUMAN, playerManager);
}
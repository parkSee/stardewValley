#include "stdafx.h"
#include "townScene.h"

#include "Pierre.h"

void townScene::youngjaeInit()
{
	Pierre* PierreNPC = new Pierre;
	PierreNPC->init("Pierre", "Pierre", 1, 1);
	TOWNWORLD->addObject(objectType::HUMAN, PierreNPC);
}
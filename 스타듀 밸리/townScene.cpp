#include "stdafx.h"
#include "townScene.h"

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
}

void townScene::render()
{
	TOWNWORLD->render();
}
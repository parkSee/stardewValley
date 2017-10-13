#include "stdafx.h"
#include "townScene.h"

HRESULT townScene::init()
{
	seeyoungInit();
	soonwooInit();
	jerichoInit();
	guenhwaInit();
	youngjaeInit();
	dongjinInit();

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
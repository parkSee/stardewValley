#include "stdafx.h"
#include "collisionTestScene.h"


collisionTestScene::collisionTestScene()
{
}


collisionTestScene::~collisionTestScene()
{

}

HRESULT collisionTestScene::init(void)
{
	_cir.x = WINSIZEX / 2;
	_cir.y = WINSIZEY / 2;
	_cir.r = 100;

	_cirMove.x = 50;
	_cirMove.y = 50;
	_cirMove.r = 50;


	return S_OK;
}

void collisionTestScene::release(void)
{

}

void collisionTestScene::update(void) 
{
	_cirMove.setCenterPos(_ptMouse.x, _ptMouse.y);

	if (isCollisionReaction(_cir, _cirMove))
	{

	}
}

void collisionTestScene::render(void) 
{
	_cir.render(getMemDC());
	_cirMove.render(getMemDC());
}

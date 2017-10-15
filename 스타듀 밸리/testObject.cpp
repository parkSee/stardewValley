#include "stdafx.h"
#include "testObject.h"

testObject::testObject() {}
testObject::~testObject() {}


HRESULT testObject::init(string objName, string imageKey, tagFloat pos, pivot::Enum pivot)
{
	gameObject::init(objName, imageKey, pos, pivot);

	_object = OBJECT::NONE;

	return S_OK;
}
void testObject::release()
{
	gameObject::release();
}
void testObject::update()
{
	gameObject::update();
}
void testObject::render()
{
	int CAMX = CAMERAMANAGER->getRenderRc().left;
	int CAMY = CAMERAMANAGER->getRenderRc().top;
	switch (_object)
	{
	case OBJECT::NONE:
		//_image->frameRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y, _frameX, _frameY);
		_image->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y, _frameX, _frameY, _image->getFrameWidth() * SCALE, _image->getFrameHeight() * SCALE);
		break;
	case OBJECT::TREE1: case OBJECT::TREE2: case OBJECT::TREE3:
		_image->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y, _frameX, _frameY, _image->getFrameWidth() * SCALE, _image->getFrameHeight() * SCALE);
		_image->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y - TILESIZE, _frameX, _frameY - 1, _image->getFrameWidth() * SCALE, _image->getFrameHeight() * SCALE);
		for (int j = -5; j <= -2; ++j)
		{
			for (int i = -1; i <= 1; ++i)
			{
				_image->frameScaleRender(getMemDC(), -CAMX + _pos.x + i * TILESIZE, -CAMY + _pos.y + j * TILESIZE, _frameX + i, _frameY + j, _image->getFrameWidth() * SCALE, _image->getFrameHeight() * SCALE);
			}
		}
		break;
	case OBJECT::BIG_TREE:
		break;
	case OBJECT::BIG_BIG_TREE:
		break;
	case OBJECT::STONE:
		break;
	}
}

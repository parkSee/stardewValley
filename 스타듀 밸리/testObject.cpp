#include "stdafx.h"
#include "testObject.h"


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
	image* img = NULL;
	int CAMX = CAMERAMANAGER->getRenderRc().left;
	int CAMY = CAMERAMANAGER->getRenderRc().top;
	switch (_object)
	{
	case OBJECT::NONE:
		//_image->frameRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y, _frameX, _frameY);
		_image->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y, _frameX, _frameY, _image->getFrameWidth() * SCALE, _image->getFrameHeight() * SCALE);
		break;
	case OBJECT::TREE1:
	{
		img = IMAGEMANAGER->findImage("outdoorsSpring");
		int tempx = 1; int tempy = 5;
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y,
			tempx, tempy, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y - TILESIZE,
			tempx, tempy - 1, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		for (int j = -5; j <= -2; ++j)
		{
			for (int i = -1; i <= 1; ++i)
			{
				img->frameScaleRender(getMemDC(), -CAMX + _pos.x + i * TILESIZE,
					-CAMY + _pos.y + j * TILESIZE,
					tempx + i, tempy + j,
					img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
			}
		}
	}
	break;
	case OBJECT::TREE2:
	{
		img = IMAGEMANAGER->findImage("outdoorsSpring");
		int tempx = 4; int tempy = 5;
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y,
			tempx, tempy, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y - TILESIZE,
			tempx, tempy - 1, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		for (int j = -5; j <= -2; ++j)
		{
			for (int i = -1; i <= 1; ++i)
			{
				img->frameScaleRender(getMemDC(), -CAMX + _pos.x + i * TILESIZE,
					-CAMY + _pos.y + j * TILESIZE,
					tempx + i, tempy + j,
					img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
			}
		}
	}
	break;
	case OBJECT::TREE3:
	{
		img = IMAGEMANAGER->findImage("outdoorsSpring");
		int tempx = 11; int tempy = 5;
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y,
			tempx, tempy, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y - TILESIZE,
			tempx, tempy - 1, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		for (int j = -5; j <= -2; ++j)
		{
			for (int i = -1; i <= 1; ++i)
			{
				img->frameScaleRender(getMemDC(), -CAMX + _pos.x + i * TILESIZE,
					-CAMY + _pos.y + j * TILESIZE,
					tempx + i, tempy + j,
					img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
			}
		}
	}
	break;
	case OBJECT::BIG_TREE:
		break;
	case OBJECT::BIG_BIG_TREE:
		break;
	case OBJECT::STONE:
		break;
	case OBJECT::FARMLAND:
		img = IMAGEMANAGER->findImage("outdoorsSpring");
		//6,22
		img->frameScaleRender(getMemDC(), -CAMX + _pos.x, -CAMY + _pos.y,
			6, 22, img->getFrameWidth() * SCALE, img->getFrameHeight() * SCALE);
		break;
	}
}

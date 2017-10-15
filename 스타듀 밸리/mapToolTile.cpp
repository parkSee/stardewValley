#include "stdafx.h"
#include "mapToolTile.h"

HRESULT mapToolTile::init(int idX, int idY)
{
	gameObject::init("", "", tagFloat(idX * TILESIZE, idY * TILESIZE), pivot::LEFT_TOP);

	_indexX = idX;
	_indexY = idY;

	//_image = IMAGEMANAGER->findImage("tiles");
	_terrain = TERRAIN::NONE;
	_terrainFrameX = 3;
	_terrainFrameY = 6;

	_rc = RectMake(_pos.x, _pos.y, TILESIZE, TILESIZE);

	_obj = NULL;

	return S_OK;
}
void mapToolTile::release()
{
	gameObject::release();

}

void mapToolTile::update()
{
	gameObject::update();

	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

}

void mapToolTile::render()
{
	//RECT renderRC = CAMERAMANAGER->getRenderRc();
	//_image->frameRender(getMemDC(), _rc.left - renderRC.left, _rc.top - renderRC.top, _terrainFrameX, _terrainFrameY);

	//_image->frameRender(getMemDC(), _rc.left, _rc.top, _terrainFrameX, _terrainFrameY);

	//IMAGEMANAGER->findImage("tileSprite")->frameRender(getMemDC(), _tag.rc.left - renderRC.left, _tag.rc.top - renderRC.top, _tag.terrainFrameX, _tag.terrainFrameY);

	switch (_terrain)
	{
	case TERRAIN::NONE:
		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
			-CAMERAMANAGER->getRenderRc().left + _rc.left,
			-CAMERAMANAGER->getRenderRc().top + _rc.top,
			_terrainFrameX, _terrainFrameY, TILESIZE, TILESIZE);
		break;
	case TERRAIN::DIRT:
		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
			-CAMERAMANAGER->getRenderRc().left + _rc.left,
			-CAMERAMANAGER->getRenderRc().top + _rc.top,
			3, 6, TILESIZE, TILESIZE);
		break;
	case TERRAIN::GRASS:
		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
			-CAMERAMANAGER->getRenderRc().left + _rc.left,
			-CAMERAMANAGER->getRenderRc().top + _rc.top,
			0, 7, TILESIZE, TILESIZE);
		break;
	case TERRAIN::WATER:
		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
			-CAMERAMANAGER->getRenderRc().left + _rc.left,
			-CAMERAMANAGER->getRenderRc().top + _rc.top,
			8, 13, TILESIZE, TILESIZE);
		break;
	}
}

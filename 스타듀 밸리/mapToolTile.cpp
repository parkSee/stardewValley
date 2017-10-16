#include "stdafx.h"
#include "mapToolTile.h"


HRESULT mapToolTile::init(int idX, int idY)
{
	gameObject::init("mapToolTile", "", tagFloat(idX * TILESIZE, idY * TILESIZE), pivot::LEFT_TOP);

	_terrain = TERRAIN::NONE;
	_indexX = idX;
	_indexY = idY;
	_rc = RectMake(idX * TILESIZE, idY * TILESIZE, TILESIZE, TILESIZE);

	_pObj = NULL;

	//_image = IMAGEMANAGER->findImage("tiles");
	_terrainFrameX = 3;
	_terrainFrameY = 6;


	return S_OK;
}
void mapToolTile::release()
{
	gameObject::release();
}

void mapToolTile::update()
{
	gameObject::update();

	_rc = RectMakeCenter(_indexX * TILESIZE, _indexY * TILESIZE, TILESIZE, TILESIZE);
}

void mapToolTile::render()
{
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

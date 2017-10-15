#include "stdafx.h"
#include "mapToolTile.h"

HRESULT mapToolTile::init(int idX, int idY)
{
	gameObject::init("", "", tagFloat(idX * TILESIZE, idY * TILESIZE), pivot::LEFT_TOP);

	_tag.indexX = idX;
	_tag.indexY = idY;

	//_image = IMAGEMANAGER->findImage("tiles");
	_tag.terrain = TERRAIN::TR_GROUND;
	_tag.terrainFrameX = 3;
	_tag.terrainFrameY = 6;

	_tag.rc = RectMake(_pos.x, _pos.y, TILESIZE, TILESIZE);

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

	_tag.rc = RectMakeCenter(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

}

void mapToolTile::render()
{
	RECT renderRC = CAMERAMANAGER->getRenderRc();
	//_image->frameRender(getMemDC(), _rc.left - renderRC.left, _rc.top - renderRC.top, _terrainFrameX, _terrainFrameY);

	//_image->frameRender(getMemDC(), _rc.left, _rc.top, _terrainFrameX, _terrainFrameY);

	IMAGEMANAGER->findImage("tileSprite")->frameRender(getMemDC(), _tag.rc.left - renderRC.left, _tag.rc.top - renderRC.top, _tag.terrainFrameX, _tag.terrainFrameY);
}

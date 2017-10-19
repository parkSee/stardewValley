#include "stdafx.h"
#include "mapToolTile.h"


HRESULT mapToolTile::init(int idX, int idY, TERRAIN::Enum terrain)
{
	//초기화
	_indexX = idX;
	_indexY = idY;
	_terrain = terrain;
	_rc = RectMake(idX * TILESIZE, idY * TILESIZE, TILESIZE, TILESIZE);
	//에이스타 상속하면서 _pos 사용
	_pos.x = idX * TILESIZE + TILESIZE / 2;
	_pos.y = idY * TILESIZE + TILESIZE / 2;

	_pObj = NULL;

	_image = NULL;
	_imageKey = "";
	_frameX = 0;
	_frameY = 0;
	_isMovable = true;


	//지형 종류에 따라서 이미지, 프레임, 이동가능여부 설정
	switch (_terrain)
	{
	case TERRAIN::NONE:
		//비어있으면 타일인지 모르니까 나뭇잎 하나
		changeImage("outdoorsSpring");
		_frameX = 10; _frameY = 4;
		break;
	case TERRAIN::SOMETHING:
		//비어있으면 타일인지 모르니까 나뭇잎 두개
		changeImage("outdoorsSpring");
		_frameX = 9; _frameY = 4;
		break;
	case TERRAIN::DIRT:
		changeImage("outdoorsSpring");
		_frameX = 3; _frameY = 6;
		_isMovable = true;
		break;
	case TERRAIN::GRASS:
		changeImage("outdoorsSpring");
		_frameX = 0; _frameY = 7;
		_isMovable = true;
		break;
	case TERRAIN::WATER:
		changeImage("outdoorsSpring");
		_frameX = 8; _frameY = 13;
		_isMovable = false;
		break;
	case TERRAIN::END:
		break;
	}

	return S_OK;
}
void mapToolTile::release()
{

}
void mapToolTile::update()
{
	//타일은 업데이트 돌리지 말자
}
void mapToolTile::render()
{
	_image->frameScaleRender(getMemDC(),
		-CAMERAMANAGER->getRenderRc().left + _rc.left,
		-CAMERAMANAGER->getRenderRc().top + _rc.top,
		_frameX, _frameY, TILESIZE, TILESIZE);
}





//#include "stdafx.h"
//#include "mapToolTile.h"
//
//
//HRESULT mapToolTile::init(int idX, int idY)
//{
//	gameObject::init("mapToolTile", "", tagFloat(idX * TILESIZE, idY * TILESIZE), pivot::LEFT_TOP);
//
//	_terrain = TERRAIN::NONE;
//	_indexX = idX;
//	_indexY = idY;
//	_rc = RectMake(idX * TILESIZE, idY * TILESIZE, TILESIZE, TILESIZE);
//
//	_pObj = NULL;
//
//	//_image = IMAGEMANAGER->findImage("tiles");
//	_terrainFrameX = 3;
//	_terrainFrameY = 6;
//
//
//	return S_OK;
//}
//void mapToolTile::release()
//{
//	gameObject::release();
//}
//
//void mapToolTile::update()
//{
//	gameObject::update();
//
//	_rc = RectMakeCenter(_indexX * TILESIZE, _indexY * TILESIZE, TILESIZE, TILESIZE);
//}
//
//void mapToolTile::render()
//{
//	switch (_terrain)
//	{
//	case TERRAIN::NONE:
//		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
//			-CAMERAMANAGER->getRenderRc().left + _rc.left,
//			-CAMERAMANAGER->getRenderRc().top + _rc.top,
//			_terrainFrameX, _terrainFrameY, TILESIZE, TILESIZE);
//		break;
//	case TERRAIN::DIRT:
//		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
//			-CAMERAMANAGER->getRenderRc().left + _rc.left,
//			-CAMERAMANAGER->getRenderRc().top + _rc.top,
//			3, 6, TILESIZE, TILESIZE);
//		break;
//	case TERRAIN::GRASS:
//		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
//			-CAMERAMANAGER->getRenderRc().left + _rc.left,
//			-CAMERAMANAGER->getRenderRc().top + _rc.top,
//			0, 7, TILESIZE, TILESIZE);
//		break;
//	case TERRAIN::WATER:
//		IMAGEMANAGER->findImage("tileSprite")->frameScaleRender(getMemDC(),
//			-CAMERAMANAGER->getRenderRc().left + _rc.left,
//			-CAMERAMANAGER->getRenderRc().top + _rc.top,
//			8, 13, TILESIZE, TILESIZE);
//		break;
//	}
//}

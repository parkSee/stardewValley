#include "stdafx.h"
#include "mapToolTile.h"


HRESULT mapToolTile::init(int idX, int idY, TERRAIN::Enum terrain)
{
	//�ʱ�ȭ
	_indexX = idX;
	_indexY = idY;
	_terrain = terrain;
	_rc = RectMake(idX * TILESIZE, idY * TILESIZE, TILESIZE, TILESIZE);
	//���̽�Ÿ ����ϸ鼭 _pos ���
	_pos.x = idX * TILESIZE + TILESIZE / 2;
	_pos.y = idY * TILESIZE + TILESIZE / 2;

	_pObj = NULL;

	_image = NULL;
	_imageKey = "";
	_frameX = 0;
	_frameY = 0;
	_isMovable = true;


	//���� ������ ���� �̹���, ������, �̵����ɿ��� ����
	switch (_terrain)
	{
	case TERRAIN::NONE:
		//��������� Ÿ������ �𸣴ϱ� ������ �ϳ�
		changeImage("outdoorsSpring");
		_frameX = 10; _frameY = 4;
		break;
	case TERRAIN::SOMETHING:
		//��������� Ÿ������ �𸣴ϱ� ������ �ΰ�
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
	//Ÿ���� ������Ʈ ������ ����
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

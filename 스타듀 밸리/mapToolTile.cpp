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

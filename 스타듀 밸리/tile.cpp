#include "stdafx.h"
//#include "tile.h"
//
//HRESULT tile::init(float x , float y,int idX , int idY)
//{
//	gameObject::init("","",tagFloat(x,y),pivot::CENTER);
//
//	_indexX = idX;
//	_indexY = idY;
//
//
//	return S_OK;
//}
//void tile::release()
//{
//	gameObject::release();
//
//}
//
//void tile::update()
//{
//	gameObject::update();
//
//	_rc = RectMakeCenter(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());
//
//}
//
//void tile::render()
//{
//	RECT renderRC = CAMERAMANAGER->getRenderRc();
//	_image->frameRender(getMemDC(), _rc.left - renderRC.left, _rc.top - renderRC.top, _terrainFrameX, _terrainFrameY);
//	
//}

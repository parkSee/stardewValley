#include "stdafx.h"
#include "mapToolScene.h"

mapToolScene::mapToolScene() {}
mapToolScene::~mapToolScene() {}


HRESULT mapToolScene::init()
{
	////타일 크기 32
	IMAGEMANAGER->addFrameImage("tiles", "Tile Sample 01(352,352,11,11).bmp", 352, 352, 11, 11, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("tileSprite", "(x2)Outdoors Spring(800,2528,25,79).bmp", 800, 2528, 25, 79, true, RGB(255, 0, 255));

	//타일 크기 16
	IMAGEMANAGER->addFrameImage("crops", "Crops(256,672,16,42).bmp", 256, 672, 16, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("farmBuildings", "Farm Buildings(913,412).bmp", 913, 412, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("farmHouse", "Farmhouse(192,320,12,20).bmp", 192, 320, 12, 20, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("outdoorsSpring", "Outdoors Spring(400,1264,25,79) - 그림자 제거.bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tileSprite", "Outdoors Spring(400,1264,25,79).bmp", 400, 1264, 25, 79, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("trees", "Trees(176,645).bmp", 176, 645, true, RGB(255, 0, 255));

	_map = new tileMap;
	_map->init();

	CAMERAMANAGER->_pos.x = WINSIZEX / 2;
	CAMERAMANAGER->_pos.y = WINSIZEY / 2;

	CAMERAMANAGER->setMapSize(3000, 3000);
	
	_mode = MODE_MAP;
	_selectIdX = _selectIdY = 0;
	_mapCam.x = _spriteCam.x = WINSIZEX / 2;
	_mapCam.y = _spriteCam.y = WINSIZEY / 2;

	return S_OK;
}
void mapToolScene::release()
{

}
void mapToolScene::update()
{
	//탭 누르면 맵 - 스프라이트 전환
	if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	{
		switch (_mode)
		{
		case mapToolScene::MODE_MAP:
			_mapCam = CAMERAMANAGER->_pos;

			_mode = MODE_SPRITE;
			CAMERAMANAGER->_pos = _spriteCam;
			break;
		case mapToolScene::MODE_SPRITE:
			_spriteCam = CAMERAMANAGER->_pos;

			_mode = MODE_MAP;
			CAMERAMANAGER->_pos = _mapCam;
			break;
		}
	}

	switch (_mode)
	{
	case mapToolScene::MODE_MAP:
		_map->update();

		TOWNWORLD->update();
		break;
	case mapToolScene::MODE_SPRITE:
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selecting();
		}
		break;
	}

	int spd = 20;
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		CAMERAMANAGER->_pos.x -= spd;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		CAMERAMANAGER->_pos.x += spd;
	}
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		CAMERAMANAGER->_pos.y -= spd;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		CAMERAMANAGER->_pos.y += spd;
	}

	CAMERAMANAGER->update();
}
void mapToolScene::render()
{
	switch (_mode)
	{
	case mapToolScene::MODE_MAP:
		_map->render();

		//마우스 대고있는 칸 표시
		if (0 <= CAMERAMANAGER->getRenderRc().left + _ptMouse.x && CAMERAMANAGER->getRenderRc().left + _ptMouse.x < TILEX * TILESIZE &&
			0 <= CAMERAMANAGER->getRenderRc().top + _ptMouse.y && CAMERAMANAGER->getRenderRc().top + _ptMouse.y < TILEY * TILESIZE)
		{
			HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
			RectangleMake(getMemDC(), -CAMERAMANAGER->getRenderRc().left + (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE * TILESIZE,
				-CAMERAMANAGER->getRenderRc().top + (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE * TILESIZE, TILESIZE, TILESIZE);
			DeleteObject(SelectObject(getMemDC(), oldBrush));
		}

		TOWNWORLD->render();
		break;
	case mapToolScene::MODE_SPRITE:
		IMAGEMANAGER->findImage("tileSprite")->render(getMemDC(), -CAMERAMANAGER->getRenderRc().left, -CAMERAMANAGER->getRenderRc().top);

		//마우스 대고있는 칸 표시
		image* img = IMAGEMANAGER->findImage("tileSprite");

		if (0 <= CAMERAMANAGER->getRenderRc().left + _ptMouse.x && CAMERAMANAGER->getRenderRc().left + _ptMouse.x <= img->getWidth() &&
			0 <= CAMERAMANAGER->getRenderRc().top + _ptMouse.y && CAMERAMANAGER->getRenderRc().top + _ptMouse.y <= img->getHeight())
		{
			HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
			RectangleMake(getMemDC(), -CAMERAMANAGER->getRenderRc().left + (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE * TILESIZE,
				-CAMERAMANAGER->getRenderRc().top + (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE * TILESIZE, TILESIZE, TILESIZE);
			DeleteObject(SelectObject(getMemDC(), oldBrush));
		}

		//현재 선택된 타일 표시
		//HBRUSH oldBrush = (HBRUSH)SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
		EllipseMakeCenter(getMemDC(), -CAMERAMANAGER->getRenderRc().left + _selectIdX * TILESIZE + TILESIZE / 2,
			-CAMERAMANAGER->getRenderRc().top + _selectIdY * TILESIZE + TILESIZE / 2, 10, 10);
		//DeleteObject(SelectObject(getMemDC(), oldBrush));


		break;
	}
}

void mapToolScene::selecting()
{
	int x = (CAMERAMANAGER->getRenderRc().left + _ptMouse.x) / TILESIZE;
	int y = (CAMERAMANAGER->getRenderRc().top + _ptMouse.y) / TILESIZE;

	//case tileNumber():
	switch (spriteNumber(x, y))
	{
		//나무1
	case spriteNumber(0,0): case spriteNumber(1,0): case spriteNumber(2,0):
	case spriteNumber(0,1): case spriteNumber(1,1): case spriteNumber(2,1):
	case spriteNumber(0,2): case spriteNumber(1,2): case spriteNumber(2,2):
	case spriteNumber(0,3): case spriteNumber(1,3): case spriteNumber(2,3):
	case spriteNumber(1,4): case spriteNumber(1,5):
		_selectIdX = 1; _selectIdY = 5;
		break;
		//나무2
	case spriteNumber(3, 0): case spriteNumber(4, 0): case spriteNumber(5, 0):
	case spriteNumber(3, 1): case spriteNumber(4, 1): case spriteNumber(5, 1):
	case spriteNumber(3, 2): case spriteNumber(4, 2): case spriteNumber(5, 2):
	case spriteNumber(3, 3): case spriteNumber(4, 3): case spriteNumber(5, 3):
	case spriteNumber(4, 4): case spriteNumber(4, 5):
		_selectIdX = 4; _selectIdY = 5;
		break;
		//나무3
	case spriteNumber(6,0): case spriteNumber(7,0): case spriteNumber(8,0): case spriteNumber(9,0):
	case spriteNumber(6,1): case spriteNumber(7,1): case spriteNumber(8,1): case spriteNumber(9,1):
	case spriteNumber(6,2): case spriteNumber(7,2): case spriteNumber(8,2): case spriteNumber(9,2):
	case spriteNumber(6,3): case spriteNumber(7,3): case spriteNumber(8,3): case spriteNumber(9,3):
	case spriteNumber(7,4): case spriteNumber(8,4):
	case spriteNumber(7,5): case spriteNumber(8,5):
	case spriteNumber(7,6): case spriteNumber(8,6):
		_selectIdX = 7; _selectIdY = 6;
		break;
		//나무4
	case spriteNumber(10, 0): case spriteNumber(11, 0): case spriteNumber(12, 0):
	case spriteNumber(10, 1): case spriteNumber(11, 1): case spriteNumber(12, 1):
	case spriteNumber(10, 2): case spriteNumber(11, 2): case spriteNumber(12, 2):
	case spriteNumber(10, 3): case spriteNumber(11, 3): case spriteNumber(12, 3):
	case spriteNumber(11, 4): case spriteNumber(11, 5):
		_selectIdX = 11; _selectIdY = 5;
		break;
		//큰덤불
	case spriteNumber(13, 0): case spriteNumber(14, 0): case spriteNumber(15, 0):
	case spriteNumber(13, 1): case spriteNumber(14, 1): case spriteNumber(15, 1):
	case spriteNumber(13, 2): case spriteNumber(14, 2): case spriteNumber(15, 2):
		_selectIdX = 14; _selectIdY = 2;
		break;
		//울타리 가로 왼쪽 끝
	case spriteNumber(8,14): case spriteNumber(8,15):
		_selectIdX = 8; _selectIdY = 15;
		break;
		//울타리 가로 중간
	case spriteNumber(9,14): case spriteNumber(9,15):
		_selectIdX = 9; _selectIdY = 15;
		break;
		//울타리 가로 오른쪽 끝
	case spriteNumber(10,14): case spriteNumber(10,15):
		_selectIdX = 10; _selectIdY = 15;
		break;
	default:
		_selectIdX = x; _selectIdY = y;
		break;
	}

	_map->setSelectIdX(_selectIdX); _map->setSelectIdY(_selectIdY);
}

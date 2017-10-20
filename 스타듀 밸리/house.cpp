#include "stdafx.h"
#include "house.h"

HRESULT house::init(string name, string imageKey, tagFloat pos)
{
	motherObject::init(name, imageKey, pos);

	_rc.left = _pos.x - (89*SCALE);
	_rc.right = _pos.x + (_image->getWidth() - (89 * SCALE));
	_rc.top = _pos.y - (67*SCALE);
	_rc.bottom = _pos.y + (_image->getHeight() - (67 * SCALE));

	_alpha = 255;

	_player = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");

	return S_OK;
}

void house::release()
{
	motherObject::release();
}

void house::update() 
{
	motherObject::update();

	//if ((_player->getIndexX() == 12 && _player->getIndexY() == 11) ||
	//	(_player->getIndexX() == 13 && _player->getIndexY() == 11) ||
	//	(_player->getIndexX() == 14 && _player->getIndexY() == 11) ||
	//	(_player->getIndexX() == 15 && _player->getIndexY() == 11) ||
	//	(_player->getIndexX() == 16 && _player->getIndexY() == 11) ||
	//	(_player->getIndexX() == 13 && _player->getIndexY() == 10) ||
	//	(_player->getIndexX() == 14 && _player->getIndexY() == 10) ||
	//	(_player->getIndexX() == 15 && _player->getIndexY() == 10) ||
	//	(_player->getIndexX() == 14 && _player->getIndexY() == 9))
	//{
	//	_alpha = 100;
	//}
	//else _alpha = 255;
}

void house::render() 
{
	RECT rc = CAMERAMANAGER->getRenderRc();
	_image->alphaRender(getMemDC(), _rc.left - rc.left, _rc.top - rc.top, _alpha); 
	//_image->getWidth()*SCALE, _image->getHeight()*SCALE);

	//int indexX = (_ptMouse.x + rc.left) / TILESIZE;
	//int indexY = (_ptMouse.y +rc.top) / TILESIZE;
	//
	//char str[100];
	//sprintf(str, "%d,%d", indexX, indexY);
	//TextOut(getMemDC(), 10, 500, str, strlen(str));

}

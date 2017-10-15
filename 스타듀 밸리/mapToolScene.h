#pragma once
#include "gameNode.h"
#include "mapToolNode.h"
#include "tileMap.h"


class mapToolScene : public gameNode
{
private:
	enum MODE
	{
		MODE_MAP,
		MODE_SPRITE
	};
	//------------------------

	tileMap* _map;

	SPRITE::Enum _sprite;
	MODE _mode;
	int _selectIdX, _selectIdY;
	tagInt _mapCam, _spriteCam;

public:
	mapToolScene();
	~mapToolScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void selecting();
};

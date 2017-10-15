#pragma once
#include "gameNode.h"
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

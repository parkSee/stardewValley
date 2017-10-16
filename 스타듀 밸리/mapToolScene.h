#pragma once
#include "gameNode.h"
#include "mapToolNode.h"
#include "tileMap.h"
#include "testObject.h"


class mapToolScene : public gameNode
{
private:
	enum MODE
	{
		MODE_MAP,
		MODE_SPRITE
	};
	enum KIND
	{
		KIND_NONE,
		KIND_TERRAIN,
		KIND_OBJECT
	};
	struct tagTileSampleRect
	{
		RECT rc;
		KIND kind;
		TERRAIN::Enum terrain;
		OBJECT::Enum object;
		string str;

		tagTileSampleRect() :
			rc({ 0,0,0,0 }), kind(KIND_NONE),
			terrain(TERRAIN::NONE), object(OBJECT::NONE), str("") {}

		void init()
		{
			rc = { 0,0,0,0 };
			kind = KIND_NONE;
			terrain = TERRAIN::NONE;
			object = OBJECT::NONE;
			str = "";
		}
	};
	//------------------------

	tileMap* _map;

	vector<RECT> _vSpriteRect;
	vector<tagTileSampleRect> _vtileSampleSelect;
	SPRITE::Enum _sprite;
	MODE _mode;
	int _selectIdX, _selectIdY;
	tagInt _mapCam, _spriteCam;

	//»ùÇÃÅ¸ÀÏ¿ë
	KIND _selectKind;
	TERRAIN::Enum _selectTerrain;
	OBJECT::Enum _selectObject;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void selecting();

	void setTileSampleSelect();
	void tileSampleToMap();

	mapToolScene() {}
	~mapToolScene() {}
};

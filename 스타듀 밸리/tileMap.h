#pragma once
#include "gameNode.h"
#include "mapToolTile.h"


class tileMap : public gameNode
{
private:
	enum KIND
	{
		KIND_TERRAIN,
		KIND_OBJECT,
		KIND_OBJECT_ERASER
	};

	struct tagObjectSave
	{
		objectType::Enum objectType;
		OBJECT::Enum object;
		int idX, idY;
		int frameX, frameY;
		tagFloat pos;
		pivot::Enum pivot;

		string name;
		string imageKey;
	};
	//------------------------------------------------

	mapToolTile* _pTile[TILEX][TILEY];

	//¸ÊÅø¿ë
	int _selectIdX, _selectIdY;
	KIND _kind;
	RECT _rc1, _rc2, _rc3;

public:
	tileMap();
	~tileMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void save();
	void load();

	inline mapToolTile* getTile(int idX, int idY) { return _pTile[idX][idY]; }
	//inline TERRAIN getTerrain(int idX, int idY) { return _pTile[idX][idY]->getTerrain(); }
	inline void setSelectIdX(int x) { _selectIdX = x; }
	inline void setSelectIdY(int y) { _selectIdY = y; }
};
